package hu.ppke.itk.java.homework.second.picture.components;

import java.io.IOException;
import java.io.Writer;

interface Component {
	public abstract void write(Writer output) throws IOException;
	public void translate(float dx,float dy);
	public void fliphorizontal(float axis);
	public void flipvertical(float axis);
	default public float flip(float x, float dx)
	   {
		if(x>dx)
			return x+2*(dx-x);
			else 
			return x-2*(x-dx);	
	}
}
