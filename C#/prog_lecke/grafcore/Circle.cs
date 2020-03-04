using System;
using System.Collections.Generic;
using System.Text;
using SDL2;
namespace grafcore
{
    class Circle
    {
        double x, y;
        //double sx=0, sy=0;
        int r;

        public Circle(int x,int y,int r)
        {
            this.x = x;
            this.y = y;
            this.r = y;
        }

        public void Move(int Tx, int Ty,double time_past,int pixel)
        {
            
            double vx = Tx - x;
            double vy = Ty - y;
            double s = Math.Sqrt(vx*vx+vy*vy)*time_past/pixel;
            x += vx / s ;
            y += vy / s ;
        }


        public void Draw(IntPtr renderer)
        {

            int r2 = r * 2;

            int u = (int)x;
            int v = (int)y;
            int nx =u- r;
            int ny =v- r;
            int nr = r*r;
            for (int i = nx; i < nx + r2; i++)
            {
                for (int j = ny; j < ny + r2; j++)
                {
                    if (Math.Pow(i - u, 2) + Math.Pow(j - v, 2) <= nr)
                    {
                        SDL.SDL_RenderDrawPoint(renderer, i, j);
                    }

                }

            }
        }

        public static void Drawraw(IntPtr renderer,int x,int y,int r)
        {
            
            int r2 = r * 2;

            int u = x;
            int v = y;
            x -=r;
            y -=r;
            r *= r;
            for (int i = x; i < x + r2; i++)
            {
                for (int j = y; j < y + r2; j++)
                {
                    if (Math.Pow(i - u, 2) + Math.Pow(j - v, 2) <= r)
                    {
                        SDL.SDL_RenderDrawPoint(renderer, i, j);
                    }

                }

            }
        }
    }
}
