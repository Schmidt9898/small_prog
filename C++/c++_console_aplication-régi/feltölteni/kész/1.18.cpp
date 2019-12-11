#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    //a="asdasdasd";
    //b="asdaqweqw";
    cin>>a>>b;
    if ((a.length()>=5) && (b.length()>=5)) {
    if (a.substr(0,5)==b.substr(0,5)){
        cout<<"igaz"<<endl;
    }else{
    cout<<"hamis"<<endl;
    }
    }else
    {
     cout<<"hamis"<<endl;
    }
    return 0;
}
