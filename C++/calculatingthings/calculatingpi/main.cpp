#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;
double drand(){
double r=(double)(rand() % RAND_MAX)/RAND_MAX;
return r;
}


int main()
{
    cout << "Hello world!" << endl;
    float pi=0;
    unsigned long N=pow(10,7);
    /*
    for(int k=0;k<N;k++)
    {
        pi+=pow(-1,k)/(2*k+1);
    }
    pi*=4;
    cout<<pi<<"\n";*/

    srand (time(NULL));
    unsigned long count=0;
    //cout<<drand();
    double x,y;
    for(long k=0;k<N;k++)
    {
        x=drand();
        y=drand();
        //cout<<x*x+y*y<<"\n";
        if(x*x+y*y<1){
            count++;
        }
    }
    pi=4*(float)count/N;




cout<<pi<<"\n";








    return 0;
}
