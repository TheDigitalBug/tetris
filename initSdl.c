
#include "tetris.h"

void	sdlInit(t_tetris *tetris)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	tetris->sdl.window = SDL_CreateWindow("tetris", 300, 100, WID, HEIG,
			SDL_WINDOW_OPENGL);
	tetris->sdl.renderer = SDL_CreateRenderer(tetris->sdl.window, -1,
			SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(tetris->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(tetris->sdl.renderer);
}

void	sdlDestroy(t_tetris *tetris)
{
	SDL_DestroyRenderer(tetris->sdl.renderer);
	SDL_DestroyWindow(tetris->sdl.window);
	TTF_Quit();
	SDL_Quit();
}

void	sdlRenderClear(t_tetris *tetris)
{
	SDL_SetRenderDrawColor(tetris->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(tetris->sdl.renderer);
}
