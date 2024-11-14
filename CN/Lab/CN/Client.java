import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws Exception{
        Socket s2 = new Socket("10.110.50.72",7777);
        DataOutputStream ds2 = new DataOutputStream(s2.getOutputStream());
        ds2.writeUTF("Hello, Alomgir!");
        //Leter code for two way.
        ServerSocket ss = new ServerSocket(7777);
        Socket s1 = ss.accept();
        DataInputStream ds1 = new DataInputStream(s1.getInputStream());
        String msg = (String) ds1.readUTF();
        System.out.println("Message-----"+msg);
        ss.close();
    }
    
}
