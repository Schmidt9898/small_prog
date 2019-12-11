#include <iostream>

using namespace std;

template <int N>
    class fac{
    public : enum {value=fac<N-2>::value+fac<N-1>::value};

    };
template <>
class fac<1>
{
public:
    enum{value=1};

}    ;


template <>
class fac<0>
{
public:
    enum{value=0};

}    ;



int main()
{
    cout << "Hello world!" << endl;
        cout<<fac<46>::value<<endl;

    return 0;
}
