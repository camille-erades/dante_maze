/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_strlen.c
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return (i);
}
