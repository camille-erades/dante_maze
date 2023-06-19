/*
** EPITECH PROJECT, 2022
** solver
** File description:
** generator.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int my_getnbr(char const *str);
int create_perfect_maze(int x, int y);

int carv(char **maze, int x, int y)
{
    int choice = rand() % 2;
    if (x == 0){
        maze[x][y] = '*';
        return 0;
    } else if (y == 0){
        maze[x][y] = '*';
        maze[x][y] = '*';
        return 0;
    }
    if (choice == 0)
        maze[x][y - 1] = '*';
    if (choice == 1)
        maze[x - 1][y] = '*';
    return 0;
}

int perf_algo(char **maze, int x, int y)
{
    int i, j, a, b = 0;
    srand(time(NULL));
    for (i = 0; i < x; i++)
        for (j = 0; j < y; j++)
            carv(maze, i, j);
    maze[x - 1][y - 1] = '*';
    for (a = 0; maze[a] != NULL; a++){
        if (maze[a + 1] == NULL){
            printf("%s", maze[a]);
            break;
        }
        printf("%s\n", maze[a]);
    }
    return 1;
}

int create_imperfect_maze(int x, int y)
{
    char **maze = malloc(sizeof(char *) * x + 1);
    for (int i = 0; i < x; i++)
        maze[i] = malloc(sizeof(char) * y + 1);
    for (int a = 0; maze[a] != NULL; a++){
        for (int b = 0; b < y; b++)
            maze[a][b] = 'X';
    }
    maze[x + 1] = NULL;
    if (perf_algo(maze, x, y) == 1){
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int x = my_getnbr(argv[2]);
    int y = my_getnbr(argv[1]);
    if (x < 1 || y < 1)
        return 84;
    if (argc == 3){
        create_imperfect_maze(x, y);
        return 0;
    }
    if (argc == 4){
        create_perfect_maze(x, y);
        return 0;
    }
    return 84;
}
