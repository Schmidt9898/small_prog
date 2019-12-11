#ifndef A_H_INCLUDED
#define A_H_INCLUDED
#include <string>
#include "pres_F.h"
//#include "B.h"
//#include "C.h"
Respect respect;

class A
{
protected:
    void set_my_self()
    {
        respect.A_lista.push_back(this);
    }
public:
    virtual void F()
    {
        std::cout<<"Ez egy A"<<std::endl;
    }
/*
    static A* get_A(char T)
    {
        switch(T)
        {
        case 'B':
            return new B();
            break;
        case 'C':
            return new C();
            break;
        default:
            return new A();
        };

    }*/
};


#endif // A_H_INCLUDED
