##
## EPITECH PROJECT, 2022
## task01
## File description:
## makefile
##

SRC	=	src/solver.c \
		src/my_str_to_word_array.c \
		src/errors.c \
		src/my_strlen.c \
		src/transform_maze.c \
		src/show_soluc.c \
		src/verif_goal.c \
		src/my_free.c \
		src/multi_free.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

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
