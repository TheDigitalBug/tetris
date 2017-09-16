
#include "tetris.h"

int tetrimino[2][5][5] =
{
	{
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,9,0,0},
		{0,0,0,0,0},
	},
	
	{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,9,9,9,9},
		{0,0,0,0,0},
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
	
	tetris->tetriminoPos = (t_pos){1, 1};
	tetris->tetriminoType = rand() % 2;

	

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
					tetris->tetriminoPos = (t_pos){0, -1};
				else if (tetris->sdl.e.key.keysym.sym == SDLK_DOWN)
					delay = 100;
				else if (tetris->sdl.e.key.keysym.sym == SDLK_RIGHT && checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x + 1, tetris->tetriminoPos.y} ) == 1)
					tetris->tetriminoPos.x++;
				else if (tetris->sdl.e.key.keysym.sym == SDLK_LEFT && checkTetrimino(tetris, (t_pos){tetris->tetriminoPos.x - 1, tetris->tetriminoPos.y} ) == 1)
					tetris->tetriminoPos.x--;
			}

		}
		
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
			tetris->tetriminoType = rand() % 2;
		}

		
		SDL_RenderPresent(tetris->sdl.renderer);
		SDL_Delay(delay);
		delay = 500;

		
	}
	sdlDestroy(tetris);
	return 0;
}
