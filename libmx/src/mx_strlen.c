#include "libmx.h"

int mx_strlen(const char *s) {
    if(!s) return 0;
    int count = 0;
    
    while (s[count])
        count++;
    return count;
}

