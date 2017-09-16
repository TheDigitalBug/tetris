
#include "tetris.h"

void	deleteLine(t_tetris *tetris)
{
	extern int	map[H][W];
	extern int	tetrimino[2][5][5];
	int			sum;
	
	for (int y = H - 1; y > 1; y--)
	{
		sum = 0;
		for (int x = 1; x < W - 1; x++)
		{
			sum += map[y][x];
		}
		if (sum == 3*10)
		{
			for (int x = 1; x < W - 1; x++)
			{
				map[y][x] = 0;
			}
		}
	}
}

