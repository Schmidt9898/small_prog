package ablakaim;


import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;


public class main extends Application {
	@Override
	public void start(Stage atvesz) throws Exception {
		Label cim= new Label("Az enyim.");
		cim.setFont(Font.font(42));
		
		Image image = new Image("C:\\Dokumentumok\\Képek\\MEME\\kati.png", true); 
	    Label caption = new Label("Heroes of Might and Magic V");
	    caption.setFont(Font.font("Arial", FontWeight.BOLD, 20));
	    VBox vbox = new VBox(10, new ImageView(image), caption);
	    vbox.setAlignment(Pos.BASELINE_CENTER);
	   // setCenter(vbox);
	    Scene jelenet = new Scene(caption);
		atvesz.setScene(jelenet);
		atvesz.setOnCloseRequest(event -> Platform.exit());
		atvesz.setTitle("Mivan?");
		atvesz.show();
		
	}
	public static void main(String[] args) {
		launch(args);

	}



}
