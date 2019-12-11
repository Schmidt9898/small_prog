#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int b;
    getline(cin,a);
    //a="Schmidt László";
    b=a.find(" ");
    cout<<a[0]<<"."<<a[b+1]<<"."<<endl ;
    return 0;
}
