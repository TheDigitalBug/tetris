
#include "tetris.h"

void	drawNextTetrimino(t_tetris *tetris)
{
	extern int	tetrimino[24][5][5];
	SDL_Rect		rect;
	int			y;
	int			x;

	putTextMessage(tetris, "NEXT", (SDL_Rect){WID - INFO + WIDOFCUBE + 25, 0, INFO / 2, WIDOFCUBE});
	rect = (SDL_Rect) {0, WIDOFCUBE, WIDOFCUBE, WIDOFCUBE};
	for (y = 0; y < 5; y++)
	{
		rect.x = WID - INFO + WIDOFCUBE;
		for (x = 0; x < 5; x++)
		{
			if (tetrimino[tetris->nextTetrimino][y][x] == 0)
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
			else if (tetrimino[tetris->nextTetrimino][y][x] == 9)
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 75, 50, 50, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 40, 40, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &((SDL_Rect) {rect.x + 4, rect.y + 4, WIDOFCUBE-8, WIDOFCUBE-8}));
			}
			rect.x += WIDOFCUBE;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
		rect.y += WIDOFCUBE;
	}
}
