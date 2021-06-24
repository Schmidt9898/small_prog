#include <iostream>
#include "Timer.h"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Timer_Filemode=false;
    {
        Timer p("asd");
    for(size_t i=0;i<1000000000;i++){}
    }



    return 0;
}
