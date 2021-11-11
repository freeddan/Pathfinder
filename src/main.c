#include "../inc/pathfinder.h"


int main(int argc, char *argv[]){
    (void)argv;
    if(argc != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        return -1;
    }
    int num = 1;
    t_finder *path = (t_finder *)malloc(sizeof(t_finder));
    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(-1);
    }
    char *file = mx_file_to_str(argv[1]);
    if(mx_strlen(file) == 0){
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(-1);
    }
    int length = mx_atoi(file);
    char *temp = mx_strdup(file);
    while(*temp != '\n'){
        if(!mx_isdigit(*temp)){
            mx_printerr("error: line 1 is not valid\n");
            exit(-1);
        }
        temp++;
    }
    temp++;
    char *check = mx_strdup(temp);
    mx_line_next_validation(temp);
   
    path->n_islands = mx_atoi(file);
    path->file_str = mx_strdup(file);
    for (int i = 0; file[i] != '\0'; i++)
        if (file[i] == ',' || file[i] == '\n' || mx_isdigit(file[i]))
            file[i] = '-';
    path->phrase = mx_count_words(file, '-');
    path->unique = (char **)malloc(sizeof(char *) * path->phrase);
    path->islands = mx_strsplit(file, '-');
    path->unique[0] = mx_strdup(path->islands[0]);
    for (int i = 1; i < path->phrase; i++) {
        for (int j = 0; j < num; ) {
            if (!mx_strcmp(path->unique[j], path->islands[i]))
                break;
            if (++j == num)
                path->unique[num++] = mx_strdup(path->islands[i]);
        }
    }
    for(; path->unique[length]; length++);
    if(length != path->n_islands){
        mx_printerr("error: invalid number of islands\n");
        exit(-1);
    }
    int index = 0;
    unsigned long res = 0;
    while((index = mx_get_char_index(check, ',')) > 0){
        check += index;
        check++;
        int x = mx_atoi(check);
        res += x;
        if (res > INT_MAX){
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(-1);
        }
    }
    mx_matrix_init(path, matrix);
    mx_floyd_algorithm(path, matrix);
    mx_results(path, matrix);
    mx_del_strarr(&path->unique);
    mx_del_strarr(&path->islands);
    mx_matrix_memory(path, matrix);
    mx_clean_memory(path);

    return 0;
}

