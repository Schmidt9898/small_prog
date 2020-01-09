using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SDL2;
namespace graf
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            SDL.SDL_Init(SDL.SDL_INIT_VIDEO);

            var window = IntPtr.Zero;

            window = SDL.SDL_CreateWindow("Cím",
                0,
                0,
                500,
                500,
                SDL.SDL_WindowFlags.SDL_WINDOW_RESIZABLE);


            SDL.SDL_Delay(5000);
            SDL.SDL_DestroyWindow(window);

            SDL.SDL_Quit();
        }
    }
}
