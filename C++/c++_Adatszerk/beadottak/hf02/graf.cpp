/*
 * graf.cpp
 *
 *  Created on: 2017. nov. 15.
 *      Author: Laci
 */
#include "graf.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void graf::beolvasom_graf(string filename)
{
ifstream f;
f.open(filename);
if (!f.good())
    {
        cout<<"Nem sikerult a "<<filename<<" fajl beolvasasa!!!!"<<endl;
        return;
    }
int hanyszor;
f >> hanyszor;
f>>ws;
stringstream ss;
ss.clear();
string s;
vector<vector<int>> v;
for(int i=0;i<hanyszor;i++)
{
	getline(f,s);
	ss<<s;
	int szam;
	vector<int> szamok;
	while(ss>>szam)
		{
		szamok.push_back(szam);
		}
	ss.clear();
v.push_back(szamok);
}
f>>hanyszor;
int szam;
for(int i=0;i<hanyszor;i++)
{
	f>>szam;
	f>>ws;
	raktarok.push_back(szam);
}
f.close();
cout<<"A fajl beolvasasa megtortent"<<endl;
///Gráf felépítése;
for(unsigned int i=0;i<v.size();i++)
{
	haz a;
	a.ID=v[i][0];
	a.kapcsik.clear();
	for(unsigned int ii=1;ii<v[i].size();ii++)
	{
		keto b;
		b.kivel=v[i][ii];
		ii++;
		b.suly=v[i][ii];
		a.kapcsik.push_back(b);
	}
	pontok.push_back(a);
}/*
for(unsigned int i=0;i<pontok.size();i++)
{
cout<<pontok[i].ID<<" ";
	for(unsigned int ii=0;ii<pontok[i].kapcsik.size();ii++)
	{
cout<<pontok[i].kapcsik[ii].kivel<<" "<<pontok[i].kapcsik[ii].suly<<" ";
	}
	cout<<endl;
}*/

}
///*///////////////////////////////////////////////////////////////////////////////////
void graf::beolvasom_szimi(string filename)
{
ifstream f;
f.open(filename);
if (!f.good())
    {
        cout<<"Nem sikerult a "<<filename<<" fajl beolvasasa!!!!"<<endl;
        return;
    }
int hanyszor;
f >> hanyszor;
f>>ws;
kamion kami;
for(int i=0;i<hanyszor;i++)
{
f>>kami.teherbiras>>kami.holvagyok>>ws;
k.push_back(kami);
}
f>>hanyszor;
f>>ws;
keto rendel;
for(int i=0;i<hanyszor;i++)
{
f>>rendel.kivel>>rendel.suly>>ws;
rendeles.push_back(rendel);
}
f.close();
cout<<"A fajl beolvasasa megtortent"<<endl;
}
void graf::szimulalok()
{
    ///megtöltöm a kamionokat
    for(unsigned int i=0;i<k.size();i++)
{
    int ezt=nehez();
   if(rendeles.size()!=0){
    while(k[i].teherbiras>rendeles[ezt].suly){
            k[i].hova.push_back(rendeles[ezt].kivel);
            k[i].teherbiras=k[i].teherbiras-rendeles[ezt].suly;
            rendeles[ezt]=rendeles[rendeles.size()-1];
            rendeles.pop_back();
            ezt=nehez();
            if(rendeles.size()==0)
            break;
            }
   }
    }
///kamionok megrakodva
///utakra indítás
vector<int> utvonal;
int ut;
for(unsigned int i=0;i<k.size();i++)
{
    utvonal.clear();
    ut=0;
  //  utvonal.push_back(k[i].holvagyok);
    while(k[i].hova.size()!=0)
    {
        for(int m=0;m<k[i].hova.size();m++)
           {
               if(k[i].hova[m]==k[i].holvagyok){
                k[i].hova[m]=k[i].hova[k[i].hova.size()-1];
                k[i].hova.pop_back();
               }

            if(k[i].hova.size()==0)
           break;
    int itt=itt_van_e(k[i]);
       if(itt!=-1)
       {
          // cout<<k[i].holvagyok<<endl;
         // cout<<i+1<<". teherauto kiszallitotta a rakomanyat "<<k[i].hova[itt]<<" hazhoz"<<endl;
           ut=ut+pontok[k[i].holvagyok].kapcsik[itt].suly;
           k[i].holvagyok=pontok[k[i].holvagyok].kapcsik[itt].kivel;
           utvonal.push_back(k[i].holvagyok);
           for(int m=0;m<k[i].hova.size();m++)
           {
               if(k[i].hova[m]==k[i].holvagyok){
                k[i].hova[m]=k[i].hova[k[i].hova.size()-1];
                k[i].hova.pop_back();
               }
           }
           //continue;
       }else{
           cout<<k[i].holvagyok<<endl;
           int oda=rovid(k[i],utvonal);
       k[i].holvagyok=pontok[oda].ID;
        utvonal.push_back(k[i].holvagyok);
       }
    }
    }
    cout<<i<<" kamion utvonala: ";
    for(unsigned int a=0;a<utvonal.size();a++)
    {
        cout<<utvonal[a]<<" ";
    }
    cout<<endl;
    cout<<"ennyi utat tett meg: "<<ut<<endl;
}
}

int graf::itt_van_e(kamion& k)
{
    int re=-1;
    for(unsigned int i=0;i<pontok[k.holvagyok].kapcsik.size();i++)
    {
        for(unsigned int ii=0;ii<k.hova.size();ii++)
        {
            if(pontok[k.holvagyok].kapcsik[i].kivel==k.hova[ii])
                return i; ///index;
        }
    }
    return re;
}
int graf::nehez()
{
    int maxi=0;
    for(unsigned int i=0;i<rendeles.size();i++)
    {
if(rendeles[maxi].suly<rendeles[i].suly)
    maxi=i;
    }
    return maxi;
}
int graf::rovid(kamion& k,vector<int>& u)
{
    int re=0;
    for(unsigned int i=0;i<pontok[k.holvagyok].kapcsik.size();i++)
    {
        for(int ii=0;ii<u.size();ii++){
            if(pontok[k.holvagyok].kapcsik[i].suly<pontok[k.holvagyok].kapcsik[re].suly and u[ii]!=pontok[k.holvagyok].kapcsik[i].kivel);
                re=i;
        }
    }
    return re;
}
