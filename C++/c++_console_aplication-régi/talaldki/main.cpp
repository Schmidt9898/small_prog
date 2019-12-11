#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
srand(time(0));
int titok = rand() % 100;
int tip=-1;
int lepes=0;
bool talalt= false;
while(!talalt){
    cout<<"Tippelj:";
    cin>>tip;
    if(titok<tip){
            lepes=lepes+1;
        cout<<"Tul nagy"<<endl;
    }
        if(titok>tip){
            lepes=lepes+1;
        cout<<"Tul kicsi"<<endl;
    }
        if(titok==tip){
            lepes=lepes+1;
                talalt=true;
        cout<<"Talalt:"<<titok<<endl;
    cout<<endl;
    cout<<"Lepesek szama:"<<lepes<<endl;
    }
}


    return 0;
}
