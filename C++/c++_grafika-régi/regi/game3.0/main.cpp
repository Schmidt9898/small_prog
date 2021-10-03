#include "graphics.hpp"
#include <vector>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

int XX=1280;
int YY=720;
int elet=5;
int pont=0;
bool bezar=true;
using namespace genv;
canvas c;
canvas t,g,l,Flash;
struct kord
{
    float x,y,s,f;
    int elet;

};
struct powerapp
{
    int x,y;
    int ido=1000;
    bool elet=false;
    bool celzo=false;
    bool aktiv=false;
    bool sugar=false;
    std::string neve=" ";

};
struct pixel
{
    int r,g,b;
};
pixel szin;
pixel szin2;
struct kep
{
    std::vector<pixel> p;
    int x,y; //mérete
};
struct nehez
{
    int t=10;
    int g=5;
    int l=1;
    bool tt=true;
    bool gg=false;
    bool ll=false;
};
nehez N;
void beolvas(kep& k,std::string filename)
{
    std::ifstream f;
    f.open(filename);
    if (!f.good())
    {
        std::cerr<<"Nem sikerult a "<<filename<<" fajl beolvasasa!!!!"<<std::endl;
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
void komp(kep& k, canvas& c)
{
    int z=0;
    std::cout<<"van"<<std::endl;
    for(int i=0; i<k.y; i++)
    {
        for(int j=0; j<k.x; j++)
        {
            c<<move_to(j,i)<<color(k.p[z].r,k.p[z].g,k.p[z].b)<<dot;
            z++;
        }
    }
    std::cout<<"A fajl canvason van"<<std::endl;
}
void kimp(kep& k)
{
    int z=0;
    for(int i=0; i<k.y; i++)
    {
        for(int j=0; j<k.x; j++)
        {
            gout<<move_to(j,i)<<color(k.p[z].r,k.p[z].g,k.p[z].b)<<dot;
            z++;
        }
    }
    std::cout<<"A hatter megjelenitve!"<<std::endl;
}

void shoot1(std::vector<kord>& v,const event& ev,bool b)
{
    if (ev.button==btn_left)
    {
        kord a;
        a.x=ev.pos_x+20;
        a.y=ev.pos_y+10;
        v.push_back(a);
    }
    else if(b)
    {
        kord a;
        a.x=ev.pos_x+20;
        a.y=ev.pos_y+10;
        v.push_back(a);
    }
}
void frez2(float& x,float& y)
{
    int j=0;
    for(int i=15; i>0; i=i-2)
    {
        gout<<color(20,255-i*17,0)<<move_to(x-8,y-8+j)<<box(i,i);
        j++;
    }
}
void shoot2( std::vector<kord>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        v[i].x=v[i].x+10;
        if(v[i].x>XX-5)
        {
            v[i]=v[v.size()-1];
            v.pop_back();
            i--;
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        //frez(v[i].x,v[i].y);
        Flash.transparent(true);
        gout << stamp(Flash,v[i].x-10,v[i].y-7);
    }
}
void idegen(kord& hajo, std::vector<kord>& v,std::vector<kord>& e,int& p,bool& pp,int sx,int sy,canvas haj,int sebesseg,std::vector<powerapp>& poo,powerapp& po,int mit)
{
    // v a töltények e az idegen hajók
    sx=sx/2;
    sy=sy/2;
    if(e.size()<p && pp && (rand()%50)==1)
    {
        kord a;
        a.x=1240;
        a.y=(rand()%620)+40;
        a.s=rand()%sebesseg+2;
        e.push_back(a);
    }
    for(int i=0; i<e.size(); i++)
    {
        e[i].x=e[i].x-e[i].s;

        if(e[i].x<sx/2-1)
        {
            // e.erase(e.begin()+(i-1));
            e[i]=e[e.size()-1];
            e.pop_back();
            i--;
        }
    }
    for(int i=0; i<e.size(); i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            //  std::cout<<e[i].x<<std::endl;
            if(e[i].x>v[j].x-(sx+5)&&e[i].x<v[j].x+(sx+5)&&e[i].y-(sy+5)<v[j].y&&e[i].y+(sy+7)>v[j].y )
            {
                if(rand()%10==5)
                {
                    if(mit==2)
                    {
                        powerapp power;
                        power.x=e[i].x-1;
                        power.y=e[i].y;
                        power.aktiv=true;
                        power.celzo=true;
                        power.neve="AIM";
                        poo.push_back(power);
                    }
                    if(mit==1)
                    {
                        powerapp power;
                        power.x=e[i].x-1;
                        power.y=e[i].y;
                        power.aktiv=true;
                        power.elet=true;
                        power.neve="HP";
                        poo.push_back(power);
                    }
                    if(rand()%5==1)
                    {
                        powerapp power;
                        power.x=rand()%1080+200;
                        power.y=rand()%700+10;
                        power.aktiv=true;
                        power.ido=250;
                        power.sugar=true;
                        power.neve="Laser";
                        poo.push_back(power);
                    }
                }
                e[i]=e[e.size()-1];
                e.pop_back();
                v[j]=v[v.size()-1];
                v.pop_back();
                i--;
                pont++;
            }
        }
    }
    for(int i=0; i<e.size(); i++)
    {
        if( e[i].x>hajo.x-85 && e[i].x<hajo.x+75 && e[i].y>hajo.y-37 && e[i].y<hajo.y+37 )
        {
            gout<<move_to(0,0)<<color(255,0,0)<<box(XX,YY);
            e[i]=e[e.size()-1];
            e.pop_back();
            elet--;
            i--;
            //gout<<move_to(0,0)<<color(255,0,0)<<box(XX,YY);
        }
    }
    for(int i=0; i<poo.size(); i++)
    {
        poo[i].x--;
        if( poo[i].x>hajo.x-85 && poo[i].x<hajo.x+75 && poo[i].y>hajo.y-37 && poo[i].y<hajo.y+37 )
        {
            po=poo[i];
            poo[i]=poo[poo.size()-1];
            poo.pop_back();
            i--;
        }
        else if(poo[i].x<1)
        {
            poo[i]=poo[poo.size()-1];
            poo.pop_back();
            i--;
        }
    }
    for(int i=0; i<poo.size(); i++)
    {
        if(poo[i].celzo==true)
        {
            gout<<color(231,123,45)<<move_to(poo[i].x-5,poo[i].y-5)<<box(10,10);
        }
        else if(poo[i].elet==true)
        {
            gout<<color(231,10,0)<<move_to(poo[i].x-5,poo[i].y-5)<<box(10,10);
        }
        else if(poo[i].sugar==true)
        {
            gout<<color(20,20,240)<<move_to(poo[i].x-5,poo[i].y-5)<<box(10,10);
        }
    }
    for(int i=0; i<e.size(); i++)
    {
        haj.transparent(true);
        gout << stamp(haj,e[i].x-sx,e[i].y-sy);

    }

}
void iglov(kord& hajo, std::vector<kord>& v,std::vector<kord>& e)
{
    for(int i=0; i<e.size(); i++)
    {
        if(rand()%200==5)
        {
            kord a;
            a.x=e[i].x;
            a.y=e[i].y;
            a.s=4;
            v.push_back(a);
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        v[i].x=v[i].x-v[i].s;

        if(v[i].x<8)
        {
            // e.erase(e.begin()+(i-1));
            v[i]=v[v.size()-1];
            v.pop_back();
            i--;
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        if( v[i].x>hajo.x-85 && v[i].x<hajo.x+75 && v[i].y>hajo.y-37 && v[i].y<hajo.y+37 )
        {
            v[i]=v[v.size()-1];
            v.pop_back();
            elet--;
            gout<<move_to(0,0)<<color(255,0,0)<<box(XX,YY);
            i--;
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        frez2(v[i].x,v[i].y);

    }

}
void boslov(kord hajo, std::vector<kord>& v,kord e)
{
    if(rand()%50==1)
    {
        kord a;
        a.x=e.x;
        a.y=e.y;
       //a.s=(hajo.x-e.x)/sqrt(pow((hajo.x-e.x),2)+pow((hajo.y-e.y),2));
       // a.f=(hajo.y-e.y)/sqrt(pow((hajo.y-e.y),2)+pow((hajo.x-e.x),2));
        a.s=(hajo.y-e.y)/sqrt(pow((hajo.y-e.y),2)+pow((hajo.x-e.x),2));
        a.f=(hajo.x-e.x)/sqrt(pow((hajo.x-e.x),2)+pow((hajo.y-e.y),2));
       /* double d = sqrt((hajo.y-a.y)*(hajo.y-a.y)+(hajo.x-a.x)*(hajo.x-a.x))/10;
        a.s = hajo.y-a.y;
        a.f = hajo.x-a.x;*/
       // (e.y-hajo.y)/sqrt(pow((hajo.y-e.y),2)+pow((hajo.x-e.x),2))
        v.push_back(a);
    }
    for(int i=0; i<v.size(); i++)
    {
        v[i].x=v[i].x+v[i].f*2;
        v[i].y=v[i].y+v[i].s*2;
         /*   std::stringstream ss;
    ss<< v[i].s<<" "<< v[i].f;
    std::string s;
    s=ss.str();
    gout<<color(255,255,255)<<move_to(v[i].x,v[i].y+17)<<text(s);*/
     //   gout<<move_to(v[i].x-5,v[i].y-5)<<box(10,10);
   //     frez2(v[i].x,v[i].y);
        if(v[i].x<5 || v[i].x>1275 || v[i].y<5 || v[i].y>715 )
        {
            v[i]=v[v.size()-1];
            v.pop_back();
            i--;

        }
    }

}
void model(const kord& hajo,powerapp& aktive)
{
    int x=hajo.x,y=hajo.y;
    c.transparent(true);
    gout << stamp(c,x-65,y-17);
 /*   std::stringstream ss;
    ss<<x<<" "<<y;
    std::string s;
    s=ss.str();;
    gout<<color(255,255,255)<<move_to(x,y+17)<<text(s);*/
    if(aktive.aktiv==true)
    {
        if(aktive.celzo==true)
        {
            gout<<move_to(x+20,y+10)<<color(0,255,0)<<line(1959-x,0);
        }
        if(aktive.elet==true&& elet<5)
        {
            aktive.aktiv=false;
            elet++;
        }
        aktive.ido--;
        if(aktive.ido<=0)
        {
            aktive.aktiv=aktive.sugar=aktive.elet=false;

        }
    }
}
void csillag(std::vector<kord>& v,int e,int sok,int meret)
{
    while(v.size()<sok)
    {
        kord a;
        a.x=rand()%XX-1;
        a.y=rand()%YY-1;
        a.s=rand()%100;
        a.elet=rand()%meret+1;
        v.push_back(a);
    }
    for(int i=0; i<v.size(); i++)
    {
        v[i].x=v[i].x-e;
        if(v[i].x<0)
        {
            v[i].x=XX-1;
        }
        gout<<move_to(v[i].x,v[i].y)<<color(v[i].s+szin.r,v[i].s+szin.g,v[i].s+szin.b)<<box(v[i].elet,v[i].elet);
    }
}

void hud(powerapp a)
{
    gout<<color(255,20,20)<<move_to(20,30);
    for(int i=0; i<elet; i++)
    {
        gout<<move(10,-10)<<box(10,11);
    }
    gout.load_font("LiberationMono-Regular.ttf", 15);
    gout<<move_to(0,5)<<color(122,215,25)<<text("ELET:");
    std::stringstream ss;
    ss<<pont;
    std::string s;
    ss>>s;
    gout<<color(255,255,255)<<move_to(150,20)<<text(s)<<text(" score");
    gout<<color(255,255,255)<<move_to(240,20)<<text(a.neve)<<text(" Powerapp");

}
void stop(bool& live,kord hajo)
{
    event ev;
    gin.timer(10);
    bool asd=true;
    kord eger;
//    kimp(h);
    gout.showmouse(true);
    while (gin >> ev && asd)
    {

        if(ev.keycode==key_escape)
        {
            asd=false;
        }
        if(ev.type==ev_timer)
        {
            if(eger.x>=980 && eger.x<=1280 && eger.y>=320 && eger.y<=420)
            {
                gout<<move_to(980,320)<<color(123,215,248)<<box(200,100)<<move_to(984,324)<<color(42,60,61)<<box(196,96);
            }
            else
            {
                gout<<move_to(980,320)<<color(42,60,61)<<box(200,100);
            }
            if(eger.x>=980 && eger.x<=1280 && eger.y>=430 && eger.y<=530)
            {
                gout<<move_to(980,430)<<color(250,45,4)<<box(200,100)<<move_to(984,434)<<color(42,60,61)<<box(196,96);
            }
            else
            {
                gout<<move_to(980,430)<<color(42,60,61)<<box(200,100);
            }
            gout.load_font("LiberationMono-Regular.ttf", 30);
            gout<<color(255,255,255)<<move_to(984,350)<<text("Continue");
            gout<<color(255,255,255)<<move_to(1000,470)<<text("Exit");
            gout<<refresh;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(ev.type==ev_mouse)
        {
            eger.x=ev.pos_x;
            eger.y=ev.pos_y;
            if(ev.button>0 && eger.x>=980 && eger.x<=1280 && eger.y>=320 && eger.y<=420)
            {
                std::cout<<"zöld"<<std::endl;
                asd=false;
                //live=false;
                // gout.showmouse(false);
                gout.movemouse(hajo.x, hajo.y);
                //gout.showmouse(false);
                // pont=0;
                // elet=5;
                // gout.movemouse(100, 360);
//                start(h);
                asd=false;
            }
            if(ev.button>0 && eger.x>=980 && eger.x<=1280 && eger.y>=430 && eger.y<=530)
            {
                std::cout<<"piros"<<std::endl;
                bezar=false;
                asd=false;
                live=false;
                gout.movemouse(100,360);
            }
        }
    }
}
void ildegen(kord& hajo, std::vector<kord>& v,kord& e,int sx,int sy,canvas haj,int mehet,std::vector<kord>& ammo2)
{
  /*  std::stringstream ss;
    ss<<mehet;
    std::string s;
    ss>>s;
    gout<<color(255,255,255)<<move_to(200,100)<<text(s);*/
    if(N.ll && mehet==0)
    {
        sx=sx/2;
        sy=sy/2;
        if(e.x>=800 || e.elet<=0 )
        {
            e.x=e.x-2;
        }
        if(hajo.y<e.y && e.y<480)
        {
            e.y=e.y+1;
        }else if(hajo.y>e.y && e.y>220)
        {
            e.y=e.y-1;
        }
        for(int j=0; j<v.size(); j++)
        {
            //  std::cout<<e[i].x<<std::endl;
            if(e.x>v[j].x-(sx+5)&&e.x<v[j].x+(sx+5)&&e.y-(sy+5)<v[j].y&&e.y+(sy+7)>v[j].y )
            {
                v[j]=v[v.size()-1];
                v.pop_back();
                j--;
                e.elet--;
                pont=pont+10;
            }
        }
        boslov(hajo,ammo2,e);
        haj.transparent(true);
        gout << stamp(haj,e.x-sx,e.y-sy);
        gout<<move_to(e.x,e.y-sy-10)<<color(0,255,20)<<line(e.elet,0);
        if(e.elet<=0)
        {
            gout<<move_to(e.x-sx+rand()%(sx),e.y-sy+rand()%(sy))<<color(100,100,250)<<box(rand()%20+1,rand()%20+1);
        }
    }
}
void hard(kord il)
{
    if(pont<50)
    {
        N.tt=true;
        szin.r=0;
        szin.g=40;
        szin.b=100;
        szin2.r=0;
        szin2.g=8;
        szin2.b=20;
    }
    if(pont>50)
    {
        N.gg=true;
        szin.r=0;
        szin.g=100;
        szin.b=0;
        szin2.r=0;
        szin2.g=20;
        szin2.b=0;
    }
    if(pont>100)
    {
        N.t=20;
        N.gg=true;
        szin.r=30;
        szin.g=0;
        szin.b=120;
        szin2.r=5;
        szin2.g=5;
        szin2.b=20;
    }
    if(pont>150)
    {
        N.t=30;
        N.g=10;
        N.gg=true;
        szin.r=155;
        szin.g=155;
        szin.b=20;
        szin2.r=10;
        szin2.g=10;
        szin2.b=1;
    }
    if(pont>250)
    {
        N.gg=true;
        szin.r=120;
        szin.g=10;
        szin.b=10;
        szin2.r=20;
        szin2.g=2;
        szin2.b=3;
        N.ll=true;
        N.gg=false;
        N.tt=false;
    }
    if(il.elet<50)
    {
        N.tt=true;
        N.t=5;
    }

}
void start(kep& h)
{
    gout.showmouse(false);
    event ev;
    gin.timer(10);
    kord hajo;
    std::vector<kord> ammo;
    std::vector<kord> it;
    std::vector<kord> ig;
    std::vector<kord> ammo2;
    std::vector<kord> csill;
    std::vector<kord> csill2;
    std::vector<powerapp> power;
    powerapp aktive;
    kord il;
    il.elet=100;
    il.x=1474;
    il.y=430;
    int a=elet;
    // std::vector<kord> il;
    bool live=true;
    while(gin >> ev && live)
    {
        if(ev.type==ev_timer)
        {
            gout<<color(szin2.r,szin2.g,szin2.b)<<move_to(0,0)<<box(XX,YY);
            hard(il);
            csillag(csill,1,1000,3);
            shoot2(ammo);
            model(hajo,aktive);
            idegen(hajo,ammo,it,N.t,N.tt,60,20,t,5,power,aktive,1);
            idegen(hajo,ammo,ig,N.g,N.gg,60,40,g,1,power,aktive,2);
            //  rob(robbanas);
            iglov(hajo,ammo2,ig);
            ildegen(hajo,ammo,il,390,102,l,(ig.size()),ammo2);
            csillag(csill2,10,100,1);
            hud(aktive);
            gout<<refresh;

        }
        else if(ev.type==ev_mouse)
        {
            hajo.x=ev.pos_x;
            hajo.y=ev.pos_y;
            if(hajo.x<64)
            {
               hajo.x=64;
                //gout.movemouse(16,ev.pos_y);
            }else if(hajo.x>1263)
            {
                hajo.x=1263;
               // gout.movemouse(1263,ev.pos_y);
            }
            if(hajo.y<16)
            {
                hajo.y=16;
               // gout.movemouse(ev.pos_x,64);
            }else if(hajo.y>705)
            {
                hajo.y=705;
                //gout.movemouse(ev.pos_x,654);
            }
            shoot1(ammo,ev,aktive.sugar);
        }
        else if(ev.keycode==key_escape)
        {
            // live=false;
            // kimp(h);
            gout.showmouse(true);
            stop(live,hajo);
            gout.showmouse(false);
        }
        if(elet<1)
        {
            live=false;
            gout<<color(0,0,0)<<move_to(0,0)<<box(XX,YY);
            model(hajo,aktive);
            gout.showmouse(true);
            gout.load_font("LiberationMono-Regular.ttf", 50);
            gout<<color(255,10,10)<<move_to(XX/2-150,YY/2)<<text("Game Over");
            std::stringstream ss;
            ss<<pont<<" :score";
            std::string s;
            s=ss.str();
            gout<<color(255,255,255)<<move_to(XX/2-150,YY/2+52)<<text(s);

        }
                    if(il.elet<=0 && il.x<-20)
            {
                live=false;
            }
    }
    if(il.elet<=0 && il.x<-20 )
            {
                gout<<color(0,0,0)<<move_to(0,0)<<box(XX,YY);
                kimp(h);
                gout.load_font("LiberationMono-Regular.ttf", 50);
                gout<<color(255,255,255)<<move_to(XX/2-100,YY/2)<<text("WIN");
    std::stringstream ss;
    ss<<pont<<" :score";
    std::string s;
    s=ss.str();
    gout<<color(255,255,255)<<move_to(XX/2-100,YY/2+52)<<text(s);
                gout.showmouse(true);
            }
    std::cout<<pont<<std::endl;
}
void menu(kep& h)
{

    event ev;
    gin.timer(30);
    kord eger;
    kimp(h);
    gout.showmouse(true);
    while (gin >> ev && bezar)
    {

        if(ev.keycode==key_escape)
        {
            bezar=false;
        }
        if(ev.type==ev_timer)
        {
            if(eger.x>=980 && eger.x<=1280 && eger.y>=320 && eger.y<=420)
            {
                gout<<move_to(980,320)<<color(123,215,248)<<box(200,100)<<move_to(984,324)<<color(42,60,61)<<box(196,96);
            }
            else
            {
                gout<<move_to(980,320)<<color(42,60,61)<<box(200,100);
            }
            if(eger.x>=980 && eger.x<=1280 && eger.y>=430 && eger.y<=530)
            {
                gout<<move_to(980,430)<<color(250,45,4)<<box(200,100)<<move_to(984,434)<<color(42,60,61)<<box(196,96);
            }
            else
            {
                gout<<move_to(980,430)<<color(42,60,61)<<box(200,100);
            }
            gout.load_font("LiberationMono-Regular.ttf", 30);
            gout<<color(255,255,255)<<move_to(984,350)<<text("New Game");
            gout<<color(255,255,255)<<move_to(1000,470)<<text("Exit");
            gout<<refresh;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(ev.type==ev_mouse)
        {
            eger.x=ev.pos_x;
            eger.y=ev.pos_y;
            if(ev.button>0 && eger.x>=980 && eger.x<=1280 && eger.y>=320 && eger.y<=420)
            {
                std::cout<<"zöld"<<std::endl;
                pont=0;
                elet=5;
                N.tt=true;
                N.gg=false;
                N.ll=false;
                N.t=10;
                N.g=5;
                gout.movemouse(100, 360);
                start(h);
            }
            if(ev.button>0 && eger.x>=980 && eger.x<=1280 && eger.y>=430 && eger.y<=530)
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
    srand(time(0));
    gout.load_font("LiberationMono-Regular.ttf", 30);
    kep k,h,tt,gg,ff,ll;
    beolvas(k,"hajo.kep");
    beolvas(h,"hatter.kep");
    beolvas(tt,"it.kep");
    beolvas(ff,"FLASH.kep");
    beolvas(gg,"gg.kep");
    beolvas(ll,"ll.kep");
    c.open(k.x,k.y);
    l.open(ll.x,ll.y);
    g.open(gg.x,gg.y);
    t.open(tt.x,tt.y);
    Flash.open(ff.x,ff.y);
    komp(k,c);
    komp(ll,l);
    komp(ff,Flash);
    komp(gg,g);
    komp(tt,t);
    while (bezar)
    {
        menu(h);
    }
    return 0;
}

