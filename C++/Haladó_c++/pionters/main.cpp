#include <iostream>
#include <memory>
using namespace std;

shared_ptr<int> makeint()
{
    return shared_ptr<int>(new int(0));
}

shared_ptr<int> plusplusz(shared_ptr<int> p)
{
    *p=*p+10;
    return p;
}
void display(shared_ptr<int> p)
{
    cout<<*p<<endl;
}


int main()
{
    cout << "Hello world!" << endl;

    display(plusplusz(makeint()));





    cout<<"vege"<<endl;
    return 0;
}
