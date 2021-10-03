    #include "graphics.hpp"
    #include <vector>
    #include "ablak.hpp"
    using namespace std;
    using namespace genv;
    int X=800,Y=500;
void ablak::esemeny_hurok()
{
    gout.open(X,Y);
    event ev;
    gin.timer(15);
    while(gin >> ev) {
///*************megjelenítés***látható rész************************
        if(ev.type==ev_timer)
        {
            gout<<move_to(0,0)<<color(0,0,0)<<box(X,Y);
            for(int i=0;i<eszkozok.size();i++)
            {
eszkozok[i]->rajzol();
            }
            gout<<refresh;
        }
///***************mozdulások****nem látható rész*******************
        if(ev.type!=ev_timer)
        {
            for(int i=0;i<eszkozok.size();i++)
            {
eszkozok[i]->scope(ev);
eszkozok[i]->csinalom(ev);
            }
        }

    }
}
