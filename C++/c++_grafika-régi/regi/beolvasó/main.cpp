#include "graphics.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace genv;
struct pixel
{
    int r,g,b;
};
struct kep
{
    std::vector<pixel> p;
    int x,y;
};
void beolvas(kep& k)
{
    std::ifstream f;
     f.open("hajo.kep");
    if (!f.good())
    {
        std::cerr<<"Nem sikerult a "<<"anyád"<<" fajl beolvasasa!!!!"<<std::endl;
        return;
    }
    f>>k.x>>k.y;
    k.p.resize(k.x*k.y);
    for(int i=0; i<(k.x*k.y); i++)
    {
        f>>k.p[i].r;
        f>>k.p[i].g;
        f>>k.p[i].b;
    }
    std::cout<<"A fajl beolvasasa megtortent"<<std::endl;
}
void megjelenit(kep& k, canvas &c)
{
    int z=0;
    for(int i=0; i<k.y; i++)
    {
        for(int j=0;j<k.x;j++)
        {
            c<<move_to(j,i)<<color(k.p[z].r,k.p[z].g,k.p[z].b)<<dot;
            z++;
        }
    }
    std::cout<<"A fajl beolvasasa megtortent"<<std::endl;
}

int main()
{
    gout.open(1220,800);
    event ev;
    kep k;
    beolvas(k);
canvas c;
c.open(k.x,k.y);
    megjelenit(k, c);
  // std::cout<<k.p[1].r<<std::endl;
    while(gin >> ev) {
            //gout<<move_to(ev.pos_x,ev.pos_y);
            gout << stamp(c,ev.pos_x,ev.pos_y);
     gout << refresh;
    }
    return 0;
}
