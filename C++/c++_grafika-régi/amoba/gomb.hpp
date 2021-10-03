#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED
#include <string>
#include "graphics.hpp"
#include "eszkoz.hpp"
#include "kocka.hpp"
class gomb: public eszkoz
{
protected:

    std::string felirat="";
    bool scope=0;
    tabla* ta;
public :
    gomb(int xx,int yy,int mxx,int myy,std::string nev,tabla* te):eszkoz(xx,yy,mxx,myy)
    {
        felirat=nev;
        ta=te;
    }
    void rajzol(int p);
    void interakcio(genv::event ev,int& P);
};

class gomb2: public eszkoz
{
protected:

    std::string felirat="";
    bool scope=0;
public :
    gomb2(int xx,int yy,int mxx,int myy,std::string nev):eszkoz(xx,yy,mxx,myy)
    {
        felirat=nev;
    }
    void rajzol(int p);
    void interakcio(genv::event ev,int& P);
};

#endif // GOMB_HPP_INCLUDED
