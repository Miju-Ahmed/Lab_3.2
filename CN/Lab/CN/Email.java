import java.net.*;
import java.util.*;

import javax.net.ssl.*;

import java.io.*;

public class Email {

    private static DataOutputStream dos;
    private static BufferedReader br;

    public static void main(String[] args) throws Exception { 
          String user = "s2010676104@ru.ac.bd";
          String pass = "c717ca2633";
          String reciver = "mijurujml@gmail.com";
          String userName = new String(Base64.getEncoder().encode(user.getBytes()));
          String password = pass;
          SSLSocket s = (SSLSocket) SSLSocketFactory.getDefault().createSocket("smtp.gmail.com", 465);

    }
}