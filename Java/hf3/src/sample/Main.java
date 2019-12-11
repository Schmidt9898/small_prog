package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Pane root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("hf3");
        primaryStage.setScene(new Scene(root, 300, 275));
        Button gomb=new Button();
        root.getChildren().add(gomb);
        gomb.setOnAction(e->{
            try {
                Parent newroot=FXMLLoader.load(getClass().getResource("A.fxml"));
                primaryStage.setScene(new Scene(newroot,600,400));
                primaryStage.show();
            } catch (IOException e1) {
                e1.printStackTrace();
            }

        });
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
