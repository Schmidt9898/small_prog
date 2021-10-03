#include "graphics.hpp"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace genv;
using namespace std;
struct kord
{
    int x,y;
    int M=80;
    bool meg=false;
};
int main()
{
    gout.open(500,500);
    gout.load_font("LiberationSans-Regular.ttf", 30);
    event ev;
    gin.timer(15);
    bool elso=true;
    bool lent=false;

    std::vector<kord> v;
    kord eger;
    while(gin >> ev&& ev.keycode!=key_escape)
    {
        if(ev.button==btn_wheelup)
        {
            for(int i=0;i<v.size();i++)
            {
                if(ev.pos_x>v[i].x-v[i].M/2&&ev.pos_x<v[i].x+v[i].M/2&&ev.pos_y>v[i].y-v[i].M/2&&ev.pos_y<v[i].y+v[i].M/2)
                    v[i].M++;
            }

        }else if(ev.button==btn_wheeldown)
        {
            for(int i=0;i<v.size();i++)
            {
                if(ev.pos_x>v[i].x-v[i].M/2&&ev.pos_x<v[i].x+v[i].M/2&&ev.pos_y>v[i].y-v[i].M/2&&ev.pos_y<v[i].y+v[i].M/2)
                    v[i].M--;
            }

        }
        if(ev.button>0 && ev.button==btn_left)
        {
            eger.x=ev.pos_x;
            eger.y=ev.pos_y;
            lent=true;
        }
        if(ev.button<0)
        {
            lent=false;
        }
        if(ev.button>0 && ev.button==btn_right)
        {
            kord a;
            a.x=ev.pos_x;
            a.y=ev.pos_y;
            v.push_back(a);

        }
        if(lent && ev.type==ev_mouse)
        {
            for(int i=v.size()-1; i>=0; i--)
            {
                if(ev.pos_x>v[i].x-v[i].M/2&&ev.pos_x<v[i].x+v[i].M/2&&ev.pos_y>v[i].y-v[i].M/2&&ev.pos_y<v[i].y+v[i].M/2 && elso || v[i].meg)
                {
                    v[i].meg=true;
                    v[i].x=v[i].x+(ev.pos_x-eger.x);
                    v[i].y=v[i].y+(ev.pos_y-eger.y);
                    eger.x=ev.pos_x;
                    eger.y=ev.pos_y;
                    elso=false;
                    if(v[i].x>500-v[i].M/2)
                    {
                        v[i].x=500-v[i].M/2;
                    }
                    else if(v[i].x<v[i].M/2+2)
                    {
                        v[i].x=v[i].M/2+2;
                    }
                    if(v[i].y>500-v[i].M/2)
                    {
                        v[i].y=500-v[i].M/2;
                    }
                    else if(v[i].y<v[i].M/2+2)
                    {
                        v[i].y=v[i].M/2+2;
                    }
                }
            }
        }
        for(int i=v.size()-1; i>=0; i--)
        {
            if (!lent)
            {
                v[i].meg=false;
                elso=true;
            }
        }
        if(ev.type==ev_timer)
        {
            gout<<color(0,0,0)<<move_to(0,0)<<box(500,500);
            for(int i=0; i<v.size(); i++)
            {
                if(v[i].meg)
                {
                    stringstream ss;
                    ss<<v[i].M;
                    string s;
                    ss>>s;
                    gout<<move_to(v[i].x-v[i].M/2-2,v[i].y-v[i].M/2-2)<<color(255,255,255)<<box(v[i].M+4,v[i].M+4)<<move_to(v[i].x-v[i].M/2,v[i].y-v[i].M/2)<<color(0,0,255)<<box(v[i].M,v[i].M);
                    gout<<move_to(v[i].x-v[i].M/2,v[i].y-v[i].M/2)<<color(255,255,255)<<text(s);
                }
                else
                {
                    stringstream ss;
                    ss<<v[i].M;
                    string s;
                    ss>>s;
                    gout<<move_to(v[i].x-v[i].M/2-2,v[i].y-v[i].M/2-2)<<color(0,0,0)<<box(v[i].M+4,v[i].M+4)<<move_to(v[i].x-v[i].M/2,v[i].y-v[i].M/2)<<color(0,0,255)<<box(v[i].M,v[i].M);
                    gout<<move_to(v[i].x-v[i].M/2,v[i].y-v[i].M/2)<<color(255,255,255)<<text(s);
                }
            }
            gout<<refresh;
        }

    }
    return 0;
}
