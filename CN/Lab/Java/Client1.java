import java.io.DataOutputStream;
import java.io.DataInputStream;
import java.net.*;
import java.util.Scanner;
public class Client1 {
    public static void main(String[] args) throws Exception {
        Socket s = new Socket("localhost", 7777);
        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        Scanner sc = new Scanner(System.in);
        String msg;

        do{
            String str = "Client: ";
            System.out.println(str);
            msg = sc.next();
            dos.writeUTF(msg);
            String server_response_string = (String) dis.readUTF();
            System.out.println("Server : " + server_response_string);
        }while(!msg.toLowerCase().equals(msg));
        sc.close();
        s.close();
        dos.close();
    }
}
