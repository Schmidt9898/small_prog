package gui;

import java.awt.Event;

import javafx.geometry.Pos;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class hajopane extends StackPane {
public hajopane() {
	/*Rectangle background = new Rectangle(406, 432);
    background.setFill(Color.color(0.375, 0.375, 0.375));
    getChildren().add(background);
    setAlignment(background, Pos.CENTER);*/
    Pane kk = new Pane();
    kk.getChildren().addAll();
    for(int i=0;i<20;i++) {
    	for(int j=0;j<20;j++) {
    		Rectangle A=new Rectangle(20,20);
    		A.setFill(Color.color(0, 1,0));
    		A.setX(500/20*i+10);
    		A.setY(500/20*j);
    		A.setOnMouseClicked(Event -> A.setFill(Color.color(1, 0, 0)));
    		kk.getChildren().addAll(A);
    	}
    }
    this.getChildren().add(kk);
    
}
}
