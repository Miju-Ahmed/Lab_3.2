import java.io.*;
import java.time.LocalDateTime;
import javax.net.*;
import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;

import java.util.*;

class mail1{
    private static DataOutputStream dos;
    public static BufferedReader br;

    public static void main(String[] argv) throws Exception{
        String user = "s2010676104@ru.ac.bd";
        String pass = "c717ca2633";

        String username = new String(Base64.getEncoder().encode(user.getBytes()));
        String password = new String(Base64.getEncoder().encode(pass.getBytes()));

        SSLSocket s = (SSLSocket) SSLSocketFactory.getDefault().createSocket("smtp.gmail.com",465);
        
    }
}
