package hu.ppke.itk.java.halpa.beadando;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException, InterruptedException {
        System.out.println("Start.");


        System.out.println("Mit indítsak? \n -local\n-server\nclient");

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String inp = bf.readLine();
        switch (inp)
        {
            case "local":
                UserInterface ui = new GameTextUI();
                Thread one = new Thread((GameTextUI) ui);
                PlayerCommunicator pcom = new LocalPlayer(ui);
                Thread two = new Thread((LocalPlayer) pcom);

                one.start();
                two.start();

                one.join();
                two.join();
                break;
            case "server":
                NetworkClient nk = new NetworkClient();
                Thread nkt = new Thread(nk);
                nkt.setDaemon(true);
                nkt.start();
                nkt.join();
                break;
            case "client":
                System.out.println("akkó ip adjad idefele");
                String strip= bf.readLine();
                System.out.println("és az portot is.");
                int port = Integer.parseInt(bf.readLine());

                UserInterface uic = new GameTextUI();
                Thread uit = new Thread((GameTextUI) uic);
                PlayerCommunicator pon = new NetworkPlayer(uic,strip,port);
                Thread pont = new Thread((NetworkClient) pon);

                break;
        }





        System.out.println("End!");
    }
}
