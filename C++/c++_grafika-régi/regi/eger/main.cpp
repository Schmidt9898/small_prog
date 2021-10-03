#include "graphics.hpp"
#include <vector>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace genv;
struct kord
{
    int x,y;
};
int main()
{
    gout.open(400,400);
    event ev;
    kord eger;
    int x,y,j;
    gout.showmouse(false);
    gout.load_font("LiberationMono-Regular.ttf", 20);
    while(gin >> ev) {
            x=ev.pos_x;
            y=ev.pos_y;
            j=0;
            gout<<color(0,0,0)<<move_to(0,0)<<box(400,400);

            for(int i=15;i>0;i=i-2){
                gout<<color(20,255-i*20,0)<<move_to(x-8,y-8+j)<<box(10,i);
                   j++;
            }
    gout << refresh;
    }
    return 0;
}
