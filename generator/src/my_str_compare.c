/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-minishell1-camille.erades
** File description:
** my_str_compare.c
*/

#include <stddef.h>

int my_str_compare(char *str, char *str2)
{
    for (int i = 0; str2[i] != '\0'; i++){
        if (str[i] != str2[i])
            return 0;
    }
    return 1;
}
