##
## EPITECH PROJECT, 2022
## task01
## File description:
## makefile
##

SRC	=	src/generator.c \
		src/my_getnbr.c \
		src/my_str_compare.c \
		src/perfect_maze.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -Iinclude

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

debug: fclean
		gcc -o $(NAME) $(SRC) -g3 -Iinclude
