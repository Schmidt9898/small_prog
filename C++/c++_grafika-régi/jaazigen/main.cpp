#include "graphics.hpp"
#include <iostream>
#include <vector>

using namespace genv;
using namespace std;
int X=800,Y=500;
class WIDGET
{
    protected:
    int x,y,mx,my;
    bool aktive=false;
    public:
        WIDGET(int xx,int yy,int mxx,int myy)
        {
            x=xx;
            y=yy;
            mx=mxx;
            my=myy;
            cout<<"letrejott a ";
        }
        ~WIDGET(){cout<<"kampec";}
        virtual void rajzol()=0;
        virtual void doit(event e)=0;
        bool aktivitas(event e)
        {
            if(e.pos_x>=x&&e.pos_x<=x+mx&&e.pos_y>=y&&e.pos_y<=y+my)
            {
            aktive=true;
            }
            return(aktive);
        }
        void set_aktive(bool a)
        {
            aktive=a;
        }
};
struct add_gomb : public WIDGET
{
    bool most=false;
    string szoveg=" ";
    vector<char> betuk;
    add_gomb(int xx,int yy,int mxx,int myy): WIDGET(xx,yy,mxx,myy)
    {
        cout<<"add_gomb"<<endl;
    }
    void rajzol()
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
    void doit(event e)
    {
           if(e.pos_x>=x&&e.pos_x<=x+mx&&e.pos_y>=y+my/2&&e.pos_y<=y+my&&e.button>0)
            {
            most=true;
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
};
struct tarolo:public WIDGET
{
   // vector<>
        tarolo(int xx,int yy): WIDGET(xx,yy,300,400)
    {
        cout<<"tarolo"<<endl;
    }
        void rajzol()
    {
        if(aktive){
        gout<<move_to(x-2,y-2)<<color(200,200,120)<<box(mx+4,my+4);
        }
        gout<<move_to(x,y)<<color(100,90,120)<<box(mx,my);
        gout<<move_to(x,y)<<color(200,180,240)<<box(mx,my/8);
    }
    void doit(event e){}
};


int main()
{
    gout.open(X,Y);
    event ev;
    tarolo* a=new tarolo(400,10);
    add_gomb* b=new add_gomb(10,10,200,100);
    vector<WIDGET*> v;
    v.push_back(a);
    v.push_back(b);
    gin.timer(15);
    while(gin >> ev&&ev.keycode!=key_escape) {
            if(ev.type==ev_timer){
            gout<<move_to(0,0)<<color(0,0,0)<<box(X,Y);
            for(int i=0;i<v.size();i++)
            {
                v[i]->rajzol();
            }
            gout<<refresh;
    }
    else if(ev.button>0&&ev.button==btn_left)
    {
        bool meg=true;
            for(int i=0;i<v.size();i++)
            {
                v[i]->set_aktive(0);
            }

        for(int i=v.size()-1;i>=0;i--)
        {
            if(v.size()>0  && meg )
            {
meg!=v[i]->aktivitas(ev);
            }
        }
    }
    if(ev.time!=ev_timer)
    {
        for(int i=0;i<v.size();i++)
            {
                v[i]->doit(ev);
            }
    }

    }
    return 0;
}
