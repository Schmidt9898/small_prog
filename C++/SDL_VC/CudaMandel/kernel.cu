#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "Mandelgpu.h"
#include <iostream>

#define Ddim(arr,x,y) arr[(y) + (x)*YY]

__device__ struct komplex
{
    double i, v;
    __device__ komplex(double vv, double ii)
    {
        i = ii;
        v = vv;
    }
    __device__ double re()
    {
        return(v);
    }
    __device__ double im()
    {
        return (i);
    }
};
__device__ komplex  operator+ (komplex a, komplex b)
{
    a.i += b.i;
    a.v += b.v;
    return a;
}
__device__ komplex  operator* (komplex a, komplex b)
{
    komplex c(0, 0);
    c.i = a.v * b.i + a.i * b.v;
    c.v = a.i * b.i * -1 + (a.v * b.v);
    return c;
}


__global__ void cudamandelkernel(float* data, const int XX, const int YY,const int MAX, const double mag, const double xoff, const double yoff) {
    
        int x = threadIdx.x + blockIdx.x * blockDim.x;
        int y = threadIdx.y + blockIdx.y * blockDim.y;
        if (x < XX && y < YY) {

            double cr = (mag / double(XX)) * x - mag / 2 - xoff;
            double ci = (mag / double(YY)) * y - mag / 2 - yoff;
                komplex c(cr, ci);
                komplex z(0, 0);
                float t = 0;
                while (z.re() * z.re() + z.im() * z.im() < 4.0 && t < MAX) {
                    z = z * z + c;
                    t+=1;
                }
                //gout << move_to(x, y) << color(t, t, t) << dot;

                Ddim(data, x, y) = t/MAX*256;
        }
    

}
float* mandelgpuinit(const int XX, const int YY)
{
    float* datavram;
    cudaMalloc(&datavram, XX*YY*sizeof(int));
    return datavram;
}

void mandelGPU(float* __restrict datavram,float* __restrict dataram, const int XX, const int YY,const int MAX, const double mag, const double xoff, const double yoff) {

    dim3 threads(32,16,1);
    dim3 blocks((XX - 1) / 32 + 1, (YY - 1) / 16 + 1, 1);
    cudamandelkernel<<<blocks, threads >>> (datavram, XX,YY,MAX,mag,xoff,yoff);
    cudaMemcpy(dataram, datavram, XX*YY*sizeof(int), cudaMemcpyDeviceToHost);
}