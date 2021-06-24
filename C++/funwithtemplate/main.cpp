#include <iostream>
#include "FUNTemplete.h"
#include "FUNFunctions.h"
using namespace std;




class A
{
public:
    virtual void f()=0;
};




int main()
{
    cout << "This is Fun!" << endl;

    myPair<int,string> a(1,"asd");
    a.print();

    Print_int(5,2,3,4,1,6);

    Print(1,1.0,'3',"asd","asdasdasdasd",0,1,-2,3.14);

    string s="Csaba",ss="Kenobi";

    Print(s,ss,"asd");
    Print(mymax(1,5,3,44));

    int* t=new int[5]{1,2,3,4,5};

    Print(1[t]);

    [=]{};

    int x=5;
    int y=x++;
    Print((1.0+2.0)/2.0);

    Afunction();



    return 0;
}
