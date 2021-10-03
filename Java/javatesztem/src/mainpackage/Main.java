package mainpackage;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in));

                System.out.println("Adj meg számokat szóközzel elválasztva. pl:1 2 3");



                String input = reader.readLine();


















         /*
                String[] strings = input.split(" ");
                double[] numbers = new double[strings.length];
                double sum=0,avg=0;
                boolean _2azonos=false;
        for (int i=0;i< strings.length;i++) {
            numbers[i]=Double.parseDouble(strings[i]);
            sum+=numbers[i];
        }
        outerloop:
        for (int i=0;i< numbers.length;i++) {
            for (int j = 0; j < numbers.length; j++) {
                if(i!=j && numbers[j]==numbers[i]) {
                    _2azonos = true;
                    break outerloop;
                }
            }
        }




        avg=sum/ numbers.length;

        System.out.println("összeg: "+sum);
        System.out.println("átlag: "+avg);
        System.out.println("Van köztük egysorma?: "+_2azonos);*/

    }
}