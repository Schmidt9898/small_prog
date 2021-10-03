#ifndef ESZKOZ_HPP_INCLUDED
#define ESZKOZ_HPP_INCLUDED
#include <iostream>
 #include "graphics.hpp"
class eszkoz
{
    protected:
    int x,y,mx,my;
    bool focus=0;
    public:
    eszkoz(int xx,int yy,int mxx,int myy);
    void scope(genv::event ev);
    virtual void rajzol()=0;
    virtual void csinalom(genv::event& ev)=0;
};


#endif // ESZKOZ_HPP_INCLUDED
