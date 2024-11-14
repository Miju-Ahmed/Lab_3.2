//For two way communication.

import java.io.DataInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.DataOutputStream;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.LocalDate;

public class Server1 {
    public static void main(String args[]) throws Exception{
        ServerSocket ss = new ServerSocket(7777);
        Socket s = ss.accept();

        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());

        String msg;

        do{
            msg = dis.readUTF();
            System.out.println(msg);
            if(msg.equalsIgnoreCase("hi")){
                System.out.println("Hello\n");
            }else if(msg.equalsIgnoreCase("time")){
                DateTimeFormatter dt = DateTimeFormatter.ofPattern("HH:MM");
                LocalTime localtime = LocalTime.now();
                String time = localtime.format(dt);
                dos.writeUTF(time);
            }else if(msg.equalsIgnoreCase("quit")){
                System.out.println("Quiting...\n");
            }else{
                System.out.println("Unknown\n");
            }
        }while(!(msg.equalsIgnoreCase("quit")));
        ss.close();
    }
    

}
