#include "graphics.hpp"
#include <iostream>
#include <vector>
#include "WIDGET.h"
#include "valt.hpp"

using namespace genv;
using namespace std;

       WIDGET::WIDGET(int xx,int yy,int mxx,int myy)
        {
            x=xx;
            y=yy;
            mx=mxx;
            my=myy;
            cout<<"letrejott a ";
        }
        WIDGET::~WIDGET(){cout<<"kampec";}
    bool WIDGET::aktivitas(event e)
        {
            if(e.pos_x>=x&&e.pos_x<=x+mx&&e.pos_y>=y&&e.pos_y<=y+my)
            {
            aktive=true;
            }
            return(aktive);
        }
        void WIDGET::set_aktive(bool a)
        {
            aktive=a;
        }

            void add_gomb::rajzol()
    {
        if(aktive){
        gout<<move_to(x-2,y-2)<<color(200,0,20)<<box(mx+4,my+4);
        }
        gout<<move_to(x,y)<<color(100,90,120)<<box(mx,my);
          gout.load_font("LiberationSans-Regular.ttf", 30);
        gout<<move_to(x,y)<<color(200,180,240)<<box(mx,my/2);
        gout<<move_to(x,y+my/2)<<color(255,255,255)<<text("Hozzaad");
        gout<<move_to(x-6,y)<<color(255,255,255)<<text(szoveg);
    }
    void add_gomb::doit(event e)
    {
           if(e.pos_x>=x&&e.pos_x<=x+mx&&e.pos_y>=y+my/2&&e.pos_y<=y+my&&e.button>0)
            {
            valt* d=new valt(300,24);
            d->nev=szoveg;
            v->push_back(d);
            }
        if(aktive){
        if(e.keycode>=32&&e.keycode<=164&& gout.twidth(szoveg)<mx-5){
      //  cout<<(char) e.keycode;
        betuk.push_back((char) e.keycode);
        }
        szoveg=" ";
        if(e.keycode==key_backspace&& betuk.size()>=1)
        {
           betuk.pop_back();
        }

        for(int i=0;i<betuk.size();i++)
        {
           szoveg=szoveg+betuk[i];
        }
        }

    }
    void torol_gomb::rajzol()
    {
        if(aktive){
        gout<<move_to(x-2,y-2)<<color(200,0,20)<<box(mx+4,my+4);
        }
        gout<<move_to(x,y)<<color(100,90,120)<<box(mx,my);
          gout.load_font("LiberationSans-Regular.ttf", 30);
        gout<<move_to(x,y)<<color(255,255,255)<<text("Torol");
    }
    void torol_gomb::doit(event e)
    {
        if(e.button>0&&e.button==btn_left&&e.pos_x>=x&&e.pos_x<=x+mx&&e.pos_y>=y&&e.pos_y<=y+my)
        {
            for(int i=0;i<v->size()&&v->size()>0;i++)
            {
                if((*v)[i]->anny())
                {
                   // (*v)[i]=NULL;
                    delete (*v)[i];
                    (*v)[i]=(*v)[v->size()-1];
                    v->pop_back();
                    i--;
                }
            }
        }
    }

