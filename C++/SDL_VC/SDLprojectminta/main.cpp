#include "SDL.h"

int main(int argc, char *argv[])
{

	const int width=600, height=400;


	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Ablak.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);




	size_t array_size = width * height;
	int* data = new int[array_size];

	

	for (size_t x = 0; x < width; x++)
	{
		for (size_t y = 0; y < height; y++)
		{
			//SDL_SetRenderDrawColor(renderer, t,t,t, 255);
			SDL_RenderDrawPoint(renderer,x, y);

		}
	}




	SDL_RenderPresent(renderer);

	SDL_Delay(30000);


	delete[] data;
	return 0;
}