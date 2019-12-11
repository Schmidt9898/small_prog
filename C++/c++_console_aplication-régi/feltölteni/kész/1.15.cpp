#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string a;
    cin>>a;
    if (isalpha(a[0])){
    if (a[0]==toupper(a[0]))
    {
        cout<<"igaz"<<endl;
    }
        else{
            cout<<"hamis"<<endl;
    }}else{
    cout<<"hamis"<<endl;
    }
    return 0;
}
