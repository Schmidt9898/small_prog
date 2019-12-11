package sample;

import com.sun.javafx.scene.SceneEventDispatcher;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import valamik.TcpClient;


public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Pane root = new Pane();//FXMLLoader.load(getClass().getResource("sample.fxml"));
        Scene scene=new Scene(root, 600, 400);
        root.setBackground(new Background(new BackgroundFill(Color.GRAY, CornerRadii.EMPTY, Insets.EMPTY)));

        TcpClient player=new TcpClient("192.168.137.1",19982,scene,"laci1");
        player.setDaemon(true);
        player.start();

        primaryStage.setTitle("Hello World");
        primaryStage.setScene(scene);
       // primaryStage.setScene(new Scene(root, 600, 400));

        primaryStage.show();



    }


    public static void main(String[] args) {
        launch(args);
    }
}
