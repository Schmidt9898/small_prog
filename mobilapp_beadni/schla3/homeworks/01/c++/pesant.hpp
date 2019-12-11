
#ifndef PESANT_HPP_INCLUDED
#define PESANT_HPP_INCLUDED
#include "king.hpp"

using namespace std;

class Pesant{
int number_of_sheeps=1;
public :
Pesant(){};

void buy_sheep()
{
    number_of_sheeps++;
    cout<<"Pesant bought a sheep, and has "<<number_of_sheeps<<endl;
}
void sel_sheep()
{
    number_of_sheeps--;
    if(number_of_sheeps<0)
        number_of_sheeps=0;

            cout<<"Pesant selled a sheep, and has "<<number_of_sheeps<<endl;
}

private:
    friend class King;

};

#endif


