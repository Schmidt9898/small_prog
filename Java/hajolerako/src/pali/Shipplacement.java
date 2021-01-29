package pali;

import java.util.Random;

public class Shipplacement {
    Random rng;
    Shipplacement(){
        rng = new Random();
    }
    int [][] place(int num_players,int[] ships)
    {


        double size=0.0;
        size=ships[0]*(1);
        size+=ships[1]*(2);
        size+=ships[2]*(3);
        size+=ships[3]*(4);
        size*=Math.round(3.0/2.0);
        size+=1;
        size/=2;
        int sx= (int) Math.round(size),sy= (int) Math.round(size);
        //System.out.println(sx);

        int[][] grid=new int[sx][sy];

        for(int x=0;x<sx;x++)
        {
            for(int y=0;y<sy;y++)
            {
                grid[x][y]=0;
                //System.out.print(grid[x][y]+" ");
            }
            //System.out.println("");
        }

        for(int id=0;id<=num_players;id++) {
            for(int i=0;i<4;i++) {
                for (int ship = 0; ship < ships[i]; ship++) {
                    boolean ok = false;
                    int shiplength = i+2;
                    while (!ok) {
                        int x = rng.nextInt(sx), y = rng.nextInt(sy);
                        int start_x = x, start_y = y;
                        boolean orientation = rng.nextBoolean();// 0 horizontal right , 1 vertical down
                        ok = true;
                        //aligment:
                        for (int k = 0; k < shiplength; k++) {
                            if (grid[x][y] != 0) {
                                ok = false;
                                break;//aligment;
                            }
                            if (orientation)
                                y++;
                            else
                                x++;

                            if (x >= sx || y >= sy) {
                                ok = false;
                                break;
                            }

                        }
                        //System.out.println("ok" + ok);
                        if (ok) {
                            x = start_x;
                            y = start_y;
                            for (int k = 0; k < shiplength; k++) {
                                grid[x][y] = id;
                                if (orientation)
                                    y++;
                                else
                                    x++;
                            }
                        }
                    }

                }
            }
        }




        return grid;
    }
}
