#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct color
{
    int r,g,b;
};

void beolvas(vector<vector<color>>& v,string fajlnev)
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
            color c;
            f>>c.r>>c.g>>c.b;
            v[i][j]=c;
        }
    }
    cout<<"A fajl beolvasasa megtortent"<<endl;
}
void kiir(vector<vector<color>>& v,string fajlnev2)
{
    ofstream f(fajlnev2);
    f << v.size() << " " << v[0].size() << endl;
    for(int i=0; i<v.size(); i++)
    {

        for(int j=0; j<v[i].size(); j++)
        {
            f << v[i][j].r << " " << v[i][j].g << " " << v[i][j].b << "  ";
        }
    }
    f.close();
    cout<<"A fajl kiirasa megtortent"<<endl;
}
void negativ(vector<vector<color>>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            color& c= v[i][j];
            c.r=255-c.r;
            c.g=255-c.g;
            c.b=255-c.b;
        }
    }
    cout<<"A kep negalasa megtortent."<<endl;
}
void szintelen(vector<vector<color>>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            color& c= v[i][j];
            int a;
            a=int(c.r+c.b+c.g)/3;
            c.r=a;
            c.g=a;
            c.b=a;
        }
    }
    cout<<"A kep szintelenitese megtortent."<<endl;
}
int main()
{
    vector<vector<color>> igazi_kep;
    string fajlnev,fajlnev2;
    fajlnev="kep.txt";
    fajlnev2="111.txt";
    beolvas(igazi_kep,fajlnev);
    //negativ(igazi_kep);
    szintelen(igazi_kep);
    kiir(igazi_kep,fajlnev2);

    return 0;
}
