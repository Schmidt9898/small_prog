#ifndef SMART_POINTER_H_INCLUDED
#define SMART_POINTER_H_INCLUDED


template <typename T>
class SMARTER_POINTER
{


struct Counter_proxy
{
T * element;
//T element;
int counter=0;

Counter_proxy(T& elem)
{
    element=&elem;
    counter = 1;
}
void new_ref()
{
    counter++;
     std::cout << "reference : "<<counter << std::endl;
}
void delet_ref()
{
    counter--;
    std::cout << "reference : "<<counter << std::endl;
    if(counter<=0)
    {
        delete element;
    }
}

};

Counter_proxy* counter;
Counter_proxy* getcounter(){return counter;}

public:
    SMARTER_POINTER(T elem)
    {
            std::cout <<" new smarter pointer "<< std::endl;
    counter = new Counter_proxy(elem);
    }

    SMARTER_POINTER(SMARTER_POINTER &same)
    {
         std::cout << "new smart reference to a previous pointer " << std::endl;
        this->counter=same.getcounter();
        this->counter->new_ref();
    }

    ~SMARTER_POINTER()
    {
        std::cout << "deleting reference" << std::endl;
        this->counter->delet_ref();
    }

    T* GetElemPtr() const
    {
        return this->counter->element;
    }
      T GetElem() const
    {
        int temp=*(this->counter->element);
        return temp;
    }


};




#endif // SMART_POINTER_H_INCLUDED
