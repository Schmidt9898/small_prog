#include "graphics.hpp"
#include <sstream>
#include <cmath>
#include <vector>

using namespace genv;

# define PI           3.14159265358979323846

void forgatas(int fok, std::vector<float> & koord)
{
    std::vector<float> koordi;
    koordi.push_back(cos(fok * PI / 180) * koord[0] - sin(fok * PI / 180) * koord[1]);
    koordi.push_back(sin(fok * PI / 180) * koord[0] + cos(fok * PI / 180) * koord[1]);

    koord = koordi;
}

int main()
{
    event ev;

    gout.open(500,500);

    std::vector<float> koord(2,0);
    int j = 0;
    gin.timer(33);
    while(gin >> ev && !ev.button)
    {
        if(ev.type == ev_timer)
        {


        j++;
        for(int i = 0; i < 25; i++)
        {
            gout << color(102,204,0);

            koord[0] = i * 10;
            koord[1] = 0;
            forgatas(270 + j, koord);
            gout << move_to(250,250);
            gout << move( koord[0], koord[1]);

            koord[0] = -i * 10;
            koord[1] = 250- i * 10;
            forgatas(270 + j , koord);
            gout << line( koord[0], koord[1]);
        }
        for(int i = 0; i < 25; i++)
        {
            gout << color(51,51,255);

            koord[0] = i * 10;
            koord[1] = 0;
            forgatas(0 + j, koord);
            gout << move_to(250,250);
            gout << move( koord[0], koord[1]);

            koord[0] = -i * 10;
            koord[1] = 250- i * 10;
            forgatas(0 + j, koord);
            gout << line( koord[0], koord[1]);
        }
        for(int i = 0; i < 25; i++)
        {
            gout << color(102,204,0);

            koord[0] = i * 10;
            koord[1] = 0;
            forgatas(90 + j, koord);
            gout << move_to(250,250);
            gout << move( koord[0], koord[1]);

            koord[0] = -i * 10;
            koord[1] = 250- i * 10;
            forgatas(90 + j, koord);
            gout << line( koord[0], koord[1]);
        }
        for(int i = 0; i < 25; i++)
        {
            gout << color(51,51,255);

            koord[0] = i * 10;
            koord[1] = 0;
            forgatas(180 + j, koord);
            gout << move_to(250,250);
            gout << move( koord[0], koord[1]);

            koord[0] = -i * 10;
            koord[1] = 250- i * 10;
            forgatas(180 + j, koord);
            gout << line( koord[0], koord[1]);
        }
        gout << refresh;
        gout << color(0,0,0) << move_to(1,1) << box_to(499,499);
        }
    }

    return 0;
}
