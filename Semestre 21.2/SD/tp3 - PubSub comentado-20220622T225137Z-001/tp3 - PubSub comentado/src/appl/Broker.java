package appl;

import core.Address;
import core.Message;
import core.MessageImpl;
import core.Server;
import core.client.Client;

import java.util.Scanner;

public class Broker {

	public static void main(String[] args) {
		new Broker();
	}
	
	public Broker(){
		/* aí a gente vai rodar alguns casos de exemplo.
			1º caso: fazendo os clientes se subscreverem pelo broker
				inicialmente, o broker trata das requisições dos clientes e sincroniza esses logs com o backup
				caso ocorra algum problema no primário durante a sua execução e ele venha a cair,
				então o backup é que assume o papel de primário, e aí é ela que começa a tratar das
				que estão subscritos
			
			2º caso: o segundo caso de exemplo que a gente vai rodar, é com um usuário
					subscrevendo pelo primário (vm3) e outro subscrevendo direto pelo backup (vm2).
					nesse caso, o cliente que está subscrito no backup faz as requisições
					e essas requisições são repassadas para o primário, que é quem está
					realizando essas operações no momento.
					nesse segundo caso, se o backup cair, então o backup é deletado
					e broker primário adota o cliente que foi sobrescrito sobre ele e
					continua tratando as suas requisições.


			* falar que não tem o caso de rodarem n brokers backups para qualquer quantidade de clientes

			* primário ele só roda

		*/

		Scanner reader = new Scanner(System.in);  // Reading from System.in
		System.out.print("[SYSTEM] Enter the Broker port number: ");
		int port = reader.nextInt(); // Scans the next token of the input as an int.
		Address address = new Address("localhost", port);
		

		System.out.println("[SYSTEM] Is the broker primary? (Y | N)");
		boolean isPrimary = reader.next().toLowerCase().equals("y");

		Server s;
		ThreadWrapper brokerThread;

		boolean successBackup = false;

		if (! isPrimary) {
			// Se for broker backup, pega ip e porta do primário
			System.out.print("[SYSTEM] Enter the Primary Broker ip: ");
			String primaryHost = reader.next();

			System.out.print("[SYSTEM] Enter the Primary Broker port number: ");
			int primaryPort = reader.nextInt(); // Scans the next token of the input as an int.
		
			s = new Server(port, isPrimary, new Address(primaryHost, primaryPort));
			brokerThread = new ThreadWrapper(s);
			brokerThread.start();

			// Backup tenta enviar uma mensagem para o primario indicando que é um backup se subscrevendo,
			// se tiver sucesso em enviar a mensagem (e receber uma mensagem de volta), então successBackup = true
			Message msgBroker = new MessageImpl();
			msgBroker.setBrokerId(port);
			msgBroker.setType("backupSub");
			msgBroker.setContent(address.toString()); 

			Message status = null;

			try {
				Client subscriber = new Client(primaryHost, primaryPort);

				status = subscriber.sendReceive(msgBroker);
			
			} catch (Exception e) {
				successBackup = false;
			}

			if (status != null && status.getType().equals("backupSub_ack"))
				successBackup = true;
			
		} else {
			s = new Server(port, isPrimary);
			brokerThread = new ThreadWrapper(s);
			brokerThread.start();
		}

		// Se tiver sucesso em subscrever o backup ou for o primário, deixa em aberto a opção de parar o broker
		if (successBackup || isPrimary) {
			System.out.print("[SYSTEM] Shutdown the broker (Y|N)?: ");
			String resp = reader.next(); 
			if (resp.equals("Y") || resp.equals("y")){
				System.out.println("[SYSTEM] Broker stopped...");
				s.stop();
				brokerThread.interrupt();
				
			}
		}
		else {
			// Se não tiver sucesso no backup nem for primário, então é porque o backup falhou ou não existe o broker
			System.out.println("[SYSTEM] O backup não foi aceito pelo broker ou o broker não existe.");
			s.stop();
			brokerThread.interrupt();
		}

		
		//once finished
		reader.close();
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

/* baseado no que comparamos,
a parte de sincronização foi pego do joubert,
enquanto a parte de tolerância a falhas com o backup 
foi algo implementado pelo grupo
*/