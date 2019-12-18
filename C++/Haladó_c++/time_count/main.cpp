#include <iostream>
#include "Windows.h"
#include <thread>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    long int before = GetTickCount();

// Perform time-consuming operation

long int after = GetTickCount();

 cout << after-before << endl;

    return 0;
}
