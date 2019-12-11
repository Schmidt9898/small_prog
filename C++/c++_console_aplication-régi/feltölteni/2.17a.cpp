#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int b,c;
    getline(cin,a);
    //a="majd (ez lesz) fontos";
    b=a.find("(");
    c=a.find(")");
    cout<<a.substr(b+1,c-b-1)<<endl ;
    return 0;
}
