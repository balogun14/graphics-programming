#include <iostream>
#include <SDL.h>


int main(int argc, char* argv[])
{
    SDL_Window *window = nullptr;
	SDL_Surface *screen = nullptr;
	SDL_Surface *imageOne = nullptr;
	SDL_Surface *imageTwo = nullptr;
	SDL_Surface *imageThree = nullptr;
	SDL_Surface *currentImage = nullptr;

	
	window = SDL_CreateWindow("Day two",  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);

	imageOne = SDL_LoadBMP("image.bmp");
	imageTwo = SDL_LoadBMP("first.bmp");
	imageThree = SDL_LoadBMP("second.bmp");
	currentImage = imageOne;
	
	bool isRunning = true;

	SDL_Event event;

	while (isRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_1:
					currentImage = imageOne;
						break;
				case SDLK_2:
					currentImage = imageTwo;
					break;
				case SDLK_3:
					currentImage = imageThree;
						break;
				default:
						std::cout << "Unknown Key Event" << event.key.keysym.sym << '\n';
						break;
				}
			}
			
		}
		SDL_BlitSurface(currentImage, NULL, screen, NULL);
	SDL_UpdateWindowSurface(window);
	}
	SDL_FreeSurface(imageOne);
	SDL_FreeSurface(imageTwo);
	SDL_FreeSurface(imageThree);

	SDL_DestroyWindow(window);
	currentImage = imageOne = imageTwo = imageThree = nullptr;
	window = nullptr;
	SDL_Quit();
    return 1;
}
