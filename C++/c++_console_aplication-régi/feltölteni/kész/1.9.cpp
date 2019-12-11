#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c,s;
{cin >> a >> b >> c ;
s=(a+b+c)/2;
cout << fixed << setprecision(1) << sqrt(s*(s-a)*(s-b)*(s-c)) << endl;}
    return 0;
}
