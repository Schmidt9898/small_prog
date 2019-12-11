#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    cout << fixed << setprecision(1) << sqrt((a-c)*(a-c)+(b-d)*(b-d)) << endl;
    return 0;
}
