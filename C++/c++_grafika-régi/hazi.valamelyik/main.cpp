#include "graphics.hpp"
#include <iostream>
#include <vector>
#include "WIDGET.h"
#include "tarolo.hpp"
#include "valt.hpp"
#include <string>

using namespace genv;
using namespace std;
int X=800,Y=500;
int main()
{
   gout.open(X,Y);
    event ev;
    tarolo* a=new tarolo(400,10);
    add_gomb* b=new add_gomb(10,10,200,100,&(a->v));
    torol_gomb* c=new torol_gomb(10,200,200,50,&(a->v));
    vector<WIDGET*> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    gin.timer(15);
    while(gin >> ev&&ev.keycode!=key_escape) {
            if(ev.type==ev_timer){
            gout<<move_to(0,0)<<color(0,0,0)<<box(X,Y);
            for(int i=0;i<v.size();i++)
            {
                v[i]->rajzol();
            }
            gout<<refresh;
    }
    else if(ev.button>0&&ev.button==btn_left)
    {
        bool meg=true;
            /*for(int i=0;i<v.size();i++)
            {
                v[i]->set_aktive(0);
            }*/

        for(int i=v.size()-1;i>=0;i--)
        {
            if(v.size()>0  && meg )
            {
meg!=v[i]->aktivitas(ev);
            }
        }
    }
    if(ev.time!=ev_timer)
    {
        for(int i=0;i<v.size();i++)
            {
                v[i]->doit(ev);
            }
    }

    }
    return 0;
}
