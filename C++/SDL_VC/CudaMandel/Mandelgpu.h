


#ifdef DLL_EXPORT

//extern "C"             //No name mangling
__declspec(dllexport)  //Tells the compiler to export the function
float*                    //Function return type     
__cdecl               //Specifies calling convention, cdelc is default, 
                       //so this can be omitted 
mandelgpuinit(const int XX, const int YY);

extern "C" __declspec(dllexport) void __cdecl mandelGPU(float* __restrict datavram, float* __restrict dataram, const int XX, const int YY, const int MAX, const double mag, const double xoff, const double yoff);


#else

 __declspec(dllimport) float* __cdecl mandelgpuinit(const int XX, const int YY);

__declspec(dllimport) void __cdecl mandelGPU(float* __restrict datavram, float* __restrict dataram, const int XX, const int YY, const int MAX, const double mag, const double xoff, const double yoff);


#endif
