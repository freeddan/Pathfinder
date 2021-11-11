#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#include <stdbool.h>

#define INT_MAX 2147483647

typedef struct s_finder {
    int fd;  //fd;
    int phrase;  //words;
    int n_islands;
    char *file_str; //file_in_str
    char **unique;  //uniq_isl;
    char **islands; // //
}               t_finder;

typedef struct s_matrix {
    int len; /* len */
    int *pattern; /* route */
    long **first; /* */
    long **map; /* table*/
}         t_matrix;

void mx_line_next_validation(char *string);
void mx_dup_bridges(t_finder *path);
void dup_islands(t_finder *path);
// algorithm

void mx_matrix_init(t_finder *path, t_matrix *matrix); //
void mx_floyd_algorithm(t_finder *path, t_matrix *matrix); //

// result and cleaning

void mx_print_limit();
void mx_results(t_finder *path, t_matrix *matrix); //
void mx_clean_memory(t_finder *path);//
void mx_matrix_memory(t_finder *path, t_matrix *matrix); //


#endif

