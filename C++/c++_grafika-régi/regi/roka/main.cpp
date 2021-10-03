#include "graphics.hpp"
#include <vector>
#include <iostream>
#include <random>
#include <string>
#include <time.h>
using namespace genv;
using namespace std;
const int X=500;
const int Y=500;
class csillag
{
    int x,y;
public:
    csillag(int hol)
    {
        x=rand()%X;
        y=hol;
    }
    void rajzol()
    {
        gout<<move_to(x,y)<<color(255,255,255)<<dot;

    }
    void mozog()
    {
        y++;
    }
    int get_y()
    {
        return(y);
    }

};
int main()
{
    gout.open(X,Y);
    event ev;
    gin.timer(100);
    vector<csillag*> v;
    for(int i=0; i<1000; i++)
    {
        csillag* cs=new csillag(rand()%Y);

        v.push_back(cs);
    }
    while(gin >> ev)
    {
        if(ev.type==ev_timer)
        {
            gout<<color(0,0,0)<<move_to(0,0)<<box(X,Y);
            for(int i=0; i<v.size(); i++)
            {

                v[i]->rajzol();
                v[i]->mozog();
                if(v[i]->get_y()>=Y/2)
                {
                    delete v[i];
                    v.erase(v.begin()+i);
                }
            }


            gout<<refresh;
        }
        if(ev.keycode==key_enter)
        {
            for(int i=0; i<1000; i++)
            {
                csillag* cs=new csillag(0);
                v.push_back(cs);
            }
        }
        /*gout<<move_to(0,0)<<color(0,0,0)<<box(X,Y);
        gout<<refresh;*/
    }
    return 0;
}
