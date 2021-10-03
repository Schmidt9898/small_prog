#ifndef KOCKA_HPP_INCLUDED
#define KOCKA_HPP_INCLUDED
#include "eszkoz.hpp"
#include <vector>
class kocka: public eszkoz
{
protected:

    int mivagyok=0;/// 0=nem vagyok senkié. 1=player1, 2=player2
    unsigned char r=0,g=0,b=0;
    bool scope=0;
    int elet=0;

public :

    kocka(int xx,int yy,int mxx,int myy):eszkoz(xx,yy,mxx,myy){}

    void rajzol(int p);
    void interakcio(genv::event ev,int& P);
    bool bennevan(genv::event ev);
    void set_mi(int P,int m);
    void set_minusz(int P);
    int get_mi();
};

class tabla: public eszkoz
{
    protected:
    int x,y,mx,my;
    int merete;
    std::vector<std::vector<kocka*>> matrix;
    public:
    tabla(int meret,int xx,int yy,int Y);
    void rajzol(int p);
    void interakcio(genv::event ev,int& P);
    bool joe(genv::event ev,int& P);
    bool ellenoriz(int P);
    void tisztit();
};
struct kord
{
    int x,y;
    kord(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
};

#endif // KOCKA_HPP_INCLUDED
