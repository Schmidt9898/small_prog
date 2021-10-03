#include "graphics.hpp"
#include <vector>
#include <string>
#include "kocka.hpp"
#include "ablak.h"
#include "eszkoz.hpp"
#include "gomb.hpp"

using namespace genv;
const int X=1000,Y=700;

struct ablakom : public ablak
{
    ablakom()
    {
    tabla* ta=new tabla(3,0,0,Y);
    gomb* go=new gomb(720,10,200,50,"Restart",ta);
    gomb2* jel=new gomb2(720,70,200,50," ");
    eszkozok.push_back(ta);
    eszkozok.push_back(jel);
    eszkozok.push_back(go);
    }
};


int main()
{
    gout.open(X,Y);
    ablakom Ablakom;
    Ablakom.esemeny_hurok();
    return 0;
}
