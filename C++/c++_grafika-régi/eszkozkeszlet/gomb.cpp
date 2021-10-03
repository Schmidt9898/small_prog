#include "josagok.h"
#include <vector>
#include "eszkoz.hpp"
#include <iostream>
#include "graphics.hpp"

using namespace std;
using namespace genv;
gomb::gomb(int xx,int yy,int mxx,int myy):eszkoz(xx,yy,mxx,myy)
    {
        cout<<"gomb_"<<endl;
    }
void gomb::rajzol()
{
        if(focus){gout<<move_to(x-2,y-2)<<color(255,255,255)<<box(mx+4,my+4);}
        gout<<move_to(x,y)<<color(50,50,50)<<box(mx,my);
        gout<<move_to(x,y+my/2)<<color(255,255,255)<<text(cim);
}

void gomb::csinalom(genv::event& ev)
{
    if(focus&&ev.button>0&&ev.button==btn_left)
        {
            ///Feladat.pl:
            cout<<"igen"<<endl;
        }
}
