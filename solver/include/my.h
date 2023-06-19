/*
** EPITECH PROJECT, 2022
** solver
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <string.h>
    #include <stddef.h>
    typedef struct max_val {
        int *x;
        int *y;
        int *i;
        int *j;
    } max_t;
    bool resolve_maze(char **maze, max_t max);
    bool solve_maze(int **numMaze, max_t max, int **solution);
    bool look_safety(int **numMaze, max_t max);
    void show_solution (int **sol, max_t max, char **maze);
    int transform_maze(char maze);
    int is_strt_n_fnsh_blocked(char **maze);
    bool bad_char_error(char *buffer);
    int my_strlen(char const *str);
    char **my_str_to_word_array(char *str, char separator);
    char **mallocline(char *str, char **arr, char separator);
    int countline(char *str, char separator);
    int maze_countline(char **maze);
    bool prepare_solution(int **numMaze, max_t max, int **solution);
    void fill_path(int i, int j, int **sol, char **maze);
    bool verif_goal(int **numMaze, max_t max, int **solution);
    void super_free(char **tabl, int **numtab1, int **numtab2);
    void multi_free(char *str, max_t max);
#endif /* !MY_H_ */
