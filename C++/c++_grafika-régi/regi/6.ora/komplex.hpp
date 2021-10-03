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
    komplex operator+ (komplex a,komplex b)
    {
        a.i+=b.i;
        a.v+=b.v;
        return a;
    }
        komplex operator* (komplex a,komplex b)
    {
        komplex c(0,0);
        c.i=a.v*b.i+a.i*b.v;
        c.v=a.i*b.i*-1+(a.v*b.v);
        return c;
    }

#endif // KOMPLEX_HPP_INCLUDED
