#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int a,b,i=1;
    cin>>a>>b;
    //a=6;
    //b=3;
    while(i<=a)
    {
        if(a%i==0 && b%i==0)
        {
            cout<<i<<" ";
        }
        i++;
    }
    return 0;
}
