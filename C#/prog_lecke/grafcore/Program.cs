using System;
using System.Diagnostics;
using System.Threading;
using SDL2;
namespace grafcore
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            SDL.SDL_Init(SDL.SDL_INIT_VIDEO);

            var window = IntPtr.Zero;
            var renderer = IntPtr.Zero;
            window = SDL.SDL_CreateWindow("Cím",
                100,
                100,
                500,
                500,
                SDL.SDL_WindowFlags.SDL_WINDOW_SHOWN);

            renderer = SDL.SDL_CreateRenderer(window, -1, SDL.SDL_RendererFlags.SDL_RENDERER_PRESENTVSYNC);

            SDL.SDL_Event e;
           /* 
            Stopwatch timer = new Stopwatch();
            timer.Start();
            */
            Stopwatch drawtick = new Stopwatch();
            drawtick.Start();

            int xe = 0;
            int ye = 0;
            long counter = 0;

            int delay = 20;
            double divine = 1000.0 / (double)delay;
           // int timepast=0;
            int pixelp = 1000;


            Circle kor = new Circle(20, 20, 20);
            while (true)
            {
                if (SDL.SDL_PollEvent(out e) != 0)
                {
                    //counter++;
                    if (e.type == SDL.SDL_EventType.SDL_QUIT )
                    {
                        break;
                    }
                    if (e.type == SDL.SDL_EventType.SDL_MOUSEMOTION)
                    {
                        xe = e.motion.x;
                        ye = e.motion.y;

                    }
                    if(e.type== SDL.SDL_EventType.SDL_MOUSEBUTTONDOWN)
                    {
                        pixelp = 10;
                    }
                    if (e.type == SDL.SDL_EventType.SDL_MOUSEBUTTONUP)
                    {
                        pixelp = 1000;
                    }

                }
                else if(drawtick.ElapsedMilliseconds>delay)
                {

                    SDL.SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL.SDL_RenderClear(renderer);
                    //draw

                    SDL.SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
                   
                    kor.Draw(renderer);
                    //Circle.Drawraw(renderer, xe, ye, 20);
                    //show
                    SDL.SDL_RenderPresent(renderer);

                   // Console.WriteLine(counter);
                    counter = 0;

                    
                    kor.Move(xe, ye,divine,pixelp);


                    drawtick.Restart();
                }
                else
                {
                    

                   // counter++;

                    int timeslep =  (int) (delay) - (int) drawtick.ElapsedMilliseconds;
                    if(timeslep>0)
                    Thread.Sleep(timeslep);
                }

            }
            //SDL.SDL_Delay(5000);
            SDL.SDL_DestroyRenderer(renderer);
            SDL.SDL_DestroyWindow(window);
            
            SDL.SDL_Quit();
        }
    }
}
