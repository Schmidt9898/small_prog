#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

#define ellenoriz(felt, pont) if (felt) pont++; else cerr << "Nem teljesul a feltetel a " << __LINE__<< ". sorban." <<endl;

/* Szabalyok:
    - csak az a beugró érvényes, amely nem tartalmaz semmilyen változtatást a main()-ben,
        és már nincs benne kommentezve semmi
    - az "ellenoriz"-en kívül nem tartalmaz #define sorokat, és azt sem szabad megváltoztatni
*/

// Innentol
int fv(int a)
{
    a=a*2;
    return(a);
}
struct Vektor
{
    vector<int> t;
    int osszeg;
};
void legyen_egyenlo(Vektor& k,Vektor& v)
{
    k.t=v.t;
}
bool egyenlo_e(Vektor& k,Vektor& v)
{
    bool a;
    a=k.t==v.t;
    return(a);
}
void osszead(Vektor& a)
{
    a.osszeg=0;
    for(int i=0;i<a.t.size();i++)
    {
        a.osszeg=a.t[i]+a.osszeg;
    }
}
// Idaig

int main()
{
    int pont = 0;

    int a = fv(2);
    int b = fv(4);
    ellenoriz(a == 4 && b == 8 , pont)

    Vektor v;
    ellenoriz(v.t.size()==0 , pont)

    v.t = vector<int>(8,2);
    ellenoriz(v.t.size()==8 , pont)

    Vektor k;
    legyen_egyenlo(k,v);
    ellenoriz(k.t.size()==8 , pont)

    bool b1 = egyenlo_e(k,v);
    k.t[3]=3;
    bool b2 = egyenlo_e(k,v);
    ellenoriz(b1==true && b2==false , pont)

    osszead(v);
    osszead(k);
    ellenoriz( v.osszeg == 16 && k.osszeg == 17 , pont)

    cout << endl << pont << "/6 pont";
}
