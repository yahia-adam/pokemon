
SRC	=	src/main.c \
		src/read_file.c \
		src/write_in_file.c\
		src/mapGenerator.c\
		src/player.c\
		src/game.c\
		src/move.c\

OBJ	=	$(SRC:.c=.o)

BINARY_NAME	=	pokemon

INCLUDE	=	include/

CPPFLAGS	=	-I ./$(INCLUDE)

all:		NAME

NAME:		$(OBJ)
			gcc $(OBJ) -o $(BINARY_NAME) $(CPPFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BINARY_NAME)

re:			fclean all
			rm -f $(OBJ)
