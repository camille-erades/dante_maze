/*
** EPITECH PROJECT, 2022
** solver
** File description:
** solver.c
*/

#include "../include/my.h"

bool look_safety(int **numMaze, max_t max)
{
    if (max.x[0] >= 0 && max.x[0] < max.i[0] && max.y[0] >= 0 &&
    max.y[0] < max.j[0] && numMaze[max.x[0]][max.y[0]] == 2)
        return true;
    return false;
}

bool prepare_solution(int **numMaze, max_t max, int **solution)
{
    if (verif_goal(numMaze, max, solution) == true) return true;
    if (look_safety(numMaze, max) == true) {
        if (solution[max.x[0]][max.y[0]] == 2) return false;
        solution[max.x[0]][max.y[0]] = 2;
        max.x[0] += 1;
        if (solve_maze(numMaze, max, solution) == true) return true;
        max.x[0] -= 1;
        max.y[0] += 1;
        if (solve_maze(numMaze, max, solution) == true) return true;
        max.y[0] -= 1;
        max.x[0] -= 1;
        if (solve_maze(numMaze, max, solution) == true) return true;
        max.x[0] += 1;
        max.y[0] -= 1;
        if (solve_maze(numMaze, max, solution) == true) return true;
        max.y[0] += 1;
        solution[max.x[0]][max.y[0]] = 1;
        return false;
    }
    return false;
}

bool solve_maze(int **numMaze, max_t max, int **solution)
{
    if (prepare_solution(numMaze, max, solution) == false){
        return false;
    }
    return true;
}

bool resolve_maze(char **maze, max_t max)
{
    int **numMaze = malloc(sizeof(int *) * max.i[0] + 1);
    int **solution = malloc(sizeof(int *) * max.i[0] + 1);
    for (int c = 0; c <= max.i[0]; c++){
        numMaze[c] = malloc(sizeof(int) * max.j[0]);
        solution[c] = malloc(sizeof(int) * max.j[0]);
    }
    for (int a = 0; maze[a] != NULL; a++){
        for (int b = 0; maze[a][b] != '\0'; b++){
            numMaze[a][b] = transform_maze(maze[a][b]);
            solution[a][b] = 1;
        }
    }
    if (solve_maze(numMaze, max, solution) == true){
        show_solution(solution, max, maze);
        super_free(maze, numMaze, solution);
        return true;
    }
    super_free(maze, numMaze, solution);
    return false;
}

int main(int argc, char **argv)
{
    max_t max;
    max.i = malloc(sizeof(int) * 100000); max.j = malloc(sizeof(int) * 100000);
    max.x = malloc(sizeof(int) * 100000); max.y = malloc(sizeof(int) * 100000);
    char *buffer = NULL;
    char **maze = NULL;
    struct stat buf;
    int fd = open(argv[1], O_RDONLY);
    stat(argv[1], &buf);
    buffer = malloc(sizeof(char) * (buf.st_size + 1));
    if (buf.st_size <= 0) return 84;
    read(fd, buffer, (buf.st_size + 1));
    if (!bad_char_error(buffer)) return 84;
    maze = my_str_to_word_array(buffer, '\n');
    max.i[0] = maze_countline(maze); max.x[0] = 0;
    max.j[0] = strlen(maze[0]); max.y[0] = 0;
    if (is_strt_n_fnsh_blocked(maze) == -1 || resolve_maze(maze, max) == false)
        printf("no solution found");
    multi_free(buffer, max); return 0;
}
