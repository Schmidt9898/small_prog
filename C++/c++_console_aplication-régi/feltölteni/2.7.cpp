#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int a,b=1,c=0,d=0;
    cin>>a;
    //n=3;
    if (a==1)
    {
        cout<<0;
    }else
    {
        if (a==2)
        {
            cout<<2;
        }
        else
        {
          for (int i=3;i<=a;i++)
          {
              d=c+b;
              c=b;
              b=d;
          }
          cout<<d;
        }
    }


    return 0;
}
