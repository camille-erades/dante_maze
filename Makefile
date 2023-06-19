##
## EPITECH PROJECT, 2022
## task01
## File description:
## makefile
##

all:
		make -C solver/
		make -C generator/
clean:
		make clean -C solver/
		make clean -C generator/

fclean:
		make fclean -C solver/
		make fclean -C generator/

re:		fclean all

debug: fclean
		make debug -C solver/
		make debug -C generator/
