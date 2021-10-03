#ifndef ESZKOZ_HPP_INCLUDED
#define ESZKOZ_HPP_INCLUDED
#include "graphics.hpp"


class eszkoz
{
protected:
    int x,y,mx,my;
public:
    eszkoz(int xx,int yy, int mxx, int myy)
    {
        x=xx;
        y=yy;
        mx=mxx;
        my=myy;
    }
    virtual void rajzol(int p)=0;
    virtual void interakcio(genv::event ev,int& P)=0;
};


#endif // ESZKOZ_HPP_INCLUDED
