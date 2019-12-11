#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int r=100;
    ofstream f("kör.txt");
for (int i=1; i<=2*r; ++i)
{
    for (int j=1;j<=2*r;++j)
    {
if ((pow(i-r,2)+pow(j-r,2))>=pow(r,2))
    {
            f<<"###";

    }
else
    {
        if (pow(i-r,2)+pow(j-r,2)>=pow((r/4),2))
        {
            f<<"---";
        }
        else
            {
    f<<"   ";
}
    }
    }
    f<<endl;
}
    return 0;
}
