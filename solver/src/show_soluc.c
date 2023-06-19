/*
** EPITECH PROJECT, 2022
** solver
** File description:
** show_soluc.c
*/

#include "../include/my.h"

void fill_path(int i, int j, int **sol, char **maze)
{
    if (sol[i][j] == 2)
        maze[i][j] = 'o';
}

void show_solution (int **sol, max_t max, char **maze)
{
    int a = 0;
    char *final_maze = malloc(sizeof(char) * ((max.i[0] + 1) * max.j[0]));
    for (int i = 0; i < max.i[0]; i++){
        for (int j = 0; j < max.j[0]; j++)
            fill_path(i, j, sol, maze);
    }
    for (int i = 0; i < max.i[0]; i++){
        for (int j = 0; j < max.j[0]; j++, a++){
            final_maze[a] = maze[i][j];
        }
        final_maze[a++] = '\n';
    }
    final_maze[a - 1] = '\0';
    write(1, final_maze, a - 1);
}
