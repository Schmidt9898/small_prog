#include <iostream>

using namespace std;

struct byte
{
    unsigned int bits:10;
};


int main()
{
    cout << "Hello world!" << endl;
    byte b;
    b.bits=0;
    for(int i=0;i<1000;i++)
        cout << ++b.bits << endl;

    return 0;
}
