/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-camille.erades
** File description:
** perfect_maze.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int carv_perf(char **maze, int x, int y)
{
    static int por = 2;
    static int old_x = 0;
    int choice = rand() % 5;
    int nb = por + ((y > 0) ? rand() % y: 0);

    if (old_x != x) {
        old_x = x;
        por = 2;
    }
    if (choice == 1 && y < strlen(maze[0]) - 2){
        maze[x][y + 1] = 'X';
        maze[x - 1][nb - ((nb % 2) != 0)] = '*';
        por = y + 2;
    }
    if (!(strlen(maze[0]) % 2) && y == (strlen(maze[0]) - 2) &&
    maze[x][y + 1] != 'X')
        maze[x - 1][y] = '*';
}

int perf_algo_perf(char **maze, int x, int y)
{
    int i, j, a, b = 0;
    srand(time(NULL));
    
    for (i = 2; i < x; i += 1)
        for (j = 0; j < y; j += 1)
            carv_perf(maze, i, j);
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

int create_perfect_maze(int x, int y)
{
    char **maze = malloc(sizeof(char *) * x + 1);
    for (int i = 0; i < x; i++)
        maze[i] = malloc(sizeof(char) * y + 1);
    for (int a = 0; maze[a] != NULL; a++){
        for (int b = 0; b < y; b++)
            maze[a][b] = '*';
        maze[a][y + 1] = '\0';
    }
    for (int a = 1; maze[a] != NULL; a += 2){
        for (int b = 0; b < y; b++)
            maze[a][b] = 'X';
        maze[a][y + 1] = '\0';
    }
    maze[x + 1] = NULL;
    if (perf_algo_perf(maze, x, y) == 1){
        return 1;
    }
    return 0;
}
