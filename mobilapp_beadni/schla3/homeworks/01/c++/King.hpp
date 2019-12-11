#ifndef KING_HPP_INCLUDED
#define KING_HPP_INCLUDED


#include "pesant.hpp"


class King{
int number_of_sheeps;
    public:
        King(){number_of_sheeps=1000;}

void buy_sheep()
{
    number_of_sheeps++;
    cout<<"King bought a sheep."<<endl;
}
void sel_sheep()
{
    number_of_sheeps--;
    if(number_of_sheeps<0){
        number_of_sheeps=0;
    }
    cout<<"King selled a sheep."<<endl;


}




   void give_sheep(int how_many,Pesant *pes)
   {
    if(how_many>number_of_sheeps)
    return;

    pes->number_of_sheeps+=how_many;

    number_of_sheeps-=how_many;
     cout<<"King gave away "<<how_many<<"sheep(s)"<<endl;
   }

   void take_sheep(int how_many,Pesant *pes)
   {
    pes->number_of_sheeps-=how_many;
    number_of_sheeps+=how_many;
    if(pes->number_of_sheeps<0)
    {
        number_of_sheeps+=pes->number_of_sheeps;
        pes->number_of_sheeps=0;
    }
    cout<<"King took away "<<how_many<<"sheep(s)"<<endl;

   }

};
#endif
