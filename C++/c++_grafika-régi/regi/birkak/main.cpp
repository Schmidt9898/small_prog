#include "graphics.hpp"
#include <stdlib.h>
#include <vector>
#include <random>
#include <time.h>
#include <string>
#include <iostream>
#include <cmath>
using namespace genv;
using namespace std;
const int X=500;
const int Y=500;
int darabb=40;
int darabf=10;

struct allatok
{
    double x=rand()%X;
    double y=rand()%Y;
    // double mx=0,my=0;
    string micsoda;
    allatok(string s) : micsoda(s) {}
    virtual void megy(vector<allatok*>& v) =0;
    void rajzol()
    {
        if(micsoda=="roka")
        {
            gout<<color(250,30,30);
        }
        else if(micsoda=="birka")
        {
            gout<<color(250,250,250);
        }
        else
        {
            gout<<color(0,0,255);
        }
        gout<<move_to(x,y)<<box(10,10);
    }
    int legkozelebb(vector<allatok*>& v)
    {
        int hanyadik=-1;
        double messze=X;
        for(int i=0; i<v.size(); i++)
        {
            if(micsoda!=v[i]->micsoda)
            {
                if(messze>sqrt((x-v[i]->x)*(x-v[i]->x)+(y-v[i]->y)*(y-v[i]->y)))
                {
                    messze=sqrt((x-v[i]->x)*(x-v[i]->x)+(y-v[i]->y)*(y-v[i]->y));
                    hanyadik=i;
                    if(messze<5 && micsoda=="roka")
                   {
                       delete v[i];
                       v[i]=v[v.size()-1];
                       v.pop_back();
                       i=0;

                   }
                }
            }
        }
        return(hanyadik);
    }
};

struct birka : allatok
{
    birka() : allatok("birka") {}
    void megy(vector<allatok*>& v)
    {
        int ii=legkozelebb(v);
        if(ii!=-1)
        {
            x+=(x-v[ii]->x)/sqrt((x-v[ii]->x)*(x-v[ii]->x)+(y-v[ii]->y)*(y-v[ii]->y));
            y+=(y-v[ii]->y)/sqrt((x-v[ii]->x)*(x-v[ii]->x)+(y-v[ii]->y)*(y-v[ii]->y));
        }
        if(x>=X-11)
        {
            x=0;
        }
        if(x<=0)
        {
            x=X-11;
        }
        if(y>=Y-11)
        {
            y=0;
        }
        if(y<=0)
        {
            y=Y-11;
        }
    }

};
struct roka : allatok
{
    roka() : allatok("roka") {}
    void megy(vector<allatok*>& v)
    {
        int ii=legkozelebb(v);
        if(ii!=-1)
        {
            x-=((x-v[ii]->x)/sqrt((x-v[ii]->x)*(x-v[ii]->x)+(y-v[ii]->y)*(y-v[ii]->y)))*2;
            y-=((y-v[ii]->y)/sqrt((x-v[ii]->x)*(x-v[ii]->x)+(y-v[ii]->y)*(y-v[ii]->y)))*2;
        }
        if(x>=X-11)
        {
            x=X-11;
        }
        if(x<=0)
        {
            x=0;
        }
        if(y>=Y-11)
        {
            y=Y-11;
        }
        if(y<=0)
        {
            y=0;
        }

    }
};
int main()
{
    gout.open(X,Y);
    srand(time(0));
    gin.timer(15);
    vector<allatok*> allat;
    for(int i=0; i<1000; i++)
    {
        allatok* birkakoma=new birka();
        allat.push_back(birkakoma);
    }
        for(int i=0; i<100; i++)
    {
        allatok* rokakoma=new roka();
        allat.push_back(rokakoma);
    }
    event ev;
    while(gin >> ev)
    {
        if(true)
        {
            gout<<move_to(0,0)<<color(0,0,0)<<box(X,Y);
            for(int i=0; i<allat.size(); i++)
            {
                allat[i]->megy(allat);
                allat[i]->rajzol();
                // cout<<i<<" ";
            }
            //cout<<endl;
            gout<<refresh;
        }
    }
    return 0;
}
