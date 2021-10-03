#include "kocka.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>
#include "eszkoz.hpp"
#include "gomb.hpp"
#include <sstream>

//#include "ellenorzo.cpp"

using namespace genv;
using namespace std;
string P_kiir="Kiderul!";
bool nyertes=0;

tabla::tabla(int meret,int xx,int yy,int Y):eszkoz(xx,yy,Y,Y)
{
    x=xx;
    y=yy;
    mx=Y;
    my=Y;
    merete=meret;
    int kocka_merete=(Y-2*meret)/meret;
    int kx=x,ky=y;
    for(int i=0; i<meret; i++)
    {
        std::vector<kocka*> v;
        matrix.push_back(v);
    }
    for(int i=0; i<meret; i++)
    {
        kx=x;
        for(int j=0; j<meret; j++)
        {
            kocka* k=new kocka(kx,ky,kocka_merete,kocka_merete);
            matrix[i].push_back(k);
            kx+=kocka_merete+2;
        }
        ky+=kocka_merete+2;
    }
}
int kocka:: get_mi()
{
    return (mivagyok);
}
void kocka::rajzol(int p)
{
    gout<<move_to(x,y)<<color(r,g,b)<<box(mx,my);
    if(scope){gout<<move_to(x,y)<<color(200,g,b)<<box(mx,my);}
   // gout<<move_to(x,y)<<color(r,g,b)<<box(mx,my);

}
void tabla::rajzol(int p)
{
    gout<<move_to(x,y)<<color(100,100,100)<<box(mx,my);
    if(nyertes)
    {
    std::stringstream ss;
    ss<<"Jatekos "<<p<<" nyert!";
    P_kiir=ss.str();

    }else{P_kiir="Kiderul!";}
gout<<move_to(720,130)<<color(200,200,200)<<box(200,50)
    <<move_to(720,175)<<color(0,0,0)<<text(P_kiir);
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            matrix[i][j]->rajzol(p);
        }
    }
}
void kocka::set_minusz(int P)
{
    if(P==mivagyok)
    {
       elet--;
    }
        if(elet<=0)
        {
            mivagyok=0;
        }
}
void tabla::interakcio(event ev,int& P)
{
     for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            matrix[i][j]->interakcio(ev,P);
        }
    }
    if(ev.button==btn_left&& ev.button>0)
        {
            this->joe(ev,P);
        }

}
void kocka::interakcio(event ev,int& P)
{

    if(ev.pos_x>=x&&ev.pos_x<=x+mx&&ev.pos_y>=y&&ev.pos_y<=y+my)
    {
        scope=1;
    }else if (!(ev.pos_x>=x&&ev.pos_x<=x+mx&&ev.pos_y>=y&&ev.pos_y<=y+my))
    {scope=0;}
    if(mivagyok==0){r=0;g=0;b=0;}
    if(mivagyok==1){r=0;g=255;b=0;}
    if(mivagyok==2){r=0;g=0;b=255;}
}
void valtozik(int& P)
{
vector<int> p (2,1);
p[0]=2;
P=p[P-1];
    //cout<<P;
}
bool tabla::joe(event ev ,int& P)
{
    bool most=0;
for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            if(matrix[i][j]->bennevan(ev)&&!nyertes)
            {
                matrix[i][j]->set_mi(P,merete);
                most=1;
            }
        }
    }
    if(most)
    {
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                matrix[i][j]->set_minusz(P);
            }
        }
    if(this->ellenoriz(P))
    {
        cout<<"nyert";
        nyertes=1;

    }
         valtozik(P);
    }
}
bool kocka::bennevan(event ev)
{
    return (ev.pos_x>=x&&ev.pos_x<=x+mx&&ev.pos_y>=y&&ev.pos_y<=y+my&&mivagyok==0);
}
void kocka::set_mi(int P,int m)
{
    mivagyok=P;
    elet=m+1;
}
///*////////////////////////////////////////////////////////
bool tabla::ellenoriz(int P)
{
    vector<kord> v;
    int db=0;
for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            if(matrix[i][j]->get_mi()==P)
            {
                kord a(i,j);
                v.push_back(a);
            }
        }
    }
    if(v.size()>=merete)
    {
    db=0;
    for(int i=1;i<v.size();i++)
    {
       if(v[0].x==v[i].x)
       {
           db++;
       }
       if(db==merete-1)
       {
           return(true);
       }
      // cout<<egy;
    }
    db=0;
    for(int i=1;i<v.size();i++)
    {
       if(v[0].y==v[i].y)
       {
           db++;
       }
       if(db==merete-1)
       {
           return(true);
       }
    }
    db=0;
    for(int i=1;i<v.size();i++)
    {
       if(v[0].x+v[0].y==v[i].x+v[i].y)
       {
           db++;
       }
       if(db==merete-1)
       {
           return(true);
       }
    }
    db=0;
    for(int i=1;i<v.size();i++)
    {
       if(v[0].x+v[i].y==v[i].x+v[0].y)
       {
           db++;
       }
       if(db==merete-1)
       {
           return(true);
       }
    }


    }
    return(false);
}
void tabla::tisztit()
{
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            matrix[i][j]->set_mi(0,0);
        }
    }
nyertes=0;
}









