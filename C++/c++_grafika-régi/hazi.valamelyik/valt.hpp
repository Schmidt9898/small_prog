#ifndef VALT_HPP_INCLUDED
#define VALT_HPP_INCLUDED
#include "graphics.hpp"
using namespace genv;
using namespace std;
struct valt
{
int x,y,mx,my;
int sorend;
bool annyie=0;
string nev="nincs";
valt(int mxx,int myy);
        ~valt();
        void rajzol(int xx,int yy);
        void doit(genv::event e);
        void set_nem()
        {
            annyie=0;
        }
        bool anny(){return(annyie);}
};


#endif // VALT_HPP_INCLUDED
