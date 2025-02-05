import javax.net.ssl.*;
import java.io.*;
import java.time.LocalDateTime;
import java.util.*;
import java.io.DataOutputStream;

public class SendMail {
    private static DataOutputStream dos;
    private static BufferedReader br;

    public static void main(String[] args) throws Exception {

        String user = "s2010676104@ru.ac.bd";
        String pass = "";

        String username = new String(Base64.getEncoder().encode(user.getBytes()));
        String password = new String(Base64.getEncoder().encode(pass.getBytes()));

        SSLSocket s = (SSLSocket) SSLSocketFactory.getDefault().createSocket("smtp.gmail.com", 465);

        dos = new DataOutputStream(s.getOutputStream());
        br = new BufferedReader(new InputStreamReader(s.getInputStream()));

        send("EHLO smtp.gmail.com\r\n");
        System.out.println("SERVER: " + br.readLine());
        System.out.println("SERVER: " + br.readLine());
        System.out.println("SERVER: " + br.readLine());
        System.out.println("SERVER: " + br.readLine());
        System.out.println("SERVER: " + br.readLine());
        System.out.println("SERVER: " + br.readLine());
        System.out.println("SERVER: " + br.readLine());
        System.out.println("SERVER: " + br.readLine());
        System.out.println("SERVER: " + br.readLine());

        send("AUTH LOGIN\r\n");
        System.out.println("SERVER: " + br.readLine());

        send(username + "\r\n");
        System.out.println("SERVER: " + br.readLine());

        send(password + "\r\n");
        System.out.println("SERVER: " + br.readLine());

        send("MAIL FROM:<s2010676104@ru.ac.bd>\r\n");
        System.out.println("SERVER: " + br.readLine());

        send("RCPT TO: <mijurujml@gmail.com>\r\n");
        System.out.println("SERVER: " + br.readLine());

        send("DATA\r\n");
        System.out.println("SERVER: " + br.readLine());

        send("FROM: s2010676104@ru.ac.bd\r\n");
        send("TO: mijurujml@gmail.com\r\n");
        send("Subject: miju.ch7@gmail.com" + "\r\n");
        send("This is a testing email!\r\n");
        
        send(".\r\n");
        System.out.println("SERVER: " + br.readLine());
        send("QUIT\r\n");
        System.out.println("SERVER: " + br.readLine());

    }

    private static void send(String s) throws Exception {
        dos.writeBytes(s);
        Thread.sleep(1000);
        System.out.println("CLIENT: " + s);
    }
}