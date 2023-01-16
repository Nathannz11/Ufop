package appl;

import java.util.SortedSet;
import java.util.TreeSet;

import java.util.Iterator;
import java.util.Random;

import core.Message;
import core.MessageComparator;

public class OneAppl {
	private static String serverIp;
	private static int serverPort;
	private static String clientIp;
	private static int clientPort;

	public static void setServerIP(String ip){
		serverIp = ip;
	}

	public String getServerIP(){
		return serverIp;
	}

	public static void setServerPort(String port){
		serverPort = Integer.parseInt(port);
	}

	public int getServerPort(){
		return serverPort;
	}

	public static void setClientIP(String ip){
		clientIp = ip;
	}

	public String getClientIP(){
		return clientIp;
	}


	public static void setClientPort(String port){
		clientPort = Integer.parseInt(port);
	}

	public int getClientPort(){
		return clientPort;
	}

	public static void main(String[] args) throws Exception {
		setServerIP(args[0]);
		setServerPort(args[1]);
		setClientIP(args[2]);
		setClientPort(args[3]);
		new OneAppl();
	}

	public OneAppl() throws Exception{
		// Cria um novo pubsubclient com o ip e porta que passa como parametro
		// Subscreve no Appl um broker abacaxi que consome os recursos x, y, z aleatoriamente
		PubSubClient cliente = new PubSubClient(getClientIP(), getClientPort());

		String brokerAddress = getServerIP();
		Integer brokerPort = getServerPort();

		// Subscreve o cliente no broker_abacaxi e então insere o name do broker na lista de brokers em que o pubsub tá subscrito	
		cliente.subscribe("broker_abacaxi", brokerAddress, brokerPort);
		
		String[] resources = {"var X", "var Y", "var Z"};
		
		try {
			for(int i = 0; i < 10; i++){

				Random rand = new Random();
				int r = rand.nextInt(resources.length);
				String msg = resources[r];

				// Enquanto o broker primário desse cliente estiver ativo (????)
				// Se o pedido de acquire tiver sucesso, tenta acessar o recurso
				// verificar se é a minha vez, se for acesso o recurso que está em response.content
				// se não for eu durmo e espero o server me acordar em caso de releases. aí eu verifico dnv

				// Para isso, Percorre os logs, verificando, p cada mensagem, se está pedindo o acquire do recurso específico
				// e se não está indicando que já acabou a requisição
				// Se for a requisição, retorna o id da requisição (lá em cima, se o id retornado for igual ao id da requisição, sai do modo de espera)
				
				// Ou seja, percorre todas as mensagens, verifica se está fazendo um acquire que ainda não finalizou daquele recurso específico
				// Assim, vai aceitando as requisições a medida que são inseridas na lista de logs
				String resource = cliente.acquire(msg, "broker_abacaxi");

				// Usa o recurso por um período x de tempo
				cliente.useResource(resource);

				// Libera o recurso
				cliente.release(msg, "broker_abacaxi");
			
			}
	
			// Imprime todos (?) os logs
			SortedSet<Message> log =  new TreeSet<Message>(new MessageComparator());
			log.addAll(cliente.getLogMessages());

		
			Iterator<Message> it = log.iterator();

			System.out.println("********************************************************************");
			while(it.hasNext()){
				Message aux = it.next();
				System.out.println("  ["+  aux.getLogId() + "] -- " + aux.getContent());
			}
			System.out.println("********************************************************************");

			System.out.println();

		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		finally {
			cliente.unsubscribe("broker_abacaxi");
			cliente.stopPubSubClient();
		}

	}
}