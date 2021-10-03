#include "graphics.hpp"
#include <random>
#include <time.h>
#include <cmath>
using namespace genv;
int X=500;
int Y=500;

int main()
{
   srand(time(NULL));
    gout.open(X,Y);
    event ev;
    int x,y;
    while(gin >> ev && ev.keycode!=key_escape)
    {
        gout<<color(0,0,0)<<move_to(0,0)<<box(X,Y)<<color(255,255,255);
        x=ev.pos_x;
        y=ev.pos_y;
        for (int i=y;i<X;i++)
        {
        gout<<move_to(x,y)<<box(10,10)<<refresh;
        y++;
        }
    }
    return 0;
}
