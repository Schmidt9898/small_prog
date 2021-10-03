#include "graphics.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace genv;
using namespace std;
int X=500,Y=500;
bool buli=0;

struct Widget
{
    int x,y;
    int mx,my;
    bool active=0;
    Widget(int xx,int yy,int mxx,int myy)
    {
        x=xx;
        y=yy;
        mx=mxx;
        my=myy;
        cout<<"letrejott a ";
    }
    void aktival(event& e)
    {
        if(e.pos_x>=x && x+mx>=e.pos_x && e.pos_y>=y && y+my>=e.pos_y)
        {
            active=true;
            cout<<"YEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEAAAAAH"<<endl;
        }
    }
    virtual void rajzol()=0;
};
struct textbox : Widget
{
    string szoveg;
    vector<char> betuk;
    textbox(int xx,int yy,int mxx,int myy):Widget(xx,yy,mxx,myy)
    {
        cout<<"szovegdoboz"<<endl;
    }
    void rajzol()
    {
        gout<<move_to(x,y)<<color(255,255,255)<<box(mx,my);
        gout<<move_to(x,y+my/2)<<color(255,0,0)<<text(szoveg);
    }
    void szov(event e)
    {
        if(active){
        if(e.keycode>=32&&e.keycode<=164&& gout.twidth(szoveg)<mx){
        cout<<(char) e.keycode;
        betuk.push_back((char) e.keycode);
        }
        szoveg="";
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
int main()
{
    gout.open(X,Y);
    event ev;
    gin.timer(15);
    textbox A(100,100,200,50);
    while(gin >> ev && ev.keycode!=key_escape)
    {
        if(ev.type=ev_timer)
        {
            ///rajzolás
            A.rajzol();
            gout<<refresh;
        }
        if(ev.button>0)
        {
            A.aktival(ev);
            A.szov(ev);
        }
        if(ev.keycode>0)
        {
            A.szov(ev);
        }


    }
    return 0;
}
