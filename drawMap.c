
#include "tetris.h"

void	drawMap(t_tetris *tetris)
{
	extern int	map[H][W];
	extern int	tetrimino[12][5][5];
	
	


	SDL_Rect  rect;
	rect = (SDL_Rect) {0, 0, WIDOFCUBE, WIDOFCUBE};
	for (int y = 0; y < H; y++)
	{
		rect.x = 0;
		for (int x = 0; x < W; x++)
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
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
			else if (map[y][x] == 3) // saved tetrimino on map
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 75, 50, 50, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
			else if (map[y][x] == 9) // tetrimino
			{
				
				SDL_SetRenderDrawColor(tetris->sdl.renderer, tetris->tetriminoColor.r, tetris->tetriminoColor.g, tetris->tetriminoColor.b, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
//			printf("%d ",map[y][x]);

			rect.x += WIDOFCUBE;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
//		printf("\n");
		rect.y += WIDOFCUBE;
	}

}

void	putTextMessage(t_tetris *tetris, char *str, SDL_Rect rect)
{
	tetris->sdl.font = TTF_OpenFont("arcadeclassic/ARCADECLASSIC.TTF", 22);
	tetris->sdl.surfaceScoreLines = TTF_RenderText_Solid(tetris->sdl.font, str, (SDL_Color){255, 255, 255, 255});
	tetris->sdl.textureScoreLines = SDL_CreateTextureFromSurface(tetris->sdl.renderer, tetris->sdl.surfaceScoreLines);
//	tetris->sdl.rectScoreLines.x = WID - INFO + WIDOFCUBE + 25;
//	tetris->sdl.rectScoreLines.y = 0;
//	tetris->sdl.rectScoreLines.w = INFO / 2;
//	tetris->sdl.rectScoreLines.h = WIDOFCUBE;
	
	SDL_RenderCopy(tetris->sdl.renderer, tetris->sdl.textureScoreLines, NULL, &(rect));
	
}

void	drawNextTetrimino(t_tetris *tetris)
{
	extern int	tetrimino[12][5][5];
	
	putTextMessage(tetris, "NEXT", (SDL_Rect){WID - INFO + WIDOFCUBE + 25, 0, INFO / 2, WIDOFCUBE});
	
	
	
	SDL_Rect  rect;
	rect = (SDL_Rect) {0, WIDOFCUBE, WIDOFCUBE, WIDOFCUBE};
	for (int y = 0; y < 5; y++)
	{
		rect.x = WID - INFO + WIDOFCUBE;
		for (int x = 0; x < 5; x++)
		{
			if (tetrimino[tetris->nextTetrimino][y][x] == 0) // empty place
			{
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
			else if (tetrimino[tetris->nextTetrimino][y][x] == 9)
			{
				
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 70, 70, 70, 255);
				SDL_RenderFillRect(tetris->sdl.renderer, &rect);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(tetris->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderDrawRect(tetris->sdl.renderer, &rect);
			}
			rect.x += WIDOFCUBE;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
	
		rect.y += WIDOFCUBE;
	}
}

void	setLivesLevel(t_tetris *tetris)
{
	char buf[50] = {0};
	
	strcat(buf, "Lines ");
	SDL_itoa(tetris->scoreLines, buf + 6, 10);
	tetris->sdl.font = TTF_OpenFont("arcadeclassic/ARCADECLASSIC.TTF", 22);
	tetris->sdl.surfaceScoreLines = TTF_RenderText_Solid(tetris->sdl.font, buf, (SDL_Color){255, 255, 255, 255});
	tetris->sdl.textureScoreLines = SDL_CreateTextureFromSurface(tetris->sdl.renderer, tetris->sdl.surfaceScoreLines);
	tetris->sdl.rectScoreLines.x = WID - INFO + WIDOFCUBE;
	tetris->sdl.rectScoreLines.y = WIDOFCUBE * 7;
	tetris->sdl.rectScoreLines.w = 150;
	tetris->sdl.rectScoreLines.h = WIDOFCUBE;
	
	SDL_RenderCopy(tetris->sdl.renderer, tetris->sdl.textureScoreLines, NULL, &(tetris->sdl.rectScoreLines));
}




