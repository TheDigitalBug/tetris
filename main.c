
#include "tetris.h"

int tetrimino[12][5][5] =
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
	}
};


int map[22][12] =
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


int main(void)
{
	int			stop;
	t_tetris		*tetris;
	int			delay = 500;
	
	stop = 0;

	tetris = (t_tetris *)malloc(sizeof(t_tetris));
	sdlInit(tetris);
	
	tetris->tetriminoPos = (t_pos){5, 5};
	tetris->tetriminoType = rand() % 12;
	int random = (rand() * tetris->tetriminoType) / 200 + 55;
	tetris->tetriminoColor = (SDL_Color){random / 4, random / 3, random / 2, 255};

	

	while (!stop)
	{
		while (SDL_PollEvent(&(tetris->sdl.e)))
		{
			if (tetris->sdl.e.type == SDL_QUIT || tetris->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				stop = 1;
			else if (tetris->sdl.e.type == SDL_KEYDOWN)
			{
//				if (tetris->sdl.e.key.keysym.sym == SDLK_SPACE)
//				{
//					putTextMessage(tetris, "Pause");
//					tetris->pause = (tetris->pause == 1) ? 0 : 1;
//				}
//				else
				if (tetris->sdl.e.key.keysym.sym == SDLK_UP)
				{
					if (tetris->tetriminoType % 4 == 3)
						tetris->tetriminoType = (tetris->tetriminoType / 4) * 4;
					else
						tetris->tetriminoType++;
				}
				
				else if (tetris->sdl.e.key.keysym.sym == SDLK_DOWN)
					delay = 50;
				else if (tetris->sdl.e.key.keysym.sym == SDLK_RIGHT && checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x + 1, tetris->tetriminoPos.y} ) == 1)
					tetris->tetriminoPos.x++;
				else if (tetris->sdl.e.key.keysym.sym == SDLK_LEFT && checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x - 1, tetris->tetriminoPos.y} ) == 1)
					tetris->tetriminoPos.x--;
			}

		}
		printf("%d\n", tetris->tetriminoType);
		
		sdlRenderClear(tetris);
		
		if (checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x, tetris->tetriminoPos.y + 1} ) == 1)
		{
			tetris->tetriminoPos.y++;
			
			putTetrimino(tetris);
			
			drawMap(tetris);
			
			killTetrimino(tetris);
		}
		else
		{
			saveTetrimino(tetris);
			deleteLine(tetris);
			tetris->tetriminoPos = (t_pos){1, 1};
			tetris->tetriminoType = rand() % 12;
			random = (rand() * tetris->tetriminoType) / 200 + 55;
			tetris->tetriminoColor = (SDL_Color){75, random / 3, random / 2, 255};
		}

		
		SDL_RenderPresent(tetris->sdl.renderer);
		SDL_Delay(delay);
		delay = 500;

		
	}
	sdlDestroy(tetris);
	return 0;
}
