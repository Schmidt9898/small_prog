#include "graphics.hpp"
#include <iostream>
#include <vector>

using namespace genv;
using namespace std;
struct kord
{
    float x,y;
    int m=40;
    bool megfogva=false;
    void beletolt(event ev)
    {
        x=ev.pos_x;
        y=ev.pos_y;
    }
    void rajzol()
    {
        if(megfogva)
        {
            gout<<move_to(x-m/2-2,y-m/2-2)<<color(255,255,255)<<box(m+4,m+4);
        }
        gout<<move_to(x-m/2,y-m/2)<<color(0,0,255)<<box(m,m);
    }
    void megfoge(event ev,bool& legfelul)
    {
        if(ev.pos_x>x-m/2 && ev.pos_x<x+m/2 && ev.pos_y>y-m/2 && ev.pos_y<y+m/2 && legfelul)
        {
            //cout<<"megvan"<<endl;
            legfelul=false;
            megfogva=true;
        }
    }
    void valtoz(event ev,kord& eger)
    {
        x=x+(ev.pos_x-eger.x);
        y=y+(ev.pos_y-eger.y);
        eger.x=ev.pos_x;
        eger.y=ev.pos_y;
    }
};
int main()
{
    gout.open(400,400);
    event ev;
    bool legfelul=true;
    gin.timer(10);
    vector<kord> v;
    kord eger;
    while(gin >> ev)
    {
        if(ev.button==btn_left && ev.button>0 && v.size()!=0)
        {
            //cout<<"megvan"<<endl;
            eger.x=ev.pos_x;
            eger.y=ev.pos_y;
            legfelul=true;
            for(int i=v.size()-1; i>=0; i--)
            {
                v[i].megfoge(ev,legfelul);
                // cout<<"megvan"<<endl;
            }
            for(int i=0; i<v.size(); i++)
            {
                v[i].valtoz(ev,eger);
            }
        }
        if(ev.button==btn_left && ev.button<0 && v.size()!=0)
        {
            for(int i=v.size()-1; i>=0; i--)
            {
                v[i].megfogva=false;
            }

        }
        if(ev.button==btn_right && ev.button>0)
        {
            kord a;
            a.beletolt(ev);
            v.push_back(a);
        }
        if(ev.type==ev_timer)
        {
            for(int i=0; i<v.size(); i++)
            {
                v[i].rajzol();
            }
            // cout<<v.size()<<endl;
            gout<<refresh;
        }
    }
    return 0;
}
