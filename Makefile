
NAME = tetris

CC = gcc

CFLAGS =  -F. -Wall -Werror -Wextra

SDL_FLAGS = -framework SDL2 -framework SDL2_ttf

OBJ = deleteLine.o initSdl.o putTetrimino.o drawMap.o intro.o putTextMsg.o drawNextTetrimino.o main.o

HEADER = tetris

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC)  $^ $(CFLAGS) $(SDL_FLAGS) -o $@

clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

sdl2:
	cp -r SDL2_ttf.framework ~/Library/Frameworks/
	cp -r SDL2.framework ~/Library/Frameworks/

