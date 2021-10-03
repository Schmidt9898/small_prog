#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"
class widget
{
    protected:
    int x,y,mx,my;
    public:
    widget(int xx,int yy,int mxx,int myy)
    {
        x=xx;
        y=yy;
        mx=mxx;
        my=myy;
    }
    void interakcio(genv::event ev);
    void rajzol();

};


#endif // WIDGET_HPP_INCLUDED
