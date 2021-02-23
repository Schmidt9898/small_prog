#include <iostream>
#include <omp.h>
#include "ParallelFUN.h"
#include <chrono>
#include <thread>
//using namespace std;
#include "mandelbrot_fun.h"

void Test_prime();

int main()
{

    std::cout << "OMP teszteles!\n";
    std::cout << "Total Devices: " << omp_get_num_devices() << std::endl;
    //int a,b,c,d;
    //a=b=c=d=0;
    //printf("Values a=%d,b=%d,c=%d,d=%d___\n",a,b,c,d);


    //cout<<is_prime(1)<<"\n";


    std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
    std::chrono::duration<float> duration;

    const uint32_t XX=2000,YY=2000,MAX=255;
    uint32_t* outbuff;

    start = std::chrono::high_resolution_clock::now();
    outbuff=mandelbrot_cpu(XX,YY,MAX);
    end=std::chrono::high_resolution_clock::now();
    duration = end-start;

    printf("egyszalas cpu: %f s ig tartott.\n",duration.count());
    //mandelbrot_print(outbuff,XX,YY,MAX);
    delete outbuff;


    //parallel
    start = std::chrono::high_resolution_clock::now();
    outbuff=mandelbrot_cpu_parallel(XX,YY,MAX);
    end=std::chrono::high_resolution_clock::now();
    duration = end-start;

    printf("tobbszalas cpu: %f s ig tartott.\n",duration.count());
    //mandelbrot_print(outbuff,XX,YY,MAX);
    delete outbuff;



    //parallel gpu
    start = std::chrono::high_resolution_clock::now();
    outbuff=mandelbrot_gpu(XX,YY,MAX);
    end=std::chrono::high_resolution_clock::now();
    duration = end-start;

    printf("tobbszalas gpu: %f s ig tartott.\n",duration.count());
    //mandelbrot_print(outbuff,XX,YY,MAX);
    delete outbuff;








    //comp<float> a,b;
    //a={1,2};
    //std::cout<<a.toString()<<"\n";
    //Test_prime();






    std::cout << "End!\n";
    return 0;
}



void Test_prime()
{

    std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
    std::chrono::duration<float> duration;
    size_t N=100;
    start = std::chrono::high_resolution_clock::now();
    GetNumPrims_singlecore(N);
    end=std::chrono::high_resolution_clock::now();
    duration = end-start;

    printf("egyszalas: %f s ig tartott.\n",duration.count());


    start = std::chrono::high_resolution_clock::now();
    GetNumPrims_parallel(N);
    end=std::chrono::high_resolution_clock::now();
    duration = end-start;

    printf("tobbszalas: %f s ig tartott.\n",duration.count());


    start = std::chrono::high_resolution_clock::now();
    GetNumPrims_parallel_schedule(N);
    end=std::chrono::high_resolution_clock::now();
    duration = end-start;

    printf("tobbszalas elosztott: %f s ig tartott.\n",duration.count());


    start = std::chrono::high_resolution_clock::now();
    GetNumPrims_gpu(N);
    end=std::chrono::high_resolution_clock::now();
    duration = end-start;

    printf("gpu: %f s ig tartott.\n",duration.count());
    //
    //export OMP_NUM_THREADS;


}

