
#ifndef snake_h
#define snake_h

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <SDL2/SDL.h>
//# include <SDL2_ttf/SDL_ttf.h>
//# include <SDL2_image/SDL_image.h>
# define WID 12*30
# define HEIG 22*30
# define W WID / 30
# define H HEIG / 30

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer		*renderer;
	SDL_Event		e;

	
//	SDL_Surface		*surfaceScore;
//	SDL_Rect			rectScore;
//	SDL_Texture		*textureScore;
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
	t_pos			tetrimino[4];
	t_pos			tetriminoPreviousPos[4];
	int				tetriminoType;

	
	
	
}					t_tetris;



void	sdlInit(t_tetris *tetris);
void	sdlDestroy(t_tetris *tetris);
void	sdlRenderClear(t_tetris *tetris);


#endif
