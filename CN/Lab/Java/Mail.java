//Here we should make sure our gmail is less secured. 
//mygoogleaccout->security->less security->on
import java.io.*;
import javax.net.ssl.*;
import java.util.*;
import java.time.LocalDateTime;
import java.io.DataOutputStream;

public class Mail {
    private static DataOutputStream dos;
    public static BufferedReader br;

    public static void main(String[] args) throws Exception{
        String user = "miju.ch7@gmail.com";
        String pass = "xxx";

        String username = new String(Base64.getEncoder().encode(user.getBytes()));
        String password = new String(Base64.getEncoder().encode(pass.getBytes()));

        SSLSocket s = (SSLSocket) SSLSocketFactory.getDefault().createSocket("smtp.gmail.com",465);
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
        send("MAIL FROM: <miju.ch7@gmail.com>\r\n");
        System.out.println("SERVER: " + br.readLine());
        send("RCPT TO:<mijurujml@gmail.com>\r\n");
        System.out.println("SERVER: " + br.readLine());
        send("DATA\r\n");
        System.out.println("SERVER: " + br.readLine());
        send("FROM: miju.ch7@gmail.com\r\n");
        send("TO: mijurujml@gmail.com\r\n");
        send("Subject: Testin mail\r\n");
        send("Hi Miju\r\n");
        send(".\r\n");
        System.out.println("SERVER: " + br.readLine());
        send("QUIT\r\n");
        System.out.println("SERVER: " + br.readLine());
    }
    private static void send(String s) throws Exception{
        dos.writeBytes(s);
        Thread.sleep(1000);
        System.out.println("CLIENT: " + s);
    }
}
