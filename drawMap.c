
#include "tetris.h"

void	drawMap(t_tetris *tetris)
{
	extern int	map[H][W];


	SDL_Rect  rect;
	rect = (SDL_Rect) {0, 0, 30, 30};
	for (int y = 0; y < 22; y++)
	{
		rect.x = 0;
		for (int x = 0; x < 19; x++)
		{
			if (map[y][x] == 0) // empty place
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
				
			}
			else if (map[y][x] == 1) // wall
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
			else if (map[y][x] == 2) // cube
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}

			rect.x += 30;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
		rect.y += 30;
	}

}
