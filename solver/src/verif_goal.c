/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-camille.erades
** File description:
** verif_goal.c
*/

#include "../include/my.h"

bool verif_goal(int **numMaze, max_t max, int **solution)
{
    if (max.x[0] == max.i[0] - 1 && max.y[0] == max.j[0] - 1 &&
        numMaze[max.x[0]][max.y[0]] == 2){
        solution[max.x[0]][max.y[0]] = 2;
        return true;
    }
    return false;
}
