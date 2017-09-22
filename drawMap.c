
#include "tetris.h"

void	drawMap(t_tetris *tetris)
{
	extern int	map[H][W];
	extern int	tetrimino[24][5][5];
	SDL_Rect		rect;
	int			x;
	int			y;

	rect = (SDL_Rect) {0, 0, WIDOFCUBE, WIDOFCUBE};
	for (y = 0; y < H; y++)
	{
		rect.x = 0;
		for (x = 0; x < W; x++)
		{
			if (map[y][x] == 0) // empty place
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
			else if (map[y][x] == 1) // wall
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
			}
			else if (map[y][x] == 3) // saved tetrimino on map
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 75, 50, 50, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 40, 40, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &((SDL_Rect) {rect.x + 4, rect.y + 4, WIDOFCUBE-8, WIDOFCUBE-8}));
			}
			else if (map[y][x] == 9) // tetrimino
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, tetris->tetriminoColor.r, tetris->tetriminoColor.g, tetris->tetriminoColor.b, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(tetris->sdl.renderer, tetris->tetriminoColor.r * 0.8, tetris->tetriminoColor.g * 0.8, tetris->tetriminoColor.b * 0.8, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &((SDL_Rect) {rect.x + 4, rect.y + 4, WIDOFCUBE - 8, WIDOFCUBE - 8}));
				SDL_SetRenderDrawColor(tetris->sdl.renderer, tetris->tetriminoColor.r * 0.4, tetris->tetriminoColor.g * 0.4, tetris->tetriminoColor.b * 0.4, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &((SDL_Rect) {rect.x + 12, rect.y + 12, WIDOFCUBE - 24, WIDOFCUBE - 24}));
			}
			SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
			SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			rect.x += WIDOFCUBE;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
		rect.y += WIDOFCUBE;
	}
}

void	setLivesLevel(t_tetris *tetris)
{
	char buf[50] = "Lines ";

	sprintf(buf + 6, "%d", tetris->scoreLines);
	tetris->sdl.surfaceScoreLines = TTF_RenderText_Solid(tetris->sdl.font, buf, (SDL_Color){255, 255, 255, 255});
	tetris->sdl.textureScoreLines = SDL_CreateTextureFromSurface(tetris->sdl.renderer, tetris->sdl.surfaceScoreLines);
	tetris->sdl.rectScoreLines.x = WID - INFO + WIDOFCUBE;
	tetris->sdl.rectScoreLines.y = WIDOFCUBE * 7;
	tetris->sdl.rectScoreLines.w = 150;
	tetris->sdl.rectScoreLines.h = WIDOFCUBE;
	SDL_RenderCopy(tetris->sdl.renderer, tetris->sdl.textureScoreLines, NULL, &(tetris->sdl.rectScoreLines));
	SDL_DestroyTexture(tetris->sdl.textureScoreLines);
	SDL_FreeSurface(tetris->sdl.surfaceScoreLines);
}
