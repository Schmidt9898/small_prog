#include "graphics.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
using namespace genv;
/*
struct colo
{
    int r,g,b;
};

void beolvas(vector<vector<colo>>& v,string fajlnev)
{
    ifstream f;
    f.open(fajlnev);
    if (!f.good())
    {
        cerr<<"Nem sikerult a "<<fajlnev<<" fajl beolvasasa!!!!"<<endl;
        return;
    }
    int x,y;
    f>>x>>y>>ws;
    v.resize(x);
    for(int i=0; i<v.size(); i++)
    {
        v[i].resize(y);
    }
    for(int i=0; i<v.size() && f.good(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            colo c;
            f>>c.r>>c.g>>c.b;
            v[i][j]=c;
        }
    }
    cout<<"A fajl beolvasasa megtortent"<<endl;
}*/
int main()
{
   /* vector<vector<colo>> v;
    string fajlnev;
    fajlnev="kep.txt";
    beolvas(v,fajlnev);*/
    gout.open(550,343);
    for(int x=0; x<550; x++)
    {
        for(int y=0; y<343; y++)
        {
           // gout<<move_to(x,y)<<color(v[x][y].r,v[x][y].g,v[x][y].b)<<refresh;
           gout<<move_to(x,y)<<color(123,153,42)<<refresh;
        }
    }
    return 0;
}
