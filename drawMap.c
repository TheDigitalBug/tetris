
#include "tetris.h"

void	drawMap(t_tetris *tetris)
{
	extern int	map[H][W];
	extern int	tetrimino[2][5][5];
	
	


	SDL_Rect  rect;
	rect = (SDL_Rect) {0, 0, 30, 30};
	for (int y = 0; y < H; y++)
	{
		rect.x = 0;
		for (int x = 0; x < W; x++)
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
			else if (map[y][x] == 3) // saved tetrimino on map
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 75, 50, 50, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
			else if (map[y][x] == 9) // cube
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
			printf("%d ",map[y][x]);

			rect.x += 30;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
		printf("\n");
		rect.y += 30;
	}

}
