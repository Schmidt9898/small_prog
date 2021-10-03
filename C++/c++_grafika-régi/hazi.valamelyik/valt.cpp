#include "graphics.hpp"
#include <iostream>
#include <vector>
#include "tarolo.hpp"
#include "valt.hpp"
using namespace genv;
using namespace std;

valt::valt(int mxx,int myy)
        {
            mx=mxx;
            my=myy;
            cout<<"letrejott a valt ";
        }
        valt::~valt(){cout<<"kampec valt ";}

        void valt::rajzol(int xx,int yy)
        {
            x=xx;
            y=yy;
           gout<<move_to(x,y)<<color(0,0,20)<<box(mx,my);
           if(annyie){gout<<move_to(x,y)<<color(100,0,20)<<box(mx,my);}
           gout<<move_to(x,y-7)<<color(255,255,250)<<text(nev);
        };
        void valt::doit(event e)
        {
            if(e.pos_x>=x&&e.pos_x<=x+mx&&e.pos_y>=y&&e.pos_y<=y+my&&e.button>0)
            {
            annyie=!annyie;
            }
        }

