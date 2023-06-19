/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-minishell1-camille.erades
** File description:
** my_free.c
*/


#include <stdlib.h>
#include "../include/my.h"

void super_free(char **tabl, int **numtab1, int **numtab2)
{
    for (int i = 0; tabl[i] != NULL; i++){
        free(numtab1[i]);
        free(numtab2[i]);
    }
    free(numtab1);
    free(numtab2);
}
