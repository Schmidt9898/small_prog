#include "josagok.h"
#include <vector>
#include "eszkoz.hpp"
#include <iostream>
#include "graphics.hpp"

using namespace std;
using namespace genv;

sor::sor(int mxx,int myy)
        {
            mx=mxx;
            my=myy;
            cout<<"letrejott a valt ";
        }
void sor::rajzol(int xx,int yy)
        {
            x=xx;
            y=yy;
           gout<<move_to(x,y)<<color(0,0,20)<<box(mx,my);
           if(en){gout<<move_to(x,y)<<color(100,0,20)<<box(mx,my);}
           gout<<move_to(x+mx/4,y+my/2)<<color(255,255,250)<<text(nevem);
        };
void sor::csinalom(genv::event& ev)
{
    if(ev.pos_x>=x&&ev.pos_x<=x+mx&&ev.pos_y>=y&&ev.pos_y<=y+my
            &&ev.button>0&&ev.button==btn_left)
    {
        en=!en;
    }
}


lista::lista(int xx,int yy,int mxx,int myy):eszkoz(xx,yy,mxx,myy)
{
    for(int i=0; i<5; i++)
    {
        sor* a=new sor(mx,my/8);
        v.push_back(a);
    }
    cout<<"lista"<<endl;
}
void lista::rajzol()
{
    if(focus)
    {
        gout<<move_to(x-2,y-2)<<color(255,255,255)<<box(mx+4,my+4);
    }
    gout<<move_to(x,y)<<color(50,50,50)<<box(mx,my);
    int eltol=my/8;
    for(int i=0;i<v.size();i++)
        {
          //gout<<move_to(x,y+eltol);
          v[i]->rajzol(x,y+eltol);
          eltol+=v[i]->my+1;
        }

}

void lista::csinalom(genv::event& ev)
{
     for(int i=0; i<v.size(); i++)
    {
        v[i]->csinalom(ev);
    }
}
