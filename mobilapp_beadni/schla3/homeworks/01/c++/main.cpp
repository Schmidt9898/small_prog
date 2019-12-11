#include <iostream>
#include "improperfriend.cpp"
#include "King.hpp"

// You should clean the code next time.

using namespace std;

void update(BKK &bkk)
{
    bkk.ticket_price=0;
}
int main()
{
    cout<<"------------improper------------"<<endl;
    BKK bkk;
    cout<<"Lets buy 2 ticket."<<endl;
    cout<<"I got "<<bkk.buy(2,250)<<" ticket because i don't have enough money."<<endl;
    cout<<"Hacking..."<<endl;
    update(bkk);
    cout<<"Lets buy 100 ticket."<<endl;
    //int* t=bkk.buy(2,250);
    cout<<"I got "<<bkk.buy(100,250)<<" and still have 250 forint for candy"<<endl;


    cout<<"------------proper------------"<<endl;
    King *king =new King();
    Pesant *pesant = new Pesant();
    pesant->buy_sheep();
    king->give_sheep(50,pesant);
    pesant->sel_sheep();

    return 0;
}
