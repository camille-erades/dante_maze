/*
** EPITECH PROJECT, 2022
** solver
** File description:
** errors.c
*/

#include "../include/my.h"

int maze_countline(char **maze)
{
    int i = 0;
    for (i; maze[i] != NULL; i++);
    return i;
}

bool bad_char_error(char *buffer)
{
    for (int z = 1; buffer[z] != '\0'; z++){
        if (buffer[z] != '*' && buffer[z] != 'X' && buffer[z] != '\n'){
            return (false);
        }
        return (true);
    }
    return true;
}

int is_strt_n_fnsh_blocked(char **maze)
{
    int x = maze_countline(maze);
    int y = 0;
    y = strlen(maze[0]);
    if (maze[0][0] == 'X' || maze[x - 1][y - 1] == 'X')
        return -1;
    return 0;
}
