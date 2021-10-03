    #include "graphics.hpp"
    #include "eszkoz.hpp"
    using namespace genv;


eszkoz::eszkoz(int xx,int yy,int mxx,int myy)
        {
            x=xx;
            y=yy;
            mx=mxx;
            my=myy;
            std::cout<<"letrejott a ";
        }
    void eszkoz::scope(event ev)
    {
        if(ev.pos_x>=x&&ev.pos_x<=x+mx&&ev.pos_y>=y&&ev.pos_y<=y+my)
            {focus=1;}
        if(!(ev.pos_x>=x&&ev.pos_x<=x+mx&&ev.pos_y>=y&&ev.pos_y<=y+my))
            {focus=0;}
    }
