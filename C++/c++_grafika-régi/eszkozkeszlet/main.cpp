#include "graphics.hpp"
#include "ablak.hpp"
#include "eszkoz.hpp"
#include "josagok.h"
#include <vector>
using namespace genv;

struct ablakom:public ablak
{
    ablakom()
    {
        szovegdoboz* szo=new szovegdoboz(10,10,200,100);
        gomb* go=new gomb(10,120,100,50);
        szamos* so=new szamos(10,210,100,50);
        lista* li=new lista(250,10,200,300);

        eszkozok.push_back(li);
        eszkozok.push_back(go);
        eszkozok.push_back(szo);
        eszkozok.push_back(so);
    }
};

int main()
{
    ablakom Ablakom;
    Ablakom.esemeny_hurok();
    return 0;
}
