package sync;

import java.io.IOException;
import java.util.List;
import java.util.SortedSet;

import core.Address;
import core.Message;
import core.MessageImpl;
import core.PubSubCommand;
import core.client.Client;

public class MessageSyncCommand implements PubSubCommand{

	// Broker primário envia a mensagem pro backup
	@Override
	public Message execute(Message m, SortedSet<Message> log, List<String> subscribers, Address backup) {
		
		String[] content = m.getContent().split("=>");
		
		// boolean help = false;
		// int start = 0; 

		// if (content.length == 3){
		// 	start = Integer.parseInt(content[2]); // notifyLimit
		// 	help = true;
		// }

		m.setType(content[0]);
		m.setContent(content[1]);

		log.add(m);

		if (m.getType().equals("sub")) // adiciona o novo subscriber na lista de subscribers
			subscribers.add(m.getContent());
		
		if (m.getType().equals("unsub")){ // unsubscribe, remove o cliente da lista e imprime os logs
			subscribers.remove(m.getContent());
			// System.out.println("********************************************************************");
			// for(Message m1:log){
			// 	System.out.println("  ["+  m1.getLogId() + "] -- " + m1.getType()  + " -- " + m1.getContent());
			// }
			// System.out.println("********************************************************************");

			// System.out.println();
		}

		// Percorre os logs. Identifica a próxima mensagem c/ tipo acquire, que vai ser a próxima requisição a ser atendida
		// Se o tipo for acquire, seta como acquire_finished pra remover ela das próximas requisições a serem atendidas
		if (m.getType().equals("release")) {
			String[] releaseContent = m.getContent().split("_");
			String resource = releaseContent[1] + "_" + releaseContent[2];

			for( Message message : log ) {
				// firstAcquire
				if(message.getType().equals("acquire") && message.getContent().equals("acquire_" + resource)){
					message.setType("acquire_finished");
					break;
				}
			}

		}

		// Fingir que não existe
		// if (help) {
		// 	Message msg = new MessageImpl();
		// 	msg.setContent(m.getContent());
		// 	msg.setLogId(m.getLogId());
		// 	msg.setType("notify");
			
		// 	for(int i = start; i < subscribers.size(); i++) {
		// 		try {
		// 			String aux = subscribers.get(i);
		// 			System.out.println("[BACKUP] Notificando subscribe " + aux);
		// 			String[] ipAndPort = aux.split(":");
		// 			Client client = new Client(ipAndPort[0], Integer.parseInt(ipAndPort[1]));
		// 			msg.setBrokerId(m.getBrokerId());
		// 			client.sendReceive(msg);
		// 		} catch (IOException e) {
		// 			e.printStackTrace();
		// 		}
		// 	}
		// }


		// Notifica que a mensagem foi sincronizada com sucesso
        Message response = new MessageImpl();

		response.setContent("Message synchronized: " + m.getContent());
		response.setType("sync_ack");
		
		System.out.println("[SYNC] Message synchronized: (" + m.getType() + ") " +  m.getContent());

		return response;

	}

}
