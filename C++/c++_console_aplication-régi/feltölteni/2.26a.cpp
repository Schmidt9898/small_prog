#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b;
    cin>>a;
    //a=9438;
    b=2;
while (a!=1)
{
    if (a%b==0)
    {
        a=a/b;
        cout<<b<<" ";

    }
    else
        {
        b++;
        }
}
cout<<1<<endl;
    return 0;
}
