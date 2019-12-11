#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
struct repter
{
    string repternev, megyenev, jele;
    int szeles,hosszu,magas;

};
void beolvas(vector<repter>& v)
{
    ifstream f;
    f.open("repterek.txt");
    if(!f.good())
    {
        cerr<<"Nem lehet megnyitni!!!!!"<<endl;
        return;
    }
    repter r;
    char kuka;
    while(!f.eof())
    {
        getline(f,r.repternev,'|');
        getline(f,r.megyenev,'|');
        getline(f,r.jele,'|');
        f>>r.szeles;
        f>>kuka;f>>kuka;
        f>>r.hosszu;
        f>>kuka;f>>kuka;
        f>>r.magas;
        v.push_back(r);
    }
    cout<<"Beolvastuk."<<endl;
}
int heli(const vector<repter>& v)
{
    int talalt;
    int van=0;
    for(int i=0; i<v.size(); i++)
    {
        talalt=v[i].repternev.find("Helipad");    //(Helipad, Heliport, vagy Helistop)
        if(talalt!=std::string::npos)
        {
            van++;
        }
        else
        {
            talalt=v[i].repternev.find("Heliport");
            if(talalt!=std::string::npos)
            {
                van++;
            }
            else
            {
                talalt=v[i].repternev.find("Helistop");
                if(talalt!=std::string::npos)
                {
                    van++;
                }
            }
        }

    }
    return(van);
}
string legmagasabbhol(vector<repter>& v,string hol)
{
    int magas=0;
    string melyik;
       for(int i=0; i<v.size(); i++)
       {
           if(v[i].jele==hol)
           {
               if(magas<v[i].magas)
               {
                   magas=v[i].magas;
                   melyik=v[i].repternev;
               }
           }
       }
return (melyik);
}


int main()
{
    vector<repter> v;
    beolvas(v);
    cout<<heli(v)<<" db helikopter leszallo hely van."<<endl;
    string hol;
    hol="TX";
    cout<<legmagasabbhol(v,hol)<<" a legmagasebban fekvesu repter."<<endl;
    return 0;
}
