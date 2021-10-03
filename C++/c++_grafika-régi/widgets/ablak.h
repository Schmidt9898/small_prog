#ifndef ABLAK_H_INCLUDED
#define ABLAK_H_INCLUDED
#include <vector>
#include "widget.hpp"
//#include "eszkoz.hpp"
class ablak
{
protected:
    std::vector<widget*> widgets;
public:
    void esemeny_hurok();
};


#endif // ABLAK_H_INCLUDED
