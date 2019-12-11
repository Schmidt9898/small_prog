#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a,b; double c[2]; int i=0;
    while (i!=3)
    {
    cin >> a >> b;
    c[i]=a*b;
    i++;
    }
    i=0;
    while (i!=3)
    {
cout << fixed << setprecision(1) << c[i] << endl;
i++;
    }
    return 0;
}
