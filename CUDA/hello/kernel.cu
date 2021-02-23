#include "myheader.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

__global__ void f() {
    int x = threadIdx.x, y=threadIdx.y, z=threadIdx.z;
    printf(" Hello from gpu #%d , %d , %d\n",x,y,z);
}
void F()
{
    dim3 threads(10);

    f <<<1, threads >> > ();
    cudaDeviceSynchronize();
    printf("hello from cpu\n");
}
/*
int main()
{
    dim3 threads(10);

    f <<<1,threads>>> ();
    cudaDeviceSynchronize();
    printf("hello from cpu\n");


    return 0;
}
*/
