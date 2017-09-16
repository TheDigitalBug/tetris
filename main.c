
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
	
	stop = 0;

	tetris = (t_tetris *)malloc(sizeof(t_tetris));
	sdlInit(tetris);

	while (!stop)
	{
		while (SDL_PollEvent(&(tetris->sdl.e)))
		{
			if (tetris->sdl.e.type == SDL_QUIT || tetris->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				stop = 1;
//			else if (tetris->sdl.e.type == SDL_KEYUP)
//			{
//				if (tetris->sdl.e.key.keysym.sym == SDLK_SPACE)
//				{
//					putTextMessage(tetris, "Pause");
//					tetris->pause = (tetris->pause == 1) ? 0 : 1;
//				}
//				else if (tetris->sdl.e.key.keysym.sym == SDLK_UP)
//					tetris->pacMove = (t_pos){0, -1};
//				else if (tetris->sdl.e.key.keysym.sym == SDLK_DOWN)
//					tetris->pacMove = (t_pos){0, 1};
//				else if (tetris->sdl.e.key.keysym.sym == SDLK_RIGHT)
//					tetris->pacMove = (t_pos){1, 0};
//				else if (tetris->sdl.e.key.keysym.sym == SDLK_LEFT)
//					tetris->pacMove = (t_pos){-1, 0};
//			}
		}

		
			sdlRenderClear(tetris);

			drawMap(tetris);
			SDL_RenderPresent(tetris->sdl.renderer);
			SDL_Delay(250);
		
	}
	sdlDestroy(tetris);
	return 0;
}
