/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-quentin.charillon
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int i;
    int cmp;

    cmp = 0;
    i = 0;
    while (*str == '+' || *str == '-'){
        if (*str == '-'){
            i++;
        }
        str++;
    }
    while (*str >= '0' && *str <= '9' ){
        cmp = cmp * 10 + *str++ - '0';
    }
        if (i % 2 == 1){
        cmp *= -1;
    }
    return (cmp);
}
