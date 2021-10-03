#ifndef KOMPLEX_HPP_INCLUDED
#define KOMPLEX_HPP_INCLUDED

struct komplex
{
    double i,v;
    komplex(double vv, double ii)
    {
        i=ii;
        v=vv;
    }
    double re()
    {
return(v);
    }
    double im()
    {
return (i);
    }


};
     komplex  operator+ (komplex a,komplex b);
     komplex  operator* (komplex a,komplex b);

#endif // KOMPLEX_HPP_INCLUDED
