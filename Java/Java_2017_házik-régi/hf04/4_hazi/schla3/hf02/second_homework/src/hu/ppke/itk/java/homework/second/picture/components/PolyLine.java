package hu.ppke.itk.java.homework.second.picture.components;

import java.io.BufferedWriter;
import java.util.ArrayList;
import java.io.IOException;
import java.io.Writer;

public class PolyLine implements Component{
	private ArrayList<Float> xeim;
	private ArrayList<Float> yaim;
	protected int PointX,PointY,NumberofPoints;
	public PolyLine(ArrayList<Float> x,ArrayList<Float> y) {
		xeim=x;
		yaim=y;
	}
  public float getPointX(int i) {
		return xeim.get(i);
	}
	public float getPointY(int i) {
		return yaim.get(i);
	}
	public int getNumberOfPoints() {
		return xeim.size();
	}
public void write(Writer output) throws IOException {
    BufferedWriter bufferedWriter = new BufferedWriter(output);
    StringBuilder codeBuilder = new StringBuilder("<polyline points=\"");
    codeBuilder.append(getPointX(0)).append(',').append(getPointY(0));
    for (int i = 1; i < getNumberOfPoints(); i++) {
      codeBuilder.append(' ').append(getPointX(i)).append(',').append(
          getPointY(i));
    }
    codeBuilder.append("\" style='fill:none;stroke:black;stroke-width:2'/>");
    String code = codeBuilder.toString();
    bufferedWriter.write(code, 0, code.length());
    bufferedWriter.newLine();
    bufferedWriter.flush();
  }
@Override
public void translate(float dx, float dy) {
	for(int i=0;i<xeim.size();i++) {
		xeim.set(i,xeim.get(i)+dx);
		yaim.set(i,yaim.get(i)+dy);
	}
	
}
@Override
public void fliphorizontal(float axis) {
	for (int i=0;i<xeim.size();i++) flip(xeim.get(i),axis);
	
}
@Override
public void flipvertical(float axis) {
	for (int i=0;i<yaim.size();i++) flip(yaim.get(i),axis);
	
}



}
