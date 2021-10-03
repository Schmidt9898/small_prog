#include "graphics.hpp"
#include <vector>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
int XX=1920;
int YY=1080;
int elet=5;
int pont=0;
bool bezar=true;
using namespace genv;
canvas c;
/*  struct Car {
  int name;
int cost;
Car(int n, int c)
{
	name = n;
	cost = c;
}
  };*/
struct kord
{
    int x,y;
};
struct pixel
{
    int r,g,b;
};
struct kep
{
    std::vector<pixel> p;
    int x,y;
};
void beolvas(kep& k)
{
    std::ifstream f;
     f.open("hajo.kep");
    if (!f.good())
    {
        std::cerr<<"Nem sikerult a hajo.kep fajl beolvasasa!!!!"<<std::endl;
        return;
    }
    f>>k.x>>k.y;
    k.p.resize(k.x*k.y);
    for(int i=0; i<(k.x*k.y); i++)
    {
        f>>k.p[i].r;
        f>>k.p[i].g;
        f>>k.p[i].b;
    }
    std::cout<<"A fajl beolvasasa megtortent"<<std::endl;
}
void komp(kep& k, canvas &c)
{
    int z=0;
    for(int i=0; i<k.y; i++)
    {
        for(int j=0;j<k.x;j++)
        {
            c<<move_to(j,i)<<color(k.p[z].r,k.p[z].g,k.p[z].b)<<dot;
            z++;
        }
    }
    std::cout<<"A fajl beolvasasa megtortent"<<std::endl;
}

void shoot1(std::vector<kord>& v,const event& ev)
{
    if (ev.button==btn_left)
    {
        kord a;
        a.x=ev.pos_x+30;
        a.y=ev.pos_y+16;
        v.push_back(a);
    }
}
void shoot2( std::vector<kord>& v,const event& ev)
{
    //std::cout<<v.size();
    if(ev.type==ev_timer)
    {
        for(int i=0; i<v.size(); i++)
        {
            v[i].x=v[i].x+10;

            if(v[i].x>XX)
            {
                v.erase(v.begin()+(i-1));
            }
        }
            for(int i=0; i<v.size(); i++)
            {
                gout<<color(255,100,100)<<move_to(v[i].x-5,v[i].y-5)<<box(10,10);
            }
    }
}
void idegen(kord& hajo, std::vector<kord>& v,std::vector<kord>& e)
{
    //int a=1;
    while(e.size()<10)
    {
        kord a;
        a.x=1920;
        a.y=(rand()%1000)+40;
        e.push_back(a);
    }

    for(int i=0; i<e.size(); i++)
    {
        e[i].x=e[i].x-5;

        if(e[i].x<21)
        {
           // e.erase(e.begin()+(i-1));
            e[i]=e[e.size()-1];
            e.pop_back();
            i--;
        }
    }
    for(int i=0;i<e.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(e[i].x>v[j].x-25&&e[i].x<v[j].x+25&&e[i].y>v[j].y-25&&e[i].y<v[j].y+25 )
            {
                //e.erase(e.begin()+(i-1));
            e[i]=e[e.size()-1];
            e.pop_back();
            v[j]=v[v.size()-1];
            v.pop_back();
            i--;
            pont++;
            }
        }
    }
            for(int i=0;i<e.size();i++)
        {
           // gout<<color(100,100,10)<<move_to(hajo.x-100,hajo.y-25)<<box(200,50);
            if( e[i].x>hajo.x-120 && e[i].x<hajo.x+120 && e[i].y>hajo.y-45 && e[i].y<hajo.y+45 )
            {
                //e.erase(e.begin()+(i-1));
            e[i]=e[e.size()-1];
            e.pop_back();
            elet--;
            i--;
            }
        }
    for(int i=0;i<e.size();i++)
    {
            gout<<color(200,200,200)<<move_to(e[i].x-20,e[i].y-20)<<box(40,40);

    }

}
void model(const kord& hajo)
{
    int x=hajo.x,y=hajo.y;
    //  gout<<move_to(x,y);
    //c.transparent(true);
  //  gout << stamp(c,x-100,y-25);
    // int a=elet;

    gout<<move_to(1,1)<<color(200,200,200)<<box(100,100);

    /*gout<<move(22,5)<<color(50,183,255)<<box(5,-20)<<move_to(x+14,y-12)<<box(20,15)<<move_to(x+14,y-12)<<color(248,234,251)<<box(20,15)<<move_to(x,y)<<color(218,198,210)<<box(45,-10);
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
*/
}
void start()
{
     //  gout.showmouse(false);

    event ev;
    gin.timer(10);
    kord eger,hajo;
    std::vector<kord> ammo;
    std::vector<kord> it;
    while(gin >> ev && bezar)
    {
        if(ev.type==ev_timer)
        {
            gout<<color(5,25,20)<<move_to(0,0)<<box(XX,YY);
            model(hajo);
            //shoot2(ammo,ev);
           // idegen(hajo,ammo,it);
 //           gout<<color(255,255,255)<<move_to(0,0)<<box(elet*10,10);
          /*  std::stringstream ss;
            ss<<pont;
           // pont>>ss;
            std::string s;
            ss>>s;
            gout<<color(255,255,255)<<move_to(10,10)<<text(s);
           // std::cout<<elet;*/
            gout<<refresh;

        }
        else if(ev.type==ev_mouse)
        {
            hajo.x=ev.pos_x;
            hajo.y=ev.pos_y;
            shoot1(ammo,ev);
        }else if(ev.keycode==key_escape)
        {
            bezar=false;
        }
    }
}

void menu()
{
    event ev;
    gin.timer(30);
    kord eger;
    //gout.showmouse(true);
    while (gin >> ev && bezar)
    {
        eger.x=ev.pos_x;
        eger.y=ev.pos_y;
        if(ev.keycode==key_escape)
        {
            bezar=false;
        }
        if(ev.type==ev_timer)
        {
            gout<<move_to(500,500)<<color(0,255,0)<<box(100,100)<<move_to(500,600)<<color(255,0,0)<<box(100,100)<<refresh;
        }
        if(ev.type==ev_mouse)
        {

            if(ev.button>0 && eger.x>=500 && eger.x<=600 && eger.y>=500 && eger.y<=600)
            {
                std::cout<<"zöld"<<std::endl;
                elet=5;
                start();
            }
            if(ev.button>0 && eger.x>=500 && eger.x<=600 && eger.y>=600 && eger.y<=700)
            {
                std::cout<<"piros"<<std::endl;
                bezar=false;
            }
        }
    }
}

int main()
{
gout.open(XX,YY,true);
event ev;
kep k;
beolvas(k);
c.open(k.x,k.y);
    komp(k, c);
    while (bezar)
    {
        menu();
    }
    return 0;
}

