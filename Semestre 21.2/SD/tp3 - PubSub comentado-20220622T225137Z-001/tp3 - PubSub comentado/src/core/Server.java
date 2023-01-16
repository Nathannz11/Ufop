package core;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Set;

import utils.Tuple;

//this server represents the producer in a producer/consumer strategy
//it receives a client socket and inserts it into a resource
public class Server {
	protected PubSubConsumer<Socket> consumer;
	protected GenericResource<Socket> resource;

	protected SyncConsumer<Tuple<Socket, Message>> syncConsumer;
	protected GenericResource<Tuple<Socket, Message>> syncResource;

	protected CommandConsumer<Tuple<Socket, Message>> commandConsumer;
	protected GenericResource<Tuple<Socket, Message>> commandResource;

	protected int port;
	protected ServerSocket serverSocket;
	protected Boolean isPrimary;
	protected Address address;

	public Server(int port, boolean isPrimary, Address address) {
		this.port = port;
		this.isPrimary = isPrimary;
		this.address = address;

		resource = new GenericResource<Socket>();
		syncResource = new GenericResource<Tuple<Socket, Message>>();
		commandResource = new GenericResource<Tuple<Socket, Message>>();

	}

	public Server(int port, boolean isPrimary) {
		this(port, isPrimary, new Address(null, 0));
	}

	public Server(int port) {
		this(port, true, new Address(null, 0));
	}

	public void begin() {
		try {

			// O execute do pubsub consumer é o método executado quando o servidor gera um
			// socket. Basicamente, lê uma mensagem, executa o comando e envia a resposta
			// obtida por ele no backup (se mensagem do tipo sync) e no primário (no primário sempre)

			// just one consumer to guarantee a single
			// log write mechanism
			consumer = new PubSubConsumer<Socket>(resource, commandResource, syncResource);

			// Relacionado aos comandos enviados pelo consumidor aos brokers
			// Aqui, se inicia os logs dos comandos (id 1) e seta os valores relacionados ao
			// seu broker primário e backup

			// Em seu doSomething, se recebe mensagem de turn, faz o backup virar primário
			// Quando um cliente se subscreve pelo backup (tendo virado primário),
			// o backup repassa a subscrição do cliente p/ o broker primário.
			// Caso o broker já seja o primário, apenas executa o comando

			commandConsumer = new CommandConsumer<>(commandResource, isPrimary, address,
					consumer.getMessages(), consumer.getSubscribers());

			// Broker backup pega as mensagens e adiciona nos logs dele próprio
			// Seu doSomething, faz o comando ser executado (sendo notifycommand, acquirecommand, etc)
			// Verificar acquireCommand
			if (!isPrimary) {
				syncConsumer = new SyncConsumer<Tuple<Socket, Message>>(syncResource, address,
						consumer.getMessages(), consumer.getSubscribers());

				syncConsumer.start();
			}

			commandConsumer.start();

			consumer.start();

			openServerSocket();

			// start listening
			listen();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	protected void listen() {

		while (!resource.isStopped()) {

			try {
				Socket clientSocket = this.serverSocket.accept();

				resource.putRegister(clientSocket);

			} catch (IOException e) {
				if (resource.isStopped()) {
					return;
				}
				throw new RuntimeException(
						"Error accepting connection", e);
			}

		}
		System.out.println("[SERVER] Stopped: " + port);

	}

	private void openServerSocket() {
		try {
			this.serverSocket = new ServerSocket(this.port);
			System.out.println("[SERVER] Listening on port: " + this.port);
		} catch (IOException e) {
			throw new RuntimeException("Cannot open port " + port, e);
		}
	}

	public void stop() {
		resource.stopServer();
		syncResource.stopServer();
		commandResource.stopServer();

		listen();

		consumer.stopConsumer();
		commandConsumer.stopConsumer();

		if (!isPrimary)
			syncConsumer.stopConsumer();

		resource.setFinished();
		syncResource.setFinished();
		commandResource.setFinished();
		// consumer.interrupt();
		try {
			serverSocket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public Set<Message> getLogMessages() {
		try {
			return ((PubSubConsumer<Socket>) consumer).getMessages();
		} catch (Exception e) {
			return null;
		}
	}

}
