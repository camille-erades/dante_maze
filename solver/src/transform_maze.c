/*
** EPITECH PROJECT, 2022
** solver
** File description:
** transform_maze.c
*/

#include "../include/my.h"

int transform_maze(char maze)
{
    if (maze == '*')
        return 2;
    if (maze == 'X')
        return 1;
}
