
#include "tetris.h"


void	initTetriminoCube(t_tetris *tetris)
{
	tetris->tetrimino[0] = tetris->tetriminoPos;
	tetris->tetrimino[1] = (t_pos){tetris->tetriminoPos.x + 1, tetris->tetriminoPos.y};
	tetris->tetrimino[2] = (t_pos){tetris->tetriminoPos.x, tetris->tetriminoPos.y + 1};
	tetris->tetrimino[3] =  (t_pos){tetris->tetriminoPos.x + 1, tetris->tetriminoPos.y + 1};
}

void	putTetriminoCube(t_tetris *tetris)
{
	extern int map[H][W];

	//set prev pos on map to zero
	map[tetris->tetrimino[0].y][tetris->tetrimino[0].x] = 0;
	map[tetris->tetrimino[1].y][tetris->tetrimino[1].x] = 0;
	map[tetris->tetrimino[2].y][tetris->tetrimino[2].x] = 0;
	map[tetris->tetrimino[3].y][tetris->tetrimino[3].x] = 0;
	
	if (map[tetris->tetriminoPos.y][tetris->tetriminoPos.x] == 0 &&
		map[tetris->tetriminoPos.y + 1][tetris->tetriminoPos.x] == 0 &&
		map[tetris->tetriminoPos.y][tetris->tetriminoPos.x + 1] == 0 &&
		map[tetris->tetriminoPos.y + 1][tetris->tetriminoPos.x + 1] == 0)
	{
		
	initTetriminoCube(tetris);
	map[tetris->tetrimino[0].y][tetris->tetrimino[0].x] = 2;
	map[tetris->tetrimino[1].y][tetris->tetrimino[1].x] = 2;
	map[tetris->tetrimino[2].y][tetris->tetrimino[2].x] = 2;
	map[tetris->tetrimino[3].y][tetris->tetrimino[3].x] = 2;
	}

}
