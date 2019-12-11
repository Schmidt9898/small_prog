#include <iostream>
#include <vector>

using namespace std;
class elso
{
protected:
    int a;
public:
    elso(int _a):a(_a){}
    virtual ~elso(){cout<<"elso konstructor lefutott"<<endl;}
};
class masodik : public elso
{
protected:
    int b;
public:
    masodik(int _b):elso(_b-1),b(_b){}
    ~masodik(){cout<<"masodik konstructor is lefutott"<<endl;}
};
int main()
{
    vector<elso*> v;
    elso* a=new elso(1);
    masodik* b=new masodik(2);
    v.push_back(a);
    v.push_back(b);
    for(int i=v.size()-1;i!=-1;i--)
    {
        delete v[i];
    }
    cout<<"?"<<endl;
    return 0;
}
