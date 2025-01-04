#include <iostream>
#include <SDL.h>

//class InitError : public std::exception
//{
//    std::string msg;
//public:
//    InitError();
//    InitError(const std::string&);
//    virtual ~InitError() throw();
//    virtual const char* what() const throw();
//};
//
//InitError::InitError() :
//    exception(),
//    msg(SDL_GetError())
//{
//}
//
//InitError::InitError(const std::string& m) :
//    exception(),
//    msg(m)
//{
//}
//
//InitError::~InitError() throw()
//{
//}
//
//const char* InitError::what() const throw()
//{
//    return msg.c_str();
//}
//
//class SDL
//{
//    SDL_Window* m_window;
//    SDL_Renderer* m_renderer;
//public:
//    SDL(Uint32 flags = 0);
//    virtual ~SDL();
//    void draw();
//};
//
//SDL::SDL(Uint32 flags)
//{
//    if (SDL_Init(flags) != 0)
//        throw InitError();
//
//    if (SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN,
//        &m_window, &m_renderer) != 0)
//        throw InitError();
//}
//
//SDL::~SDL()
//{
//    SDL_DestroyWindow(m_window);
//    SDL_DestroyRenderer(m_renderer);
//    SDL_Quit();
//}
//
//void SDL::draw()
//{
//    // Clear the window with a black background
//    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
//    SDL_RenderClear(m_renderer);
//
//    // Show the window
//    SDL_RenderPresent(m_renderer);
//
//    int rgb[] = { 203, 203, 203, // Gray
//                  254, 254,  31, // Yellow
//                    0, 255, 255, // Cyan
//                    0, 254,  30, // Green
//                  255,  16, 253, // Magenta
//                  253,   3,   2, // Red
//                   18,  14, 252, // Blue
//                    0,   0,   0  // Black
//    };
//
//    SDL_Rect colorBar;
//    colorBar.x = 0; colorBar.y = 0; colorBar.w = 90; colorBar.h = 480;
//
//    // Render a new color bar every 0.5 seconds
//    for (int i = 0; i != sizeof rgb / sizeof * rgb; i += 3, colorBar.x += 90)
//    {
//        SDL_SetRenderDrawColor(m_renderer, rgb[i], rgb[i + 1], rgb[i + 2], 255);
//        SDL_RenderFillRect(m_renderer, &colorBar);
//        SDL_RenderPresent(m_renderer);
//        SDL_Delay(500);
//    }
//}

int main(int argc, char* argv[])
{
    SDL_Window *window = nullptr;
	SDL_Surface *windowSurface = nullptr;
	SDL_Surface *imageSurface = nullptr;
	if (SDL_Init(SDL_INIT_VIDEO) <0)
	{
		std::cout << "Video Initialization Error" << SDL_GetError() << '\n';
		
	}
	else
	{
		window = SDL_CreateWindow("Day two",  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
		
		if (window == NULL)
		{
			std::cout << "Window Creation Error" << SDL_GetError() << '\n';

		}
		else {
			windowSurface = SDL_GetWindowSurface(window);
			imageSurface = SDL_LoadBMP("image.bmp");
			if (imageSurface == NULL)
			{
				std::cout << "Image Loading Error" << SDL_GetError() << '\n';
			}
			else
			{
				SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
				
			}
		}
	}
	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
	SDL_DestroyWindow(window);
	windowSurface = nullptr;
	window = nullptr;
	SDL_Quit();
    return 1;
}
