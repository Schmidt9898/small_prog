#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED
#include "valt.hpp"
using namespace genv;
using namespace std;
class WIDGET
{
    protected:
    int x,y,mx,my;
    bool aktive=false;
    public:
        WIDGET(int xx,int yy,int mxx,int myy);
        ~WIDGET();
        virtual void rajzol()=0;
        virtual void doit(event e)=0;
        bool aktivitas(event e);
        void set_aktive(bool a);
};
struct add_gomb : public WIDGET
{
    bool most=false;
    string szoveg=" ";
    vector<char> betuk;
    vector<valt*>* v;
    add_gomb(int xx,int yy,int mxx,int myy,vector<valt*>* vv): WIDGET(xx,yy,mxx,myy)
    {
        cout<<"add_gomb"<<endl;
        v=vv;
    }
    void rajzol();
    void doit(event e);
};
struct torol_gomb: public WIDGET
{

    bool most=false;
    string szoveg=" ";
    vector<char> betuk;
    vector<valt*>* v;
    torol_gomb(int xx,int yy,int mxx,int myy,vector<valt*>* vv): WIDGET(xx,yy,mxx,myy)
    {
        cout<<"torol_gomb"<<endl;
        v=vv;
    }
    void rajzol();
    void doit(event e);
};






#endif // WIDGET_H_INCLUDED
