#include "graphics.hpp"
#include <vector>
#include <random>
#include <time.h>
int XX=1920;
int YY=1080;
using namespace genv;
struct hajo
{
    int x,y;
    int elet=5;
};
struct ammo
{
    int x,y;//kordináták
};
void model(const int& x,const int& y)
{
    gout<<move_to(x,y);
    gout<<move(22,5)<<color(50,183,255)<<box(5,-20)<<move_to(x+14,y-12)<<box(20,15)<<move_to(x+14,y-12)<<color(248,234,251)<<box(20,15)<<move_to(x,y)<<color(218,198,210)<<box(45,-10);
    for(int i=0; i<10; i++)
    {
        gout<<move_to(x+i,y)<<line(-30,15);
    }
    gout <<move(10,0)<<box(-40,10);
    gout <<move(43,-10);
    for (int i=-5; i<5; i++)
    {
        gout<<color(160,176,209)<<move_to(x-9,y+19)<<line(3,i);
    }

    for(int i=0; i<5; i++)
    {
        gout<<move_to(x-40-i,y+2)<<line(+3,15);
    }
    gout<<color(222,207,226)<<move_to(x-30,y-10)<<box(-55,14);

}

void ship(const event& ev, int& x, int& y)
{

    x=ev.pos_x;
    y=ev.pos_y;

    /* gout<<move_to(x,y);//hajó helye

      gout <<color(222,207,226)<<line(20,0)<<line(-4,-5)<<line(-10,-3)<<line(-8,0)<<line(-2,-3)<<line(0,10);// hajó grafikálya
    */
}
void shoot2( std::vector<ammo>& v,const event& ev)
{
    if(ev.type==ev_timer)
    {
        for(int i=0; i<v.size(); i++)
        {
            v[i].x=v[i].x+10;

            if(v[i].x>XX)
            {
                v.erase(v.begin()+(i-1));
            }
            for(int i=0; i<v.size(); i++)
            {
                gout<<color(255,100,100)<<move_to(v[i].x-7,v[i].y+14)<<box(10,10);
            }
        }
    }
}
void shoot1(std::vector<ammo>& v,const event& ev)
{
    if (ev.button==btn_left)
    {
        ammo a;
        a.x=ev.pos_x;
        a.y=ev.pos_y;
        v.push_back(a);
    }

}
void idegen(std::vector<hajo>& e,std::vector<ammo>& v)
{

    for(int i=0; i<e.size(); i++)
    {
        e[i].x=e[i].x-10;

        if(e[i].x<20)
        {
            e.erase(e.begin()+(i-1));
        }
    }
    for(int i=0;i<e.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(e[i].x-20<v[j].x&&e[i].x+20<v[j].x && e[i].y-20<v[j].y && e[i].y+20>v[j].y)
            {
                e.erase(e.begin()+(i-1));
            }
        }
    }
    for(int i=0;i<e.size();i++)
    {
            gout<<color(200,200,200)<<move_to(e[i].x-20,e[i].y-20)<<box(40,40);
    }

}

void enter(std::vector<hajo>& e)
{
    hajo a;
    a.y=rand()%1050+30;
    a.x=1900;
    e.push_back(a);
}
int main()
{
    gout.open(XX,YY,true);
    gout.showmouse(true);
    srand(time(0));
    event ev;
    std::vector<ammo> v;
    std::vector<hajo> e;
    int x,y;
    gin>>ev;
    x=ev.pos_x;
    y=ev.pos_y;
    gin.timer(10);
    while(gin >> ev && ev.keycode!=key_escape)
    {

        if(ev.type==ev_timer)
        {
            gout<<color(0,0,0)<<move_to(0,0)<<box(XX,YY);
            model(x,y);
            shoot2(v,ev);
            idegen(e,v);
            gout<<refresh;

        }
        else if(ev.type==ev_mouse)
        {
            ship(ev,x,y);
            shoot1(v,ev);
        }
        else if(ev.keycode==225)
        {

            enter(e);
        }
    }
    return 0;
}
