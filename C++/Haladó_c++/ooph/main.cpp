#include <iostream>
#include "A.h"

using namespace std;

int main()
{

    cout << "Hello world!" << endl;
    cout << "A vagy B vagy C" << endl;
    int id;
    cin>>id;
    A* temp=(respect.get_A(id));

    temp->F();
    return 0;
}
