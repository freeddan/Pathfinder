#include "../inc/pathfinder.h"


void mx_line_next_validation(char *string) {
    for (int line = 2; *string != '\0'; string++) {
        for ( ; *string != '-'; string++)
            if (!mx_isalpha(*string)){
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(line));
            mx_printerr(" is not valid\n");
            exit(-1);
        }

        if (*string == '-' && !mx_isalpha(*(string - 1)) && !mx_isalpha(*(string + 1)))
        {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(line));
            mx_printerr(" is not valid\n");
            exit(-1);
        }
        // mx_print_errline(path, line);
        string++;
        for (; *string != ','; string++)
            if (!mx_isalpha(*string))
            {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(line));
                mx_printerr(" is not valid\n");
                exit(-1);
            }
        // mx_print_errline(path, line);
        if (*string == ',' && !mx_isalpha(*(string - 1)) && !mx_isdigit(*(string + 1)))
        {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(line));
            mx_printerr(" is not valid\n");
            exit(-1);
        }
        // mx_print_errline(path, line);
        string++;

        for ( ; *string != '\n'; string++)
            if (!mx_isdigit(*string) || mx_atol(string) > INT_MAX){
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(line));
            mx_printerr(" is not valid\n");
            exit(-1);
        }
                // mx_print_errline(path, line);
            line++;
    }
}


