package hu.ppke.itk.java.homework.second.picture.components;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.Writer;

public class Circle implements Component{
	///Paraméterek
	protected float CenterX,CenterY,Radius;
	
  public float getCenterX() {
		return CenterX;
	}
	public float getCenterY() {
		return CenterY;
	}
	public float getRadius() {
		return Radius;
	}
public void write(Writer output) throws IOException {
    BufferedWriter bufferedWriter = new BufferedWriter(output);
    String code = "<circle cx='" + getCenterX() + "' cy='" + getCenterY() +
        "' r='" +
        getRadius() + "' stroke='black' fill='black' />";
    bufferedWriter.write(code, 0, code.length());
    bufferedWriter.newLine();
    bufferedWriter.flush();
  }
  public Circle(float x,float y,float r) {
	  CenterX=x;
	  CenterY=y;
	  Radius=r;
  }
@Override
public void translate(float dx, float dy) {
	CenterX+=dx;
	CenterY+=dy;
}
@Override
public void fliphorizontal(float axis) {
	CenterY=flip(CenterY,axis);
}
@Override
public void flipvertical(float axis) {
	CenterX=flip(CenterX,axis);
} 
}
