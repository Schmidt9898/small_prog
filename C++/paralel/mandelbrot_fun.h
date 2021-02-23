#ifndef MANDELBROT_FUN_H_INCLUDED
#define MANDELBROT_FUN_H_INCLUDED
#include <string>
#include <sstream>
template <typename T>
struct comp
{
    T r=0,i=0;
    comp() {};
    comp(T r_,T i_):r(r_),i(i_) {};
    comp(T r_):r(r_),i(0) {};


    comp(comp& same)
    {
        r=same.r;
        i=same.i;
    }
    std::string toString()
    {
        std::stringstream ss;
        ss<< "r:" << r << " i:" << i;
        return ss.str();
    }

};
template <typename T>
comp<T> operator+ (comp<T>& a,comp<T>& b)
{
    comp<T> c;
    c.i=a.i+b.i;
    c.r=a.r+b.r;
    return a;
}
template <typename T>
comp<T> operator+ (comp<T> a,comp<T> b)
{
    a.i+=b.i;
    a.r+=b.r;
    return a;
}
template <typename T>
comp<T>  operator* (comp<T>& a,comp<T>& b)
{
    comp<T> c;
    c.i=a.r*b.i+a.i*b.r;
    c.r=a.i*b.i*-1+(a.r*b.r);
    return c;
}


void mandelbrot_print(uint32_t* outbuff,const uint32_t XX, const uint32_t YY, uint32_t MAX)
{
        for (uint32_t x=0; x<XX; x++)
    {
        //#pragma omp parallel for
        for (uint32_t y=0; y<YY; y++)
        {
            if(outbuff[x*YY+y]>254)
                std::cout<<"#";
            else
                std::cout<<" ";
        }
        std::cout<<"\n";
    }
}


uint32_t* mandelbrot_cpu(const uint32_t XX, const uint32_t YY, uint32_t MAX)
{
    uint32_t* outbuff = new uint32_t[XX*YY];

    for (uint32_t x=0; x<XX; x++)
    {
        //#pragma omp parallel for
        for (uint32_t y=0; y<YY; y++)
        {
            comp<float> c;
            c.r = (4/float(XX))*x - 2 ;//ide adj hozzá ha el kell mozogni
            c.i = (4/float(YY))*y - 2 ;
            comp<float> z(0,0);
            uint32_t t = 0;//konvergencia
            while (z.r*z.r+z.i*z.i < 4.0 && t < MAX)
            {
                //std::cout<<z.r*z.r+z.i*z.i;
                z = z*z+c;
                t++;
            }
            outbuff[x*YY+y]=t;
        }
    }
    return outbuff;
}


uint32_t* mandelbrot_cpu_parallel(const uint32_t XX, const uint32_t YY, uint32_t MAX)
{
    uint32_t* outbuff = new uint32_t[XX*YY];

    #pragma omp parallel for schedule (dynamic ,1)
    for (uint32_t x=0; x<XX; x++)
    {

        for (uint32_t y=0; y<YY; y++)
        {
            comp<float> c;
            c.r = (4/float(XX))*x - 2 ;//ide adj hozzá ha el kell mozogni
            c.i = (4/float(YY))*y - 2 ;
            comp<float> z(0,0);
            uint32_t t = 0;//konvergencia
            while (z.r*z.r+z.i*z.i < 4.0 && t < MAX)
            {
                //std::cout<<z.r*z.r+z.i*z.i;
                z = z*z+c;
                t++;
            }
            outbuff[x*YY+y]=t;
        }
    }
    return outbuff;
}

uint32_t* mandelbrot_gpu(const uint32_t XX, const uint32_t YY, uint32_t MAX)
{
    uint32_t* outbuff = new uint32_t[XX*YY];

    #pragma omp target teams distribute parallel for collapse(2)  //schedule (dynamic ,1)
    for (uint32_t x=0; x<XX; x++)
    {

        for (uint32_t y=0; y<YY; y++)
        {
            comp<float> c;
            c.r = (4/float(XX))*x - 2 ;//ide adj hozzá ha el kell mozogni
            c.i = (4/float(YY))*y - 2 ;
            comp<float> z(0,0);
            uint32_t t = 0;//konvergencia
            while (z.r*z.r+z.i*z.i < 4.0 && t < MAX)
            {
                //std::cout<<z.r*z.r+z.i*z.i;
                z = z*z+c;
                t++;
            }
            outbuff[x*YY+y]=t;
        }
    }
    return outbuff;
}



#endif // MANDELBROT_FUN_H_INCLUDED
