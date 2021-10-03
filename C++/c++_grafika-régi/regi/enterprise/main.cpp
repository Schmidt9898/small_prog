#include "graphics.hpp"
using namespace genv;


int main()
{
    gout.open(1920,1080,true);
    event ev;
    while(gin >> ev && ev.keycode!=key_escape) {
        gout<<color(0,0,0)<<move_to(0,0)<<box(1920,1080)<<color(255,255,255);
        gout<<move_to(ev.pos_x,ev.pos_y);
        gout<<move(22,5)<<color(50,183,255)<<box(5,-20)<<move_to(ev.pos_x+14,ev.pos_y-12)<<box(20,15)<<move_to(ev.pos_x+14,ev.pos_y-12)<<color(248,234,251)<<box(20,15)<<move_to(ev.pos_x,ev.pos_y)<<color(218,198,210)<<box(45,-10);
    for(int i=0;i<10;i++)
    {
        gout<<move_to(ev.pos_x+i,ev.pos_y)<<line(-30,15);
    }
    gout <<move(10,0)<<box(-40,10);
    gout <<move(43,-10);
    for (int i=-5;i<5;i++)
    {
        gout<<color(160,176,209)<<move_to(ev.pos_x-9,ev.pos_y+19)<<line(3,i);
    }

        for(int i=0;i<5;i++)
    {
        gout<<move_to(ev.pos_x-40-i,ev.pos_y+2)<<line(+3,15);
    }
        gout<<color(222,207,226)<<move_to(ev.pos_x-30,ev.pos_y-10)<<box(-55,14);

  gout << refresh;

    }
    return 0;
}
