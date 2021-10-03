#include "josagok.h"
#include <vector>
#include "eszkoz.hpp"
#include <iostream>
#include "graphics.hpp"

using namespace std;
using namespace genv;




void szovegdoboz::rajzol()
    {
        if(aktiv){gout<<move_to(x-2,y-2)<<color(255,255,255)<<box(mx+4,my+4);}
        gout<<move_to(x,y)<<color(10,10,100)<<box(mx,my);
        gout<<move_to(x,y+my/2)<<color(255,255,255)<<text(szoveg);
    }


void szovegdoboz::csinalom(event& ev)
    {
        if(focus&&ev.button>0&&ev.button==btn_left){aktiv=1;}
        if((!focus)&&ev.button>0&&ev.button==btn_left){aktiv=0;}

    if(aktiv)
    {
        if(ev.keycode>=32&&ev.keycode<=255&& gout.twidth(szoveg)<mx)
        {
            cout<<(char) ev.keycode;
            betuk.push_back((char) ev.keycode);
        }
        szoveg="";
        if(ev.keycode==key_backspace&& betuk.size()>=1)
        {
            betuk.pop_back();
        }

        for(int i=0; i<betuk.size(); i++)
        {
            szoveg=szoveg+betuk[i];
        }
    }

    }
