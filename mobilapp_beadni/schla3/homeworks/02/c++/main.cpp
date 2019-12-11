#include <iostream>

#include "smart_pointer.h"

using namespace std;

int main()
{
    cout << "Smarter Pointer Every Day!" << endl;
    //SMARTER_POINTER<int> ptr1;

    cout << "Make a smarter pointer to int..." << endl;
    SMARTER_POINTER<int> ptr1(new int(5));
    cout << ptr1.GetElem() << endl;
    cout << ptr1.GetElemPtr() << endl;
    //ptr1 = new SMARTER_POINTER<int>(&a);
    {


    cout << "Lets set a new pointer to ptr1... " << endl;
    SMARTER_POINTER<int> ptr2(ptr1);

    cout << ptr2.GetElem() << endl;
    cout << ptr2.GetElemPtr() << endl;
 cout << "Change the value. +1" << endl;
    *ptr2.GetElemPtr()+=1;
    cout << ptr1.GetElem() << endl;
    cout << ptr2.GetElem() << endl;
     cout << "Forget ptr2.. " << endl;

    }
     cout << "Lets make a new smarter_pointer ptr3.."<<endl;

     SMARTER_POINTER<int> ptr3(new int(1));
    cout << ptr3.GetElem() << endl;
    cout << ptr3.GetElemPtr()<<"\n  and write over vith ptr1." << endl;

   ptr3=ptr1;

    cout << ptr3.GetElem() << endl;
    cout << ptr3.GetElemPtr()<< endl;
   cout<< "and test over, delete the rest..." << endl;
    return 0;
}
