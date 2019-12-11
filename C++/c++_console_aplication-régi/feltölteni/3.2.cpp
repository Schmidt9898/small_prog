#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,i,b;
    cin>>a;
    //a=9438;
    i=1;
    b=0;
while (i<=a)
{
    if (a%i==0)
    {
        b=b+i;
    }
    i++;
}
cout<<b<<endl;
    return 0;
}
