
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>


__global__ void helokernel()
{
    int i = threadIdx.x;
    printf("Helo mate from gpu!\n");
}

int main()
{
    printf("Helo this is the host cpu\n");
    dim3 threads(10);
    helokernel << <1, threads >> > ();
    cudaDeviceSynchronize();
    system("pause");
    return 0;

}