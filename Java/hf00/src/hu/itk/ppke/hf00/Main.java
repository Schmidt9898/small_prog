package hu.itk.ppke.hf00;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Main {

    public static int majorityVoting(int[] votes) {

        int m=0,i=0;
        for(int x :votes)
        {
            if(i==0)
            {
                m=x;
                i=1;
            }
            else
            {
                if(m==x)
                {
                    i++;
                }else
                    i--;

            }
        }
        i=0;
        for(int x:votes)
        {
            if(x==m)
                i++;
        }
        if(i<=(votes.length/2))
            m=-1;


        return m;
    }


    public static int[] heavyHitters(int[] votes, int k) {
        int[] res = new int[k - 1];
        int[] m = new int[k-1];
        int i=0;


        for(int x :votes)
        {
            if(res[i]==0){

                m[i]=x;
                res[i]=1;
            }
            else
           {
               int idx=-1;
               for(int j=0;j<k-1;j++)
               {
                   if(m[j]==x)
                   {
                       idx=j;
                       break;
                   }
               }
               if(idx!=-1)
               {
                   i=idx;
                   res[i]++;
               } else {
                     idx = -1;
                    for (int j = 0; j < k - 1; j++) {
                        if (res[j] == 0) {
                            idx = j;
                            break;
                        }
                    }
                    if (idx != -1) {
                        i = idx;
                        m[i] = x;
                        res[i] = 1;
                    } else {
                        for (int j = 0; j < k - 1; j++) {
                            res[j]--;
                        }
                        i=0;
                    }
                }


            }

        }


        i=0;
        for(int j=0;j<k-1;j++)
        {
            for(int x:votes)
            {
                if(x==m[j])
                    i++;
            }
            if(i<=k)
                m[j]=-1;
        }

        Arrays.sort(m);
        int[] val=new int[m.length];

        for(int j=0;j<m.length;j++)
        {
            val[j]=m[m.length-1-j];
        }


        return val;
    }

    public static void main(String[] args) {
        System.out.println("Homework 01 k=2 (element occurs more than 50%): Majority Voting algorithm");
        int score = 0;
        int[] dataset = new int[]{1, 2, 3, 4, 5, 5, 5, 5, 5, 1, 1, 1, 5, 5, 5, 5, 5};
        int res = majorityVoting(dataset);
        System.out.println("res = " + res);
        if (res == 5) {
            score++;
            System.out.println("TEST 1 PASSED");
        }

        int[] dataset2 = new int[]{1, 2, 3, 4, 5, 5};
        res = majorityVoting(dataset2);
        System.out.println("res = " + res);
        if (res == -1) {
            score++;
            System.out.println("TEST 2 PASSED");
        }

        System.out.printf("SCORE %d/2\n", score);

        System.out.println("Optional more general solution: HeavyHitters algorithm");
        int[] result = heavyHitters(dataset, 3);
        System.out.println("res = " + Arrays.toString(result));
        if (result[0] == 5 && result[1] == 1 && result.length == 2) {
            score++;
            System.out.println("TEST 3 PASSED");
        }

        result = heavyHitters(dataset2, 3);
        System.out.println("res = " + Arrays.toString(result));
        if (result[0] == -1) {
            score++;
            System.out.println("TEST 4 PASSED");
        }

        System.out.printf("SCORE %d/2", score);

    }

}
