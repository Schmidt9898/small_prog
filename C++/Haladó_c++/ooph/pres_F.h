#ifndef PRES_F_H_INCLUDED
#define PRES_F_H_INCLUDED
#include "A.h"
#include <vector>
class A;
class Respect
{
    public :
   std::vector<A*> A_lista;
    A* get_A(int id)
    {
    return A_lista[id];
    };


};

#endif // PRES_F_H_INCLUDED
