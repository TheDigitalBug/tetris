
#include "tetris.h"

int			tetrimino[24][5][5] =
{
	{//1
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,0,0,0},
	},
	
	{//2
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,9,9,9,9},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//3
		{0,0,0,0,0},
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,9,0,0},
	},
	
	{//4
		{0,0,0,0,0},
		{0,0,0,0,0},
		{9,9,9,9,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//5
		{0,0,0,0,0},
		{0,0,9,9,0},
		{0,0,9,9,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//6
		{0,0,0,0,0},
		{0,0,9,9,0},
		{0,0,9,9,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//7
		{0,0,0,0,0},
		{0,0,9,9,0},
		{0,0,9,9,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//8
		{0,0,0,0,0},
		{0,0,9,9,0},
		{0,0,9,9,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//9
		{0,0,0,0,0},
		{0,0,9,0,0},
		{0,9,9,9,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//10
		{0,0,0,0,0},
		{0,0,9,0,0},
		{0,0,9,9,0},
		{0,0,9,0,0},
		{0,0,0,0,0},
	},
	
	{//11
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,9,9,9,0},
		{0,0,9,0,0},
		{0,0,0,0,0},
	},
	
	{//12
		{0,0,0,0,0},
		{0,0,9,0,0},
		{0,9,9,0,0},
		{0,0,9,0,0},
		{0,0,0,0,0},
	},
	
	{//13
		{0,0,0,0,0},
		{0,0,0,9,0},
		{0,9,9,9,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//14
		{0,0,0,0,0},
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,9,9,0},
		{0,0,0,0,0},
	},
	
	{//15
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,9,9,9,0},
		{0,9,0,0,0},
		{0,0,0,0,0},
	},
	
	{//16
		{0,0,0,0,0},
		{0,9,9,0,0},
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,0,0,0},
	},
	
	{//17
		{0,0,0,0,0},
		{0,0,9,9,0},
		{0,9,9,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//18
		{0,0,0,0,0},
		{0,0,9,0,0},
		{0,0,9,9,0},
		{0,0,0,9,0},
		{0,0,0,0,0},
	},
	
	{//19
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,9,9,0},
		{0,9,9,0,0},
		{0,0,0,0,0},
	},
	
	{//20
		{0,0,0,0,0},
		{0,9,0,0,0},
		{0,9,9,0,0},
		{0,0,9,0,0},
		{0,0,0,0,0},
	},
	
	{//21
		{0,0,0,0,0},
		{0,9,9,0,0},
		{0,0,9,9,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	},
	
	{//22
		{0,0,0,0,0},
		{0,0,0,9,0},
		{0,0,9,9,0},
		{0,0,9,0,0},
		{0,0,0,0,0},
	},
	
	{//23
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,9,9,0,0},
		{0,0,9,9,0},
		{0,0,0,0,0},
	},
	
	{//24
		{0,0,0,0,0},
		{0,0,9,0,0},
		{0,9,9,0,0},
		{0,9,0,0,0},
		{0,0,0,0,0},
	}
};

int				map[22][12] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1},
};

static void		initStartCond(t_tetris *tetris, int *stop, int *delay, int *random)
{
	*stop = 0;
	*delay = 500;
	tetris->tetriminoPos = (t_pos){3, 0}; //start position
	tetris->tetriminoType = rand() % 24; //rand 1s tetrimino
	tetris->nextTetrimino = rand() % 24; //rand next tetrimino
	*random = (rand() * tetris->tetriminoType) / 200 + 55; //rand color
	tetris->tetriminoColor = (SDL_Color){*random / 4, *random / 3, *random / 2, 255};
	tetris->scoreLines = 0;
	tetris->pause = 0;
	tetris->delay = 500;
}

int				main(void)
{
	int			stop;
	t_tetris		*tetris;
	int			delay;
	int			random;
	int			introflag = 0;
	int			currentType;
	
	tetris = (t_tetris *)malloc(sizeof(t_tetris));
	sdlInit(tetris);
	initStartCond(tetris, &stop, &delay, &random);
	while (!stop)
	{
		while (SDL_PollEvent(&(tetris->sdl.e)))
		{
			if (tetris->sdl.e.type == SDL_QUIT || tetris->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				stop = 1;
			else if (tetris->sdl.e.type == SDL_KEYDOWN)
			{
				if (tetris->sdl.e.key.keysym.sym == SDLK_SPACE)
				{
					putTextMessage(tetris, "Pause", (SDL_Rect){(WID - INFO) / 2, HEIG / 2 - WIDOFCUBE, INFO, WIDOFCUBE * 2});
					tetris->pause = (tetris->pause == 1) ? 0 : 1;
					SDL_RenderPresent(tetris->sdl.renderer);
					sdlRenderClear(tetris);
				}
				else if (tetris->sdl.e.key.keysym.sym == SDLK_UP && tetris->pause == 0)
				{
					currentType = tetris->tetriminoType;
					if (tetris->tetriminoType % 4 == 3)
						tetris->tetriminoType = (tetris->tetriminoType / 4) * 4;
					else
						tetris->tetriminoType++;
					if (checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x, tetris->tetriminoPos.y} ) == 0)
						tetris->tetriminoType = currentType;
				}
				else if (tetris->sdl.e.key.keysym.sym == SDLK_DOWN && tetris->pause == 0)
					delay = 50;
				else if (tetris->sdl.e.key.keysym.sym == SDLK_RIGHT && tetris->pause == 0 && checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x + 1, tetris->tetriminoPos.y} ) == 1)
					tetris->tetriminoPos.x++;
				else if (tetris->sdl.e.key.keysym.sym == SDLK_LEFT && tetris->pause == 0 && checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x - 1, tetris->tetriminoPos.y} ) == 1)
					tetris->tetriminoPos.x--;
				else if (tetris->sdl.e.key.keysym.sym == SDLK_1)
					tetris->delay = (tetris->delay == 200) ? 500 : 200;
			}
		}
		if(introflag == 0)
			intro(tetris, &introflag);
		if (tetris->pause == 0)
		{
			if (checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x, tetris->tetriminoPos.y + 1}) == 1)
			{
				tetris->tetriminoPos.y++;
				putTetrimino(tetris);
				drawMap(tetris);
				drawNextTetrimino(tetris);
				setLivesLevel(tetris);
				killTetrimino(tetris);
				SDL_RenderPresent(tetris->sdl.renderer);
				sdlRenderClear(tetris);
				SDL_Delay(delay);
			}
			else
			{
				if (checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x, tetris->tetriminoPos.y + 1}) == 0 && (tetris->tetriminoPos.x == 3 && tetris->tetriminoPos.y == 0))
				{
					SDL_RenderPresent(tetris->sdl.renderer);
					sdlRenderClear(tetris);
					putTextMessage(tetris, "YOU LOSE", (SDL_Rect){(WID - INFO) / 2, HEIG / 2 - WIDOFCUBE, INFO, WIDOFCUBE * 2});
					SDL_RenderPresent(tetris->sdl.renderer);
					SDL_Delay(1000);
					sdlDestroy(tetris);
					exit(0);
				}
				saveTetrimino(tetris);
				deleteLine(tetris);
				tetris->tetriminoPos = (t_pos){3, 0};
				tetris->tetriminoType = tetris->nextTetrimino;
				tetris->nextTetrimino = rand() % 24;
				random = (rand() * tetris->tetriminoType) / 200 + 55;
				tetris->tetriminoColor = (SDL_Color){75, random / 3, random / 2, 255};
			}
			delay = tetris->delay;
		}
	}
	sdlDestroy(tetris);
	return 0;
}
