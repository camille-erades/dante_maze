/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-camille.erades
** File description:
** my_str_to_word_array.c
*/

#include "../include/my.h"

int countline(char *str, char separator)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == separator && str[i + 1] == '\0')
            continue;
        if (str[i] == separator)
            j++;
    }
    return j + 1;
}

char **mallocline(char *str, char **arr, char separator)
{
    int charnum = 0;
    int linenum = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == separator && str[i + 1] == '\0')
            continue;
        if (str[i] == separator){
            arr[linenum] = malloc(sizeof(char) * (charnum));
            linenum++;
            charnum = 0;
        }
        charnum++;
    }
    arr[linenum] = malloc(sizeof(char) * (charnum));
    arr[linenum + 1] = NULL;
}

char **my_str_to_word_array(char *str, char separator)
{
    char **arr = malloc(sizeof(char *) * (countline(str, separator) + 1));
    int j = 0, i = 0, x = 0;
    mallocline(str, arr, separator);
    for (; arr[x] != NULL; x++){
        while (str[i] != separator && str[i] != '\0'){
            arr[x][j] = str[i];
            j++;
            i++;
        }
        arr[x][j] = '\0';
        j = 0;
        i++;
    }
    return arr;
}
