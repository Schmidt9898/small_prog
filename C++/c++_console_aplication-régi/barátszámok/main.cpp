#include <iostream>
#include <vector>
using namespace std;

int kozos(int a, int b){
int kosz = 0;
for (int i=1; i<=a;i++)
{
    if (a%i==0 && b%i==0)
    {
        kosz++;
    }
}
return kosz;
}
 bool kozos(int a)
 {
     int barat = 0;
     for (int i=1; i<a;i++){
        if (a%i==0)
     {
         barat=barat+i;
     }
     }
     return barat==a;
 }


 bool baratsagos(int a, int b)
 {
     int e=0, r=0;
     bool re=false;
     for (int i=1; i<a;i++)
     {
         if (a%i==0)
         {
            e=e+i;
         }
     }
          for (int i=1; i<b;i++)
     {
         if (b%i==0)
         {
            r=r+i;
         }
     }
     re= (r==a) && (e==b);
     return re;
 }


int max(vector<int> v){
    int b=v[0];
for(int i=0;i<v.size();i++){
if (b<v[i])
b=v[i];
}
return b;
 }
 bool vane(vector<int> v, int ez)
 {
 for(int i=0;i<v.size();i++)
 {

    if (v[i]==6)
    {
        return true;
    }

 }
 return false;
 }
int main()
{
    cout << "tokeletes:" << kozos(6) << endl;
    cout << "baratsagos:" << baratsagos(220,284) << endl;
cout << "baratsagos:" << baratsagos(898216,980984) << endl;
vector <int> v({3,2,4,12,6,5});
cout<< max(v) << endl;
cout<< vane(v,6) << endl;

    return 0;
}
