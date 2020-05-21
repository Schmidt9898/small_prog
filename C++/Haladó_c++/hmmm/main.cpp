#include <iostream>

#define unless else

using namespace std;

int main()
{
    int i=2;
    if(i==1)
        cout<<"1\n";
    else if(i==0)
        cout<<"0\n";
    unless
    cout<<"unless\n";

    return 0;
}
