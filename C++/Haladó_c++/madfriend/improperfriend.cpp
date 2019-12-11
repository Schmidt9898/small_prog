

class BKK
{
    int ticket_price=250;
friend void update(BKK &bkk);
    public :
    int buy(unsigned int quantity,unsigned int money)
    {
        int full_price = ticket_price*quantity;
        if(full_price>money)
        {
            //int tomb[2] = {0,money};
            return 0;//tomb;
        }else{
        //int tomb[2] = {quantity,money};
        return quantity;//tomb;
        }
    }

    //private :


};
/// use in the main.cpp
/*
void update(BKK &bkk)
{   bkk.ticket_price=0;}
*/
///
