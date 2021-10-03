

#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "komplex.hpp"
#include <thread>
using namespace genv;
using namespace std;

const int XX=800;
const int YY=500;
int kep=1;
 int MAX = 255;

int main()
{
     double nagy=4.0;
    double fagy=4.0;
    double tolx=0;
     double toly=0;
    gout.open(XX,YY);
    bool most=true;
    event ev;
    double s,center;
    vector<thread*>threads(XX,0);
    while(gin >> ev && ev.keycode != key_escape)
    {
        if(most)
        {
            for (int x=0; x<XX; x++)
            {
                threads[x]=new thread(
                                      [x,nagy,tolx,toly,fagy](){
                for (int y=0; y<YY; y++)
                {
                    double cr = (nagy/ double(XX))*x - nagy/2-tolx;
                    double ci = (nagy/ double(YY))*y - nagy/2-toly;
                    komplex c(cr, ci);
                    komplex z(0,0);
                    int t = 0;
                    int u = 0;
                    int o = 0;
                    while (z.re()*z.re()+z.im()*z.im() < fagy && t < MAX)
                    {
                        z = z*z+c;
                        ++t;
                    }
                    u=t+1;
                    o=t-1;
                    t=t;
                    gout << move_to(x,y) << color(t%50,o%15,u%255) << dot;
                }
                });
            }
            for(thread* t:threads)
            {
                t->join();
                delete t;
            }
            most=false;
            gout << refresh;

        }
        if(ev.button==btn_left)
        {
            nagy=nagy/2;
tolx+=(XX/2-ev.pos_x)*(nagy/ double (XX));
toly+=(YY/2-ev.pos_y)*(nagy/ double (YY));
            most=true;
        }
                if(ev.keycode==key_enter)
        {
            nagy=4;
            most=true;
            tolx=toly=0;
        }
        if(ev.keycode==key_backspace)
        {
            MAX=MAX*2;
            cout<<MAX<<endl;
            most=true;
        }
                if(ev.keycode==115)
        {
            stringstream ss;
            string s;
            ss<<kep;
            s=ss.str();
           gout.save(s);
           kep++;
           cout<<"mentve"<<kep<<endl;
        }
    }
    ///egervolt+=(xx/2-ex)*(zoom*2/double x)
    return 0;
}

