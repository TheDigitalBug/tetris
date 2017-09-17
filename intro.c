
#include "tetris.h"

void	intro(t_tetris *tetris, int *introflag)
{
	sdlRenderClear(tetris);
	putTextMessage(tetris, "TETRIS", (SDL_Rect){(WID - INFO) / 2, HEIG / 2 - WIDOFCUBE, INFO, WIDOFCUBE * 2});
	SDL_RenderPresent(tetris->sdl.renderer);
	sdlRenderClear(tetris);
	SDL_Delay(1500);
	*introflag = 1;
}
