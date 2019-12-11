package hu.ppke.itk.java.homework.second.picture.components;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Stack;
import java.util.Base64;
public class Picture {
private Stack<group> verem= new Stack();
private ArrayList<String> parancsok= new ArrayList();
{
	parancsok.add("add_line_segments");//0
	parancsok.add("add_circle");//1
	parancsok.add("add_rectangle");//2
	parancsok.add("new_group");//3
	parancsok.add("translate");//4
	parancsok.add("flip_vertical");//5
	parancsok.add("flip_horizontal");//6
	parancsok.add("merge");//7
///8 ha nem talál semmit;
}

public void build (Reader r) throws IOException, ParancsExceptions {
	BufferedReader br = new BufferedReader(r);
	group csoport = null;
	while(br.ready()) {
		Integer ide=8;
		String[] line=br.readLine().split(" ");
			for(int j=0;j<parancsok.size();j++) {
			if(line[0].equals(parancsok.get(j))){
				ide=j;
				break;
			}}
			switch (ide) {
			
			case 0:
				if(csoport!=null &&line.length>1) {
					ArrayList<Float> x = new ArrayList<Float>();
					ArrayList<Float> y = new ArrayList<Float>();
				for(int i=1;i<line.length;i+=2){
					x.add(Float.parseFloat(line[i]));
					y.add(Float.parseFloat(line[i+1]));
				}
				PolyLine p=new PolyLine(x,y);
				csoport.addComponent(p);
				continue;
				}else {
					throw new ParancsExceptions();
				}
			case 1:
				if(csoport!=null && line.length==4) {
					Circle c=new Circle(Float.parseFloat(line[1]),Float.parseFloat(line[2]),Float.parseFloat(line[3]));
				csoport.addComponent(c);
				continue;
				}else {
					throw new ParancsExceptions();
				}
				
			case 2:
				if(csoport!=null && line.length==5) {
					Rectangle c=new Rectangle(Float.parseFloat(line[1]),Float.parseFloat(line[2]),Float.parseFloat(line[3]),Float.parseFloat(line[4]));
				csoport.addComponent(c);
				continue;
				}else {
					throw new ParancsExceptions();
				}
				
			case 3:
				if(csoport==null) {
					csoport=new group();
				continue;}
				else if(csoport!=null){
					verem.add(csoport);
					csoport=new group();
					continue;
				}
				
			case 4:
				if(csoport!=null && line.length==3) {
					csoport.translate(Float.parseFloat(line[1]),Float.parseFloat(line[2]));
				continue;}
				else
					throw new ParancsExceptions();
			case 5:
				if(csoport!=null && line.length==2) {
					csoport.flipvertical(Float.parseFloat(line[1]));
					continue;}
				else
					throw new ParancsExceptions();
			case 6:
				if(csoport!=null && line.length==2) {
					csoport.fliphorizontal(Float.parseFloat(line[1]));
					continue;}
				else
					throw new ParancsExceptions();
			case 7:
				if(csoport!=null && verem.size()>1) { 
					verem.peek().merge(csoport);
					csoport=null;
					continue;
				}else
					throw new ParancsExceptions();
				
			case 8:
				//semmit nem csinál .
				continue;
				
				
			}}}
public void write (Writer f) throws IOException {
	f.write("<?xml version='1.0' encoding='UTF-8' ?>");
	f.write("<svg xmlns='http://www.w3.org/2000/svg' version='1.1'>");
	f.flush();
	
	while(!verem.isEmpty())
		{
			verem.pop().write(f);
    	}
	
	f.write("</svg>");
	f.flush();
}
public void writeh (Writer b) throws IOException {
	Writer f = new StringWriter();
	
	b.write("<html>\n\t<body>\n\t\t<img height='100%' width='100%' src=\"data:image/svg+xml;base64,");
	f.write("<?xml version='1.0' encoding='UTF-8' ?>");
	f.write("<svg xmlns='http://www.w3.org/2000/svg' version='1.1'>");
	f.flush();
	
	while(!verem.isEmpty())
		{
			verem.pop().write(f);
    	}
	
	f.write("</svg>");
	f.flush();
	byte[] c= Base64.getEncoder().encode((f.toString().getBytes()));
	b.write(c.toString());
	b.write("\n</body>\n</html>");
	b.flush();
}
}
