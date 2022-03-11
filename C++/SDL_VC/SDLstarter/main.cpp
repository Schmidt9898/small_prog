#include "SDL.h"
#include "MandelCPU.h"
#include "Mandelgpu.h"
#include <chrono>
#include <iostream>
#include <stdio.h>




unsigned int rgb(float ratio)
{
	//we want to normalize ratio so that it fits in to 6 regions
	//where each region is 256 units long
	int normalized = int(ratio * 256 * 6);

	//find the distance to the start of the closest region
	int x = normalized % 256;

	int red = 0, grn = 0, blu = 0;
	switch (normalized / 256)
	{
	case 0: red = 255;      grn = x;        blu = 0;       break;//red
	case 1: red = 255 - x;  grn = 255;      blu = 0;       break;//yellow
	case 2: red = 0;        grn = 255;      blu = x;       break;//green
	case 3: red = 0;        grn = 255 - x;  blu = 255;     break;//cyan
	case 4: red = x;        grn = 0;        blu = 255;     break;//blue
	case 5: red = 255;      grn = 0;        blu = 255 - x; break;//magenta
	}

	return red + (grn << 8) + (blu << 16);
}







#define Ddim(arr,x,y) arr[(y) + (x)*height]
int main(int argc, char *argv[])
{
	//system("set CUDA_VISIBLE_DEVICES=1");
	const int width=1240, height=720;
	//_putenv("CUDA_VISIBLE_DEVICES = 1");

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Ablak.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);













	size_t array_size = width * height;
	float* __restrict data = new float[array_size];
	float* __restrict datagpu = mandelgpuinit(width, height);

	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	double mag = 4;
	double xoff = 0, yoff = 0;
	double step = 0.1;
	SDL_Event event;
	bool most = true;
	int converg = 256;
	while (true)
	{
		
		if (most)
		{
	start = std::chrono::high_resolution_clock::now();
			most = false;
	mandelGPU(datagpu,data, width, height,converg,mag,xoff,yoff);
	//mandelrajz(data, width, height,255,mag, xoff, yoff);

	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << duration.count() << "\n";

	}

		int x=0, y=0;
	while (SDL_PollEvent(&event))
	{
		
		if (event.type == SDL_MOUSEWHEEL)
		{
			/*if (event.wheel.y > 0) // scroll up
			{
				std::cout << "fel";
			}
			else if (event.wheel.y < 0) // scroll down
			{
				std::cout << "le";
			}*/
		}
		
		
		//std::cout << x << " " << y << "\n";
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
		SDL_GetMouseState(&x, &y);
			most = true;
			mag = mag / 2;
			xoff += (width / 2 - x) * (mag / double(width));
			yoff += (height / 2 - y) * (mag / double(height));
			most = true;
		}
		
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				std::cout << "restart";
				mag = 4;
				most = true;

			}
			
			if (event.key.keysym.sym == SDLK_UP)
			{
				//std::cout << "fel";
				converg += 256;
				most = true;
				std::cout << converg<<"\n";
			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				converg -= 256;
				most = true;
				std::cout << converg << "\n";
			}
			/*
			if (event.key.keysym.sym == SDLK_d)
			{
				std::cout << "d";
				xoff -= step;
			}*/
		}



	}

	



	for (size_t x = 0; x < width; x++)
	{
		for (size_t y = 0; y < height; y++)
		{
			float t = Ddim(data, x, y);
			//unsigned int color = rgb(t);
			//char* colorp = (char*)&color;
			//if (t < 256)
			SDL_SetRenderDrawColor(renderer, t,2*t,t*3, 255);
			//else
			//SDL_SetRenderDrawColor(renderer, 0,0,0, 255);


			SDL_RenderDrawPoint(renderer,x, y);

		}
	}
	

	SDL_RenderPresent(renderer);
	//SDL_Delay(25);
	}






	delete[] data;
	return 0;
}