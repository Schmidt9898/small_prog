package hu.ppke.itk.java.homework.second.picture.components;

import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;

public class group implements Component {
	private ArrayList<Component> csoport = new ArrayList<Component>();
	@Override
	public void write(Writer output) throws IOException {
		for(int i=0;i<csoport.size();i++) {
			csoport.get(i).write(output);
		}
	}
	@Override
	public void translate(float dx, float dy) {
		for(int i=0;i<csoport.size();i++) {
			csoport.get(i).translate(dx, dy);
		}
		
	}
	@Override
	public void fliphorizontal(float axis) {
		for(int i=0;i<csoport.size();i++) {
			csoport.get(i).fliphorizontal(axis);
		}
		
	}
	@Override
	public void flipvertical(float axis) {
		for(int i=0;i<csoport.size();i++) {
			csoport.get(i).flipvertical(axis);
		}
		
	}
	public void addComponent(Component adom) {
		csoport.add(adom);
	}
	public void merge(group g) {
		for(int i=0;i<g.csoport.size();i++) {
			csoport.add(g.csoport.get(i));
		}
		
		
	}

}
