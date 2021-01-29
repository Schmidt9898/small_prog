package pali;

import java.util.Random;

public class Main {


    public static void main(String[] args) {

        Random rng = new Random();
        //int id=1;
        int num_players=3;
        int ships[]=new int[]{2,2,1,1};
        Shipplacement s=new Shipplacement();
        int[][] grid = s.place(num_players,ships);

        for(int x=0;x<14;x++)
        {
            for(int y=0;y<14;y++)
            {
                //grid[x][y]=0;
                //if(x==1 && x==y)
                //grid[x][y]=1;
                System.out.print(grid[x][y]+" ");
            }
            System.out.println("");
        }





    }
}
