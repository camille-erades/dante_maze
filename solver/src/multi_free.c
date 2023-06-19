/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-camille.erades
** File description:
** multi_free.c
*/

#include "../include/my.h"

void multi_free(char *str, max_t max)
{
    free(str);
    free(max.i);
    free(max.j);
    free(max.x);
    free(max.y);
}
