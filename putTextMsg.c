
#include "tetris.h"

void	putTextMessage(t_tetris *tetris, char *str, SDL_Rect rect)
{
	tetris->sdl.surfaceScoreLines = TTF_RenderText_Solid(tetris->sdl.font, str, (SDL_Color){255, 255, 255, 255});
	tetris->sdl.textureScoreLines = SDL_CreateTextureFromSurface(tetris->sdl.renderer, tetris->sdl.surfaceScoreLines);
	SDL_RenderCopy(tetris->sdl.renderer, tetris->sdl.textureScoreLines, NULL, &(rect));
	SDL_DestroyTexture(tetris->sdl.textureScoreLines);
	SDL_FreeSurface(tetris->sdl.surfaceScoreLines);
}
