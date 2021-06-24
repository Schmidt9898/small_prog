#include "komplex.hpp"
#include "graphics.hpp"
#include <iostream>
#include <omp.h>
#include <sstream>
#include <chrono>
#include <thread>
using namespace genv;



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
/*
template <typename T>
comp<T> operator+ (comp<T>& a,comp<T>& b)
{
    comp<T> c;
    c.i=a.i+b.i;
    c.r=a.r+b.r;
    return a;
}*/
template <typename T>
comp<T> operator+ (comp<T> a,comp<T> b)
{
    a.i+=b.i;
    a.r+=b.r;
    return a;
}
/*
template <typename T>
comp<T>  operator* (comp<T>& a,comp<T>& b)
{
    comp<T> c;
    c.i=a.r*b.i+a.i*b.r;
    c.r=a.i*b.i*-1+(a.r*b.r);
    return c;
}*/
template <typename T>
comp<T>  operator* (comp<T> a,comp<T> b)
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
            uint32_t t=outbuff[x*YY+y];
            gout << move_to(x,y) << color(255-t,255-t/3,255-t/2) << dot;

        }

    }
}


uint32_t* mandelbrot_cpu(const uint32_t XX, const uint32_t YY, uint32_t MAX,float x_, float y_,float mag)
{
    uint32_t* outbuff = new uint32_t[XX*YY];

    for (uint32_t x=0; x<XX; x++)
    {
        //#pragma omp parallel for
        for (uint32_t y=0; y<YY; y++)
        {
            comp<float> c;
            c.r = (mag/float(XX))*x - 2 +x_;//ide adj hozzá ha el kell mozogni
            c.i = (mag/float(YY))*y - 2 +y_;
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


uint32_t* mandelbrot_cpu_parallel(const uint32_t XX, const uint32_t YY, uint32_t MAX,double x_, double y_,double mag)
{
    uint32_t* outbuff = new uint32_t[XX*YY];

    #pragma omp parallel for schedule (dynamic)
    for (uint32_t x=0; x<XX; x++)
    {

        for (uint32_t y=0; y<YY; y++)
        {
            comp<double> c;
            c.r = (mag/double(XX))*x - 2 +x_;//ide adj hozzá ha el kell mozogni
            c.i = (mag/double(YY))*y - 2 +y_;
            comp<double> z(0,0);
            comp<double> one(0,0);
            uint32_t t = 0;//konvergencia
            while (z.r*z.r+z.i*z.i < 4.0 && t < MAX)
            {
                //std::cout<<z.r*z.r+z.i*z.i;
                z = (z*z*z*z*z)+c;
                t++;
            }
            outbuff[x*YY+y]=t;
        }
    }
    return outbuff;
}


    std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
    std::chrono::duration<float> duration;

void mandelrajz(int XX, int YY, int MAX,double x_, double y_,double mag)
{

    uint32_t* outbuff;

    start = std::chrono::high_resolution_clock::now();
    outbuff=mandelbrot_cpu_parallel(XX,YY,MAX,x_,y_,mag);
    end=std::chrono::high_resolution_clock::now();
    duration = end-start;

    printf("cpu: %f s ig tartott.\n",duration.count());
    mandelbrot_print(outbuff,XX,YY,MAX);





    delete outbuff;



 /*
    #pragma omptarget teams distribute \parallel for reduction(max:error)
    for (int x=0; x<XX; x++)
    {
        //#pragma omp parallel for
        for (int y=0; y<YY; y++)
        {
            double cr = (mag/double(XX))*x - 2 + x_;
            double ci = (mag/double(YY))*y - 2 + y_;
            komplex c(cr, ci);
            komplex z(0,0);
            int t = 0;
            while (z.re()*z.re()+z.im()*z.im() < 4.0 && t < MAX)
            {
                z = z*z+c;
                ++t;
            }
            t=t*2;
            #pragma omp critical
            {
                //std::cout << "thread " << omp_get_thread_num() << std::endl;
                gout << move_to(x,y) << color(t,t/3,t/2) << dot;
            }
        }


    }*/






}
