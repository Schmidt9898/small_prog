#include "josagok.h"
#include <vector>
#include "eszkoz.hpp"
#include <iostream>
#include "graphics.hpp"
#include <sstream>

using namespace std;
using namespace genv;
szamos::szamos(int xx,int yy,int mxx,int myy):eszkoz(xx,yy,mxx,myy)
    {
        cout<<"szamos"<<endl;
    }
void szamos::rajzol()
{
        if(focus){gout<<move_to(x-2,y-2)<<color(255,255,255)<<box(mx+4,my+4);}
        gout<<move_to(x,y)<<color(100,100,100)<<box(mx,my);

        gout<<move_to(x+mx/4*3,y)<<color(200,10,10)<<box(mx/4,my/2)
       <<move_to(x+mx/4*3,y+my/2)<<color(10,10,200)<<box(mx/4,my/2);

       gout<<move_to(x+mx/8*7,y+my/3)<<color(255,255,255)<<text("+")
       <<move_to(x+mx/8*7,y+my/5*4)<<color(255,255,255)<<text("-");
stringstream s;
    s<<ertek;
    ertek0=s.str();
        gout<<move_to(x+mx/4,y+my/2)<<color(255,255,255)<<text(ertek0);
}

void szamos::csinalom(genv::event& ev)
{
    if(ev.button>0&&ev.button==btn_left)///görgõvel gyors értéknövelés
        {
         if(ev.pos_x>=x+mx/4*3&&ev.pos_x<=x+mx&&ev.pos_y>=y&&ev.pos_y<=y+my/2)
         {
             ///+
             ertek++;
             cout<<"+"<<endl;
         }
         if(ev.pos_x>=x+mx/4*3&&ev.pos_x<=x+mx&&ev.pos_y>=y+my/2&&ev.pos_y<=y+my)
         {
             ///+
             ertek--;
             cout<<"-"<<endl;
         }
        }
}
