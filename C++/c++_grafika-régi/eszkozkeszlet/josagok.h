#ifndef JOSAGOK_H_INCLUDED
#define JOSAGOK_H_INCLUDED
#include "eszkoz.hpp"
#include <vector>
#include "eszkoz.hpp"
#include <iostream>
#include <string>

using namespace std;

struct szovegdoboz:public eszkoz
{
    string szoveg;
    bool aktiv=0;
    vector<char> betuk;
    szovegdoboz(int xx,int yy,int mxx,int myy):eszkoz(xx,yy,mxx,myy)
    {
        cout<<"szovegdoboz"<<endl;
    }
    void rajzol();
    void csinalom(genv::event& ev);
};
struct gomb:public eszkoz
{
    string cim;
    gomb(int xx,int yy,int mxx,int myy);
    void rajzol();
    void csinalom(genv::event& ev);
};
struct szamos:public eszkoz
{
    int ertek=0;
    string ertek0="0";
    szamos(int xx,int yy,int mxx,int myy);
    void rajzol();
    void csinalom(genv::event& ev);
};
struct sor
{
    int x,y,mx,my;
    sor(int mxx,int myy);
    bool en=0;
    string nevem="meg_nincs";
    void rajzol(int xx,int yy);
    void csinalom(genv::event& ev);
};
struct lista:public eszkoz
{
    int valasztas=-1;
    vector<sor*> v;
    lista(int xx,int yy,int mxx,int myy);
    void rajzol();
    void csinalom(genv::event& ev);
};


#endif // JOSAGOK_H_INCLUDED
