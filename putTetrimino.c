
#include "tetris.h"

int	checkTetrimino(t_tetris *tetris, t_pos pos)
{
	extern int	map[H][W];
	extern int	tetrimino[24][5][5];
	int			y;
	int			x;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 5; x++)
		{
			if ((map[pos.y + y][pos.x + x] + tetrimino[tetris->tetriminoType][y][x]) > 9)
			{
				if (pos.y + y == 0)
				{
					putTextMessage(tetris, "YOU LOSE", (SDL_Rect){(WID - INFO) / 2, HEIG / 2 - WIDOFCUBE, INFO, WIDOFCUBE * 2});
					SDL_RenderPresent(tetris->sdl.renderer);
					SDL_Delay(1000);
					sdlDestroy(tetris);
					exit(0);
				}
				return (0);
			}
		}
	}
	return (1);
}

void	putTetrimino(t_tetris *tetris)
{
	extern int	map[H][W];
	extern int	tetrimino[24][5][5];
	int			y;
	int			x;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 5; x++)
		{
			map[tetris->tetriminoPos.y + y][tetris->tetriminoPos.x + x] += tetrimino[tetris->tetriminoType][y][x];
		}
	}
}

void	killTetrimino(t_tetris *tetris)
{
	extern int	map[H][W];
	extern int	tetrimino[24][5][5];
	int			y;
	int			x;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 5; x++)
		{
			map[tetris->tetriminoPos.y + y][tetris->tetriminoPos.x + x] -= tetrimino[tetris->tetriminoType][y][x];
		}
	}
}

void	saveTetrimino(t_tetris *tetris)
{
	extern int	map[H][W];
	extern int	tetrimino[24][5][5];
	int			y;
	int			x;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 5; x++)
		{
			if (tetrimino[tetris->tetriminoType][y][x] == 9)
				map[tetris->tetriminoPos.y + y][tetris->tetriminoPos.x + x] = 3;
		}
	}
}

