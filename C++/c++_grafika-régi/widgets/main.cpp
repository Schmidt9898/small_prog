#include "graphics.hpp"
#include <iostream>
#include <vector>
#include "ablak.h"
using namespace genv;
using namespace std;

class ablakom:public ablak
{
    public:
    ablakom()
    {

    }

};

int main()
{
    ablakom Ablakom;
    Ablakom.esemeny_hurok();
    return 0;
}
