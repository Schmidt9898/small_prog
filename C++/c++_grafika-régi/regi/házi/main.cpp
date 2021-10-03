#include "graphics.hpp"
using namespace genv;
int XX=400;
int YY=400;

int main()
{
    gout.open(XX,YY);
   //gout <<text("hello world")<< refresh;
   int x,y,fx,fy,r,g,b;
   fx=4;
   fy=4;
   r=0;
   g=0;
   b=0;

    event ev;
    while(gin >> ev && ev.keycode!=key_escape) {

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
     gout<<move_to(0,199)<<line_to(399,199)<<move_to(199,0)<<line_to(199,399)<<refresh;
     x=0;
   y=199;
   while(x<200)
   {
    gout<<move_to(x,199)<<line_to(199,y)<<refresh;
    x=x+fx;
    y=y+fy;
   }
    x=0;
    y=199;
      while(x<200)
   {
    gout<<move_to(x,199)<<line_to(199,y)<<refresh;
    x=x+fx;
    y=y-fy;
   }
    x=199;
    y=399;
      while(x<400)
   {
    gout<<move_to(x,199)<<line_to(199,y)<<refresh;
    x=x+fx;
    y=y-fy;
   }
    x=199;
    y=0;
      while(x<400)
   {
    gout<<move_to(x,199)<<line_to(199,y)<<refresh;
    x=x+fx;
    y=y+fy;
   }
    }
    return 0;
}
