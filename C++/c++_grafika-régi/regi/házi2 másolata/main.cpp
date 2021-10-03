#include "graphics.hpp"
#include <vector>
#include <random>
#include <time.h>
#include <cstdlib>
using namespace genv;
struct kord
{
    int x,y;
};
int szam(int a,int b)
{
    int r=0;
    if(b-a<0)
    {
        r=-1;
    }
    else if(b-a>0)
    {
        r=1;
    }
    return(r);
}
void rajz(std::vector<kord>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        gout<<color(i%156+50,i%200,i%170)<<move_to(v[i].x,v[i].y)<<box(1,1);
    }

}
void valt(std::vector<kord>& v)
{
    for(int i=0; i<=v.size(); i++)
    {
        if(i==v.size())
        {
            v[i].x=v[i].x+szam(v[i].x,v[0].x);
            v[i].y=v[i].y+szam(v[i].y,v[0].y);
        }
        else
        {
            v[i].x=v[i].x+szam(v[i].x,v[i+1].x);
            v[i].y=v[i].y+szam(v[i].y,v[i+1].y);
        }
    }
}


int main()
{
    gout.open(400,400);
    srand(time(0));
    event ev;
    std::vector<kord> v;
    for(int i=0; i<10000; i++)
    {
        kord a;
        a.x=rand()%400;
        a.y=rand()%400;
        v.push_back(a);
    }

    gin.timer(1);

    while(gin >> ev)
    {
if(ev.type==ev_timer)
{
gout<<move_to(0,0)<<color(0,0,0)<<box(400,400);
        rajz(v);
        valt(v);
        gout<<refresh;
}
    }
    return 0;
}
