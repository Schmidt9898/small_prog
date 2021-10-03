#include "ablak.h"
#include "graphics.hpp"
#include <iostream>

using namespace genv;
const int X=1000,Y=700;
void ablak::esemeny_hurok()
{
    event ev;
//anyád
    gout.open(X,Y);
    gin.timer(15);
    while(gin >> ev)
    {
        if(ev.type!=ev_timer)
        {
      /*  for(int i=0; i<eszkozok.size(); i++)
            {
                eszkozok[i]->interakcio(ev,P);
            }*/
        }


///*////////////////////////////////////////////////////////////////
        if(ev.type==ev_timer)
        {
            gout<<move_to(0,0)<<color(0,0,0)<<box(X,Y);
           /* for(int i=0; i<eszkozok.size(); i++)
            {
                eszkozok[i]->rajzol(P);
            }*/

            gout<<refresh;
        }

    }
}
