#include "graphics.hpp"
using namespace genv;
int XX=1000;
int YY=1000;

int main()
{
    gout.open(XX,YY);
    //gout <<text("hello world")<< refresh;
    int x,y,fx,fy,r,g,b;
    fx=10;
    fy=10;
    r=0;
    g=0;
    b=0;

    event ev;
    while(gin >> ev && ev.keycode!=key_escape)
    {

        //gout<<color(0,0,0)<<move_to(0,0)<<box(400,400)<<refresh;
        gout<<color(ev.pos_x,ev.pos_y,(ev.pos_y+ev.pos_x%256));
        /*   if(ev.keycode==key_up)
           {
            r=r+10;
           }
           if(ev.keycode==key_left)
           {
            g=g+10;
           }
           if(ev.keycode==key_right)
           {
            b=b+10;
           }if(ev.keycode==key_down)
           {
               r=0;
               g=0;
               b=0;
           }
           gout<<color(r,g,b);*/
        gout<<move_to(0,YY/2-1)<<line_to(XX,YY/2-1)<<move_to(XX/2-1,0)<<line_to(XX/2-1,YY-1);
        x=0;
        y=YY/2-1;
        while(x<XX/2)
        {
            gout<<move_to(x,YY/2-1)<<line_to(XX/2-1,y);
            x=x+fx;
            y=y+fy;
        }
        x=0;
        y=YY/2-1;
        while(x<XX/2)
        {
            gout<<move_to(x,YY/2-1)<<line_to(XX/2-1,y);
            x=x+fx;
            y=y-fy;
        }
        x=XX/2-1;
        y=YY-1;
        while(x<XX)
        {
            gout<<move_to(x,YY/2-1)<<line_to(XX/2-1,y);
            x=x+fx;
            y=y-fy;
        }
        x=XX/2-1;
        y=0;
        while(x<XX)
        {
            gout<<move_to(x,YY/2-1)<<line_to(XX/2-1,y);
            x=x+fx;
            y=y+fy;
        }
        gout<<refresh;
    }
    return 0;
}
