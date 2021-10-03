/*#include "graphics.hpp"
#include <vector>
#include <random>
#include <time.h>
#include <iostream>
using namespace genv;
using namespace std;
struct pixel
{
private:
    float x,y;
   // int r,g,b;
public:
   void draw()
   {
       gout<<move_to(x,y)<<color(x,y,0)<<dot;
   }
   void feltolt(int rr,int gg,int bb)
   {
       r=rr;
       g
   }
   void xy (float xx,float yy)
   {
       x=xx;
       y=yy;
   }
   void follow(pixel* a)
   {
       cout<<a->x<<endl;
   }
};

struct valami
{
private:
    int x,y;
public:
    void P(int a,int b)
    {
        x=a;
        y=b;
    }
    void t()
    {
        cout<<x<<" :v.x "<<y<<" :v.y"<<endl;
    }
};
int main()
{
    gout.open(400,400);
    event ev;
    srand(time(0));
   // std::vector<pixel*> v;
   pixel v[1000];
   cout<<"1."<<endl;
    for(int i=0;i<1000;i++)
    {
        v[i].xy(rand()%400,rand()%400);
    }
    cout<<"2."<<endl;
    while(gin >> ev) {
            for(int i=0;i<1000;i++)
    {
        v[i].follow(&v[i]);
        v[i].draw();
    }
    gout<<refresh;

    }
    valami c;
    c.P(1,2);
    c.t();
    int a=6;
    int* b;
    cout<<a<<" :a "<<b<<" :b"<<endl;
    cout<<&a<<" :&a "<<*b<<" :*b"<<endl;
    cout<<a+1<<" :a+1 "<<*(b+1)<<" :*(b+1)"<<endl;
    cout<<*(&a+1)<<" :*(&a+1) "<<endl;
    cout<<"b=&a"<<endl;
    b=&a;
    cout<<*b<<" :*b "<<b<<" :b"<<endl;



    return 0;
}
*/
#include "graphics.hpp"
#include <vector>
#include <random>
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace genv;
using namespace std;
struct kord
{
private:
    int x,y;
public:
    void tolt(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
    void rajz(std::vector<kord*> v)
    {
        for(int i=0; i<v.size(); i++)
        {
            gout<<color(i%156+50,i%200,i%170)<<move_to(v[i]->x,v[i]->y)<<box(1,1);
        }

    }
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
    void valt(vector<kord*> v)
    {

        for(int i=0; i<=v.size(); i++)
        {
            if(i==v.size())
            {
                 cout<<v[i]->x<<" :1"<<endl;
                v[i]->x=v[i]->x+v[i]->szam(v[i]->x,v[0]->x);
                v[i]->y=v[i]->y+v[i]->szam(v[i]->y,v[0]->y);
                cout<<v[i]->x<<" :2"<<endl;
            }
            else
            {
                cout<<v[i]->x<<" :1"<<endl;
                v[i]->x=v[i]->x+v[i]->szam(v[i]->x,v[i+1]->x);
                v[i]->y=v[i]->y+v[i]->szam(v[i]->y,v[i+1]->y);
                cout<<v[i]->x<<" :2"<<endl;
            }
        }
    }
};


/*void valt(std::vector<kord>& v)
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
*/

int main()
{
    gout.open(400,400);
    srand(time(0));
    event ev;
    vector<kord*> v;
    cout<<"1."<<endl;
    for(int i=0; i<10000; i++)
    {
        kord* a=new kord;
        // cout<<"2."<<endl;
        a->tolt(rand()%400,rand()%400);
        //cout<<"3."<<endl;
        v.push_back(a);
        // cout<<"4."<<endl;
    }
    cout<<"5."<<endl;
    gin.timer(1);
    kord b;
    while(gin >> ev)
    {
        if(ev.type==ev_timer)
        {
            gout<<move_to(0,0)<<color(0,0,0)<<box(400,400);
            v[0]->rajz(v);
            cout<<"6."<<endl;
            v[0]->valt(v);
            cout<<"7."<<endl;
            gout<<refresh;
        }
    }
    return 0;
}
