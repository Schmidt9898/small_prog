#include "gomb.hpp"
#include "graphics.hpp"
#include <sstream>
using namespace std;
using namespace genv;

void gomb::rajzol(int p)
{
    gout<<move_to(x,y)<<color(200,200,200)<<box(mx,my)
    <<move_to(x,y+my/2)<<color(0,0,0)<<text(felirat);
}
void gomb::interakcio(genv::event ev,int& P)
{
if(ev.pos_x>=x&&ev.pos_x<=x+mx&&ev.pos_y>=y&&ev.pos_y<=y+my&&ev.button>0)
    {
        ta->tisztit();
    }
}
void gomb2::rajzol(int p)
{
    std::stringstream ss;
    ss<<"Jatekos "<<p;
    felirat=ss.str();
    gout<<move_to(x,y)<<color(200,200,200)<<box(mx,my)
    <<move_to(x,y+my/2)<<color(0,0,0)<<text(felirat);
}
void gomb2::interakcio(genv::event ev,int& P){};
