#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string a;
    cin>>a;
    if (a[0]==a[a.length()-1])
    {
        cout << "igaz"<< endl;
    }else{
    cout<<"hamis"<<endl;
    }
    return 0;
}
