package hu.ppke.itk.java.homework.second.picture.components;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.Writer;

public class Rectangle implements Component{  
private float leftx,lefty,width,height;
  public float getTopLeftX() {
	return leftx;
}
public float getTopLeftY() {
	return lefty;
}
public float getWidth() {
	return width;
}
public float getHeight() {
	return height;
}
public void write(Writer output) throws IOException {
    BufferedWriter bufferedWriter = new BufferedWriter(output);
    String code = "<rect x='" + getTopLeftX() + "' y='" + getTopLeftY() + "' " +
        "" + "width='" + getWidth() + "' height='" + getHeight() + "' " +
        "stroke='black' " + "fill='black' />";
    bufferedWriter.write(code, 0, code.length());
    bufferedWriter.newLine();
    bufferedWriter.flush();
  }
  public Rectangle(float lx,float ly,float w,float h) {
	  leftx=lx;
	  lefty=ly;
	  width=w;
	  height=h; 
  }
@Override
public void translate(float dx, float dy) {
	leftx+=dx;
	lefty+=dy;
}
@Override
public void fliphorizontal(float axis) {
	lefty=flip(lefty,axis);
	
}
@Override
public void flipvertical(float axis) {
	leftx=flip(leftx,axis);
	
}
  
}
