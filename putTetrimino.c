
#include "tetris.h"


int	checkTetrimino(t_tetris *tetris, t_pos pos)
{
	extern int map[H][W];
	extern int tetrimino[2][5][5];
	
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if ((map[pos.y + y][pos.x + x] + tetrimino[0][y][x]) > 9)
				return (0);
			
		}
	}
	return (1);
}

void	putTetrimino(t_tetris *tetris)
{
	extern int map[H][W];
	extern int tetrimino[2][5][5];

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			map[tetris->tetriminoPos.y + y][tetris->tetriminoPos.x + x] = tetrimino[0][y][x];
			
		}
	}
}

void	killTetrimino(t_tetris *tetris)
{
	extern int map[H][W];
	extern int tetrimino[2][5][5];
	
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			map[tetris->tetriminoPos.y + y][tetris->tetriminoPos.x + x] -= tetrimino[0][y][x];
			
		}
	}
}
