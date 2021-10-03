

#include "graphics.hpp"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace genv;
using namespace std;

const unsigned int X = 500;
const unsigned int Y = 500;

struct particle {
    particle *kovetem = 0;
    particle *engemKovet = 0;
    bool vege = true;
    float x,y;
    char r,g,b;
    particle()
    {
        x = rand() % X;
        y = rand() % Y;
        r = rand() % 256;
        g = rand() % 256;
        b = rand() % 256;
    }
    particle(int x0, int y0)
    {
        x = x0;
        y = y0;
        r = rand() % 256;
        g = rand() % 256;
        b = rand() % 256;
    }
    void rajzol()
    {
        gout << color(r,g,b) << move_to(x,y) << box (3,3);
    }
    void kovet()
    {
        if (kovetem)
        {
            float tempX, tempY;
            tempX = (kovetem->x - x) / sqrt(pow(kovetem->x - x,2) + pow(kovetem->y - y,2));
            tempY = (kovetem->y - y) / sqrt(pow(kovetem->x - x,2) + pow(kovetem->y - y,2));
            x += tempX;
            y += tempY;
            rajzol();
        }
    }
};

int main ()
{
    gout.open(X,Y);

    srand (time(NULL));

    particle* v0 = new particle;
    particle* temp = v0;

    for (unsigned int i = 0; i < 10000; i++)
    {
        temp->kovetem = new particle;
        temp->vege = false;
        temp->kovetem->engemKovet = temp;
        temp = temp->kovetem;
    }
    temp->kovetem = v0;
    v0->engemKovet = temp;

    event ev;
    gin.timer(10);
    while (gin >> ev && ev.keycode != key_escape)
    {
        if (ev.type == ev_timer)
        {
            gout << color(0,0,0) << move_to(0,0) << box(X,Y);
            temp = v0;
            while (!temp->vege)
            {
                    temp->kovet();
                    temp = temp->kovetem;
            }
            temp->kovet();
            gout << refresh;
        }
        //
        else if (ev.type == ev_mouse && ev.button == btn_left)
        {
            temp = v0->engemKovet;
            temp->kovetem = new particle(ev.pos_x, ev.pos_y);
            temp->vege = false;
            temp->kovetem->engemKovet = temp;
            temp->kovetem->kovetem = v0;
            v0->engemKovet = temp->kovetem;
        }
        else if (ev.type == ev_mouse && ev.button == btn_right)
        {
            float tav = sqrt(pow(v0->x - ev.pos_x,2) + pow(v0->y - ev.pos_y,2));
            particle* legnagyobb = v0;
            temp = v0->kovetem;
            while (!temp->vege)
            {
                if (tav > sqrt(pow(temp->x - ev.pos_x,2) + pow(temp->y - ev.pos_y,2)))
                {
                    tav = sqrt(pow(temp->x - ev.pos_x,2) + pow(temp->y - ev.pos_y,2));
                    legnagyobb = temp;
                }
                temp = temp->kovetem;
            }
            if (tav > sqrt(pow(temp->x - ev.pos_x,2) + pow(temp->y - ev.pos_y,2)))
            {
                tav = sqrt(pow(temp->x - ev.pos_x,2)* + pow(temp->y - ev.pos_y,2));
                legnagyobb = temp;
            }
            legnagyobb->engemKovet->kovetem = legnagyobb->kovetem;
            legnagyobb->kovetem->engemKovet = legnagyobb->engemKovet;
            if (legnagyobb == v0) v0 = legnagyobb->kovetem;
            if (legnagyobb->kovetem == v0) legnagyobb->engemKovet->vege = true;
            delete legnagyobb;
        }

    }

    gout << refresh;
    return 0;
}

