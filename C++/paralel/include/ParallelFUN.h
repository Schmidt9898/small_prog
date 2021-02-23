#ifndef PARALLELFUN_H
#define PARALLELFUN_H
#include <iostream>
#include <omp.h>


//size_t N = 10;

void First_testing()
{

    printf("No syncronization..\n");
    #pragma omp parallel
    {
        std::cout << "thread " << omp_get_thread_num() << std::endl;
    }

    printf("With syncronization..\n");
    #pragma omp parallel
    {
        #pragma omp critical
        {
            std::cout << "thread " << omp_get_thread_num() << std::endl;
        }
    }

    printf("for ciklus..\n");
    #pragma omp parallel for //schedule (static ,250)
    for(int i=0; i<1000; i++)
    {
        std::cout << "thread " << omp_get_thread_num() << std::endl;
    }
}

bool is_prime(size_t x)
{
    size_t div = x/2;
    while(div>1)
    {
        if(x%div==0)
            break;
        else
            div--;
    }
    return div==1;

}

bool is_prime_gpu(size_t x)
{
    int prime=0;

    //#pragma omp target teams distribute parallel for map(tofrom:prime)
    for(size_t div = x/2;div>1;div--)
    {
        if(x%div==0){
            prime++;
        }
    }
    return prime==0;

}



void GetNumPrims_singlecore(size_t N)
{
    size_t count_=0;
    for(size_t i=0; i<N; i++)
    {

        if(is_prime(i))
        {
            count_++;
            //printf("%d is a prime.\n",i);
        }
    }
    printf("%d darab prime.\n",count_);
}

void GetNumPrims_parallel(size_t N)
{
    size_t count_=0;
    #pragma omp parallel for
        for(size_t i=0; i<N; i++)
        {



            if(is_prime(i))
            {
                #pragma omp critical
                {
                    count_++;
                }
                //printf("%d is a prime.\n",i);
            }
        }
    printf("%d darab prime.\n",count_);
}

void GetNumPrims_parallel_schedule(size_t N)
{
    size_t count_=0;
    #pragma omp parallel for schedule (dynamic ,200)
        for(size_t i=0; i<N; i++)
        {

            if(is_prime(i))
            {
                #pragma omp critical
                {
                    count_++;
                }
                //printf("%d is a prime.\n",i);
            }
        }
    printf("%d darab prime.\n",count_);
}

void GetNumPrims_gpu(const size_t N)
{
    size_t count_=0;

    #pragma omp target teams distribute parallel for \
    map(from:count_) reduction(+:count_) //schedule (static ,1)
        for(size_t i=0; i<N; i++)
        {

            if(is_prime_gpu(i))
            {
                //#pragma omp critical
                {
                    //printf("%d\n",count_);
                    count_++;
                }

            }
        }

    printf("%d darab prime.\n",count_);
}






#endif // PARALLELFUN_H
