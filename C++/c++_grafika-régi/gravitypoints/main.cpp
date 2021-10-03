#include "graphics.hpp"
#include <cstdlib>
#include <vector>
#include <time.h>
#include <random>
#include <iostream>
using namespace genv;
using namespace std;

const int XX = 800;
const int YY = 800;


struct reszecske
{
    int x;
    int y;
    int r,g,b;
    reszecske(int xx, int yy)
    {
        x=xx;
        y=yy;

    }
    float sebx = 0;
    float seby = 0;

    void rajzol()
    {
        gout << color(255,255,255) << move_to(x,y) << dot;
    }

    void mozog(int mx, int my)
    {

        float t= sqrt(((mx-x)*(mx-x))+((my-y)*(my-y)));
        seby += (my-y)/t;
        sebx += (mx-x)/t;
        x += sebx;
        y += seby;
        sebx/=1.02;
        seby/=1.02;
        r=1/t;
        g=t/2;
        b=t*2;

    }
void mozog2(){
        sebx*=2;
        seby*=2;
}

};


int main()
{
    gout.open(XX,YY);
    event ev;
    gin.timer(50);
    srand(time(nullptr));
int ex=XX/2,ey=YY/2;
bool lent=false;
    vector<reszecske> v;
    for( int i=0; i<10000 ; i++)
    {
        reszecske egy(rand()%XX, rand()%YY);
        v.push_back(egy);
    }

    do
    {
        if(ev.type == ev_timer)
            {
               gout << move_to(0,0) << color(0,0,0) << box(XX-1,YY-1);
                for(int i=0;i<v.size();i++)
                    {
                      //  v[i].mozog2();
                        v[i].mozog(ex,ey);
                        if(v[i].x>0 and v[i].x<XX and v[i].y>0 and v[i].y<YY)
                        v[i].rajzol();
                    }
                gout << refresh;
            }
        if( ev.type == ev_mouse and lent)
        {
            ex=ev.pos_x;
            ey=ev.pos_y;
        }
        if(ev.keycode==key_left){
            for(int i=0;i<v.size();i++)
                 v[i].mozog2();
        }

        if(ev.button>0)
            lent=true;
        if(ev.button<0)
            lent=false;

    }while(gin >> ev and ev.keycode != key_escape);

    return 0;
}
