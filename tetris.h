
#ifndef snake_h
#define snake_h

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# include <SDL2_ttf/SDL_ttf.h>
# define W 12
# define H 22
# define INFO 210
# define WIDOFCUBE 30
# define WID W * 30 + INFO
# define HEIG H * 30

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer		*renderer;
	SDL_Event		e;
	TTF_Font			*font;
	SDL_Surface		*surfaceScoreLines;
	SDL_Rect			rectScoreLines;
	SDL_Texture		*textureScoreLines;
}					t_sdl;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_tetris
{
	t_sdl			sdl;
	t_pos			tetriminoPos;
	int				tetriminoType;
	SDL_Color		tetriminoColor;
	int				nextTetrimino;
	int				score;
	int				scoreLines;
	int				pause;
}					t_tetris;

void					sdlInit(t_tetris *tetris);
void					sdlDestroy(t_tetris *tetris);
void					sdlRenderClear(t_tetris *tetris);

int					checkTetrimino(t_tetris *tetris, t_pos pos);
void					putTetrimino(t_tetris *tetris);
void					killTetrimino(t_tetris *tetris);
void					saveTetrimino(t_tetris *tetris);

void					putTextMessage(t_tetris *tetris, char *str, SDL_Rect rect);
void					drawNextTetrimino(t_tetris *tetris);

void					drawMap(t_tetris *tetris);
void					deleteLine(t_tetris *tetris);
void					setLivesLevel(t_tetris *tetris);

void					intro(t_tetris *tetris, int *intro);
#endif
