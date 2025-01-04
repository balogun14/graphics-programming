#include <iostream>
#include <SDL.h>


int main(int argc, char* argv[])
{
    SDL_Window *window = nullptr;
	window = SDL_CreateWindow("Day two",  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);

	bool isRunning = true;

	SDL_Event event;

	while (isRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			std::cout << "Event was: " << event.type << std::endl;
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
			
		}
	SDL_UpdateWindowSurface(window);
	}
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
    return 1;
}
