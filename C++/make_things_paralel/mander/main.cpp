#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "mandelrajz.hpp"
#include "komplex.hpp"
using namespace genv;
using namespace std;

const int XX=600;
const int YY=500;


const int MAX = 500;

int main()
{

    float x=0,y=0;
    double step=0.1;
    double mag=4;
    gout.open(XX,YY);
    //mandelrajz(XX,YY, MAX,x,y);
    //gout << refresh;
    event ev;
    while(gin >> ev ) {
    if(ev.type == ev_mouse)
                continue;

    if(ev.keycode == 79)
    {
            x+=step;
            mandelrajz(XX,YY, MAX,x,y,mag);
    }

    if(ev.keycode==80){

            x-=step;
            mandelrajz(XX,YY, MAX,x,y,mag);
    }

    if(ev.keycode==82){
            y-=step;
            mandelrajz(XX,YY, MAX,x,y,mag);
    }

    if(ev.keycode==81){
            y+=step;
            mandelrajz(XX,YY, MAX,x,y,mag);
    }
    //printf("%d",ev.keycode);
    if(ev.keycode==13){
            mag/=2;
            step/=2;
            mandelrajz(XX,YY, MAX,x,y,mag);
    }



    gout << refresh;
    std::printf("refresh  x:%f\n",x);

    }
    return 0;
}

