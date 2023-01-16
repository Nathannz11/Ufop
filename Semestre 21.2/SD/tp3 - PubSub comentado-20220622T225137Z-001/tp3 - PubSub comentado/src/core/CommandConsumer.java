package core;


import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.List;
import java.util.SortedSet;

import core.client.Client;
import utils.Tuple;


//the useful socket consumer
// Relacionado aos comandos enviados pelo consumidor
public class CommandConsumer<S extends Tuple<Socket, Message>> extends GenericConsumer<S>{
	
	private Integer uniqueLogId;

	private SortedSet<Message> log;
	private List<String> subscribers;

	private Address primary;
	private boolean isPrimary;

	private Address backup;
		
	// Inicia os logs dos comandos (id 1) e seta os valores relacionados ao seu broker primário ou secundário
	public CommandConsumer(GenericResource<S> re, boolean isPrimary, Address address, SortedSet<Message> log, List<String> subscribers) {		
		super(re);

		this.log = log;
		this.subscribers = subscribers;
		this.uniqueLogId = 1;
		
		this.primary = new Address(null, 0);
		this.backup = new Address(null, 0);

		this.isPrimary = isPrimary;
				
		if (isPrimary){
			backup.setIp(address.getIp());
			backup.setPort(address.getPort());
		}
		else{
			primary.setIp(address.getIp());
			primary.setPort(address.getPort());
		}
	}
	
	
	// Se recebe mensagem de turn, faz o backup virar primário
	// Quando um cliente se subscreve pelo backup (tendo virado primário),
	// o backup repassa a subscrição do cliente p/ o broker primário.
	// Caso o broker já seja o primário, apenas executa o comando

	// Quando chega aqui pelo backup, é porque ele é (ou vai virar agora) o primário (???)

	@Override
	protected void doSomething(S pair) {
		/**
		 * Método executado pelo consumidor único do servidor do PubSubClient ou do Broker
		 * Ao conectar, o servidor produz o socket que será consumido neste método.
		 * Basicamente lê a mensagem, executa o comando requerido e envia a resposta obtida pelo comando.
		 * Atualmente, as mensagens podem ser:
		 * 	-> publicar alguma coisa para todos subscribers
		 *  -> receber uma notificação de algum nó que me inscrevi
		 *  -> subscrever em algum server
		 */
		
		Socket str = pair.key();
		Message msg = pair.value();			
		
		Message response = new MessageImpl();

		if (!isPrimary && msg.getType().equals("turn"))
			turnPrimary(msg);


		// Independente do broker primário ter parado, o backup pode ser startado em outro contexto como primário
		// Não é necessário apenas 1 primário (podem ter outros, que foram acionados por outros clientes)
		if (!isPrimary){
			System.out.println("[BACKUP] Repassando a mensagem de " +  msg.getType()  + " para o primário...");
			try {
				Client client = new Client(primary.getIp(), primary.getPort()); 
				response = client.sendReceive(msg);

				// resolve bug do backup quando se inscreve pelo backup
				if(response.getType().equals("sub_ack")) 
					response.setContent(primary.toString());
				
			}
			catch(IOException e) {
				System.out.println("[BACKUP] O primário caiu. Me tornando primário e executando => " + msg.getType());
				turnPrimary();
				System.out.println("[BACKUP] Log id atual: " + uniqueLogId);

				// O backup só executa o comando se ele for o primário
				response = executeCommand(msg);
			}
		} 
		else
			response = executeCommand(msg);
				
		try{
			ObjectOutputStream out = new ObjectOutputStream(str.getOutputStream());
			out.writeObject(response);
		
			out.flush();
			out.close();
			str.close();

		} catch (IOException e) {
			e.printStackTrace();
		} 	
	}

	// Executa o comando
	Message executeCommand(Message msg) {
		Message response = new MessageImpl();

		if (msg.getType().equals("turn")) {
			response = msg;
			response.setType("turn-ack");
			return response;
		}

		if(!(msg.getType().equals("notify")) && !(msg.getType().equals("wakeup")) )
			msg.setLogId(uniqueLogId); // é sub, unsub, acquire, release

		
		response = commands.get(msg.getType()).execute(msg, log, subscribers, backup);
		
	
		if(!(msg.getType().equals("notify"))  && !(msg.getType().equals("wakeup")))
			uniqueLogId = msg.getLogId();
		
			

		return response;
	}

	public void turnPrimary(Message msg) {
		System.out.println("[BACKUP] Verificando se o master está vivo....");
		try {
			Client client = new Client(primary.getIp(), primary.getPort()); 
		 	client.sendReceive(msg);
		}
		catch(IOException e) {
			System.out.println("[BACKUP] O primário caiu. Me tornando primário!");
			turnPrimary();
		}
	}

	public void turnPrimary() {
		// pegar o valor do ultimo log id
		this.uniqueLogId = this.log.last().getLogId();
		this.isPrimary = true;
	}

	@Override
	public SortedSet<Message> getMessages() {
		return log;
	}

}


// BROKER: focar na subscrição do backup
// begin do server: 
// sync consummer


// * envia mensagens de sincronização em cada comando