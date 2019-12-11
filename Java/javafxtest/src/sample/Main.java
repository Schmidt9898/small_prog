package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.awt.*;
import java.io.File;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root =  new Pane(); //FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("Hello World");
        primaryStage.setScene(new Scene(root, 300, 275));


        //String musicFile = "C:\\Users\\Schmidt László\\Music\\BABYMETAL - Distortion (OFFICIAL).mp3";     // For example

       /* Media sound = new Media(new File(musicFile).toURI().toString());
        MediaPlayer mediaPlayer = new MediaPlayer(sound);
        mediaPlayer.play();*/




        primaryStage.show();
    }
    public class Player extends Circle {
        public Player(int x, int y, int r, Color color)
        {
            super(x,y,r,color);


        }

        public


    }


    public static void main(String[] args) {
        launch(args);
    }
}
