#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,i=1,k;
    cin>>n;
    //n=3;
    cout<<endl;
        while(i<=n)
            {
                k=0;
                while(k!=i)
                {
                    cout<<"*";
                    k++;
                }
                cout<<endl;
                i++;
            }

    return 0;
}
