package appl;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import core.Address;
import core.Message;
import core.MessageImpl;
import core.Server;
import core.client.Client;
import utils.Tuple;

public class PubSubClient {
	
	private Server observer;
	private ThreadWrapper clientThread;

	private Address clientAddress;

	private Map<String, Tuple<Address, Address>> brokerAddresses;
	
	public PubSubClient(){
		//this constructor must be called only when the method
		//startConsole is used
		//otherwise the other constructor must be called
		this.brokerAddresses = new HashMap<String, Tuple<Address, Address>>(); // garante que posso ter multiplos brokers
	}
	
	public PubSubClient(String clientAddress, int clientPort){
		this();

		this.clientAddress = new Address(clientAddress, clientPort);

		observer = new Server(clientPort);
		clientThread = new ThreadWrapper(observer);
		clientThread.start();
	}
	
	public void subscribe(String brokerName, String brokerAddress, int brokerPort) throws Exception{
		
		// Impede que se subscreva no broker 2 vezes (??) criar 2 vezes o msm broker (????)
		if (this.brokerAddresses.containsKey(brokerName)){
			throw new IllegalStateException("A broker called " + brokerName + " already exists.");
		}

		// Envia mensagem pro broker informando a subscrição
		Message msgBroker = new MessageImpl();
		msgBroker.setBrokerId(brokerPort);
		msgBroker.setType("sub");
		msgBroker.setContent(this.clientAddress.toString());

		try {
			Client subscriber = new Client(brokerAddress, brokerPort);
			Message response = subscriber.sendReceive(msgBroker);

			// Se aceitar a subscrição, então insere o name do broker na lista de brokers em que o pubsub tá subscrito		
			if (response.getType().equals("sub_ack")){
				// O secundary é o broker que está aceitando a subscrição, seja primário ou backup
				String secundary = response.getContent();
				this.brokerAddresses.put(brokerName, new Tuple<>(new Address(brokerAddress, brokerPort), 
										secundary.isEmpty() ? null : new Address(secundary.split(":")[0], Integer.parseInt(secundary.split(":")[1]))));
			}
		} catch (IOException e) {
			throw new IllegalStateException("Any broker exists at " + brokerAddress + ":" + brokerPort);
		}
	}
	
	
	public boolean publish(String message, String brokerName) throws IOException{
		
		if (! this.brokerAddresses.containsKey(brokerName)){
			throw new IllegalStateException("Any broker called " + brokerName + "  exists.");
		}

		Address primary;

		while((primary = this.brokerAddresses.get(brokerName).key()) != null){
		
			Message msgPub = new MessageImpl();
			msgPub.setBrokerId(primary.getPort());
			msgPub.setType("pub");
			msgPub.setContent(message);
			
			//  aq ele recebe o feedback do broker
			try {
				Client publisher = new Client(primary.getIp(), primary.getPort());

				publisher.sendReceive(msgPub);

				return true;

			} catch (IOException e) {

				System.out.println("[CLIENT] Emitindo 'TURN' para o outro broker e tentando novamente.");
				turn(brokerName);
			}
		}

		throw new IllegalStateException("Any broker available"); // todo
		
	}

	public void useResource(String credentials) throws InterruptedException {
		System.out.println("[CLIENT] Estou acessando o recurso : " + credentials);
		Thread.sleep(4000); // wait -> ??
		System.out.println("[CLIENT] Terminei de usar o recurso : " + credentials);
	}

	// Percorre os logs, verificando, p cada mensagem, se está pedindo o acquire do recurso específico
	// e se a requisição ainda tá ativa ( não tá no tipo de acquire_finished )
	// Se for a requisição, retorna o id da requisição (lá em cima, se o id retornado for igual ao id da requisição, sai do modo de espera)
	
	// Ou seja, percorre todas as mensagens, verifica se está fazendo um acquire que ainda não finalizou daquele recurso específico
	// Assim, vai aceitando as requisições a medida que são inseridas na lista de logs
	private Message firstAcquire(String resource){
		// quando eu der um release, eu mudar o tipo da mensagem para acquire_finished
		// criar um log auxiliar que controla os acquires
		for( Message message : this.observer.getLogMessages() ) {
			String[] protocolMessage = message.getContent().split("_"); // messageType_ClientAddr_resource => notify, wakeup
			String resourceName = resource.split("_")[0]; // resource_credentials
			// notify: acquire_Marcos_varX ==> acquire_finished: acquire_Marcos_varX
			if(!(message.getType().equals("acquire_finished")) && protocolMessage[0].equals("acquire") && protocolMessage[2].equals(resourceName))
				return message;
		}

		throw new IllegalStateException("No acquire resources found.");
	}


	/**
	 * tentativa de acessar um recurso
	 * @param id
	 * @param credentials
	 * @throws InterruptedException
	 */
	private String accessResource(int id, String resource) throws InterruptedException {

		Set<Message> logs = this.observer.getLogMessages();

		// A sincronização geralmente é necessária quando você está compartilhando dados entre várias chamadas
		// e existe a possibilidade de que os dados sejam modificados, resultando em inconsistência.
		synchronized (logs) {
			while (firstAcquire(resource).getLogId() != id) {
				System.out.println("[CLIENT] Estou esperando pelo recurso " + resource);
				logs.wait();
			}
		}
		
		// na hora que chegar uma mensagem no log, eu dar um notify -> independente de qual release for.
		// jeito nao elegante, esperar um tempo e olhar de novo
		return resource; 
	}

	// Parâmetros: broker abacaxi e o recurso (x, y ou z)

	public String acquire(String resource, String brokerName) throws IOException, InterruptedException{
		// Impede que se subscreva no broker 2 vezes (??) criar 2 vezes o msm broker (????)
		// Talvez remover isso
		if (! this.brokerAddresses.containsKey(brokerName)){
			throw new IllegalStateException("Any broker called " + brokerName + "  exists.");
		}

		Address primary;

		// Enquanto o broker primário desse cliente estiver ativo (????)
		while((primary = this.brokerAddresses.get(brokerName).key()) != null){

			// Envia uma mensagem de acquire
			Message msgPub = new MessageImpl();
			msgPub.setBrokerId(primary.getPort());
			msgPub.setType("acquire");
			msgPub.setContent("acquire_"+this.clientAddress.toString()+"_"+resource);
			

			//  aq ele recebe o feedback do broker - acquire_ack
			Message response;

			try {
				Client publisher = new Client(primary.getIp(), primary.getPort());

				response = publisher.sendReceive(msgPub);

				// Se o pedido de acquire tiver sucesso, tenta acessar o recurso
				// recupero o __offset__
				if (response.getType().equals("acquire_ack")) {
					// verificar se é a minha vez, se for acesso o recurso que está em response.content
					// se não for eu durmo e espero o server me acordar em caso de releases. aí eu verifico dnv
					return this.accessResource(response.getLogId(), response.getContent());
				}
				else 
					throw new IllegalStateException("No acquire_ack  found.");	

			} catch (IOException e) {
				// Se não consegue conectar com o primário, é porque ele caiu.
				System.out.println("[CLIENT] Emitindo 'TURN' para o outro broker e tentando novamente.");
				turn(brokerName);
			} 
		}

		throw new IllegalStateException("Any broker available");
		
	}

	private void turn(String brokerName) throws IOException {
		changePrimary(brokerName);

		Address primary = this.brokerAddresses.get(brokerName).key();

		if(primary != null) {
			// Primário envia mensagem de turn pra ele mesmo (???)	
			Message msgPub = new MessageImpl();
			msgPub.setBrokerId(primary.getPort());
			msgPub.setType("turn");
			
			Client publisher = new Client(primary.getIp(), primary.getPort());

			Message response = publisher.sendReceive(msgPub);

			if (response.getType().equals("turn-ack"))
				return;

		}

		throw new IllegalStateException("Can't convert secundary to primary broker."); // todo

	}

	public boolean release(String resource, String brokerName) throws IOException {
		// Impede que se subscreva no broker 2 vezes (??) criar 2 vezes o msm broker (????)
		// Talvez remover isso
		if (! this.brokerAddresses.containsKey(brokerName)){
			throw new IllegalStateException("Any broker called " + brokerName + "  exists.");
		}

		Address primary;

		while((primary = this.brokerAddresses.get(brokerName).key()) != null){

			Message msgPub = new MessageImpl();
			msgPub.setBrokerId(primary.getPort());
			msgPub.setType("release");
			msgPub.setContent("release_"+this.clientAddress.toString()+"_"+resource);
			

			//  aq ele recebe o feedback do broker
			try {
				Client publisher = new Client(primary.getIp(), primary.getPort());

				publisher.sendReceive(msgPub);

				return true; // todo

			}
			catch (IOException e) {
				System.out.println("[CLIENT] Emitindo 'TURN' para o outro broker e tentando novamente.");
				turn(brokerName);
			}
		}

		throw new IllegalStateException("Any broker available"); // todo
	}

	// Envia uma mensagem informando da unsubscrição (para o broker apenas???)
	public boolean unsubscribe(String brokerName) throws IOException{

		if (! this.brokerAddresses.containsKey(brokerName)){
			throw new IllegalStateException("Any broker called " + brokerName + "  exists.");
		}

		Address primary;

		while((primary = this.brokerAddresses.get(brokerName).key()) != null){

			Message msgPub = new MessageImpl();
			msgPub.setBrokerId(primary.getPort());
			msgPub.setType("unsub");
			msgPub.setContent(this.clientAddress.toString());
			

			//  aq ele recebe o feedback do broker
			try {
				Client publisher = new Client(primary.getIp(), primary.getPort());

				publisher.sendReceive(msgPub);

				return true;

			} catch (IOException e) {
				System.out.println("[CLIENT] Emitindo 'TURN' para o outro broker e tentando novamente.");
				turn(brokerName);
			}
		}

		throw new IllegalStateException("Any broker available"); // todo
		
	}

	public Set<Message> getLogMessages(){
		return observer.getLogMessages();
	}


	// Inicia as alterações para tornar o broker backup o primário
	// Seta o endereço do primário com as informações do secundário
	// Mas continua com o isPrimary = false, no turnPrimary é que seta isPrimary = true
	public void changePrimary(String brokerName) {
		Tuple<Address, Address> tuple = this.brokerAddresses.get(brokerName);

		tuple.setKey(tuple.value());
		tuple.setValue(null);
	}


	public void stopPubSubClient(){
		System.out.println("[CLIENT] Client stopped...");
		observer.stop();
		clientThread.interrupt();
	}

	class ThreadWrapper extends Thread{
		Server s;
		public ThreadWrapper(Server s){
			this.s = s;
		}
		public void run(){
			s.begin();
		}
	}	

}
