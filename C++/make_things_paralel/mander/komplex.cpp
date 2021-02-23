#include "komplex.hpp"

     komplex  operator+ (komplex a,komplex b)
    {
        a.i+=b.i;
        a.v+=b.v;
        return a;
    }
    komplex  operator* (komplex a,komplex b)
    {
        komplex c(0,0);
        c.i=a.v*b.i+a.i*b.v;
        c.v=a.i*b.i*-1+(a.v*b.v);
        return c;
    }
