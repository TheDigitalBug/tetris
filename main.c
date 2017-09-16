
#include "tetris.h"


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
	
	tetris->tetriminoPos = (t_pos){5, 1};
	tetris->tetriminoType = 1;
	

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
//				if (tetris->sdl.e.key.keysym.sym == SDLK_UP)
//					tetris->tetriminoPos = (t_pos){0, -1};
//				else
					if (tetris->sdl.e.key.keysym.sym == SDLK_DOWN)
					delay = 200;
				else if (tetris->sdl.e.key.keysym.sym == SDLK_RIGHT && tetris->tetriminoPos.x < 9)
				{
					printf("%d", tetris->tetriminoPos.x);
					tetris->tetriminoPos.x++;
				}
				else if (tetris->sdl.e.key.keysym.sym == SDLK_LEFT && tetris->tetriminoPos.x > 1)
					tetris->tetriminoPos.x--;
			}

		}
		
		sdlRenderClear(tetris);
		
		if (tetris->tetriminoType == 1)
			putTetriminoCube(tetris);
		
		drawMap(tetris);
		
		
		SDL_RenderPresent(tetris->sdl.renderer);
		SDL_Delay(delay);
		delay = 500;
		tetris->tetriminoPos.y++;
		
	}
	sdlDestroy(tetris);
	return 0;
}
