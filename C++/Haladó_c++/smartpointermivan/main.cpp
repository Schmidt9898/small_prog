#include <iostream>

#include "smart_pointer.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    SMARTER_POINTER<int> ptr1(5);
    // cout << ptr1.GetElem() << endl;
      cout << "Lets set a new pointer to ptr1... " << endl;
   // SMARTER_POINTER<int> ptr2(ptr1);

     cout << ptr1.GetElemPtr() << endl;
     cout << ptr1.GetElem() << endl;
 cout << 6 << endl;
     cout << "Lets set a new pointer to ptr1... " << endl;
    cout << ptr1.GetElemPtr() << endl;
     cout << ptr1.GetElem() << endl;
     return 0;
}
