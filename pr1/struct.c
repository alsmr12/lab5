#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

char *freadline(FILE *f) {
    char buf[81];
    char *str = NULL;
    int len = 0, t;
    do {
        t = fscanf(f, "%80[^\n]", buf);
        if (t == -1) {
            return NULL;
        }
        else if (t == 0) fscanf(f, "%*c");
        else {
            int len_buf = strlen(buf);
            str = (char *)realloc(str, (len + len_buf + 1) * sizeof(char));
            memcpy(str + len, buf, len + len_buf);
            len = len + len_buf;
        }
    } while ((t > 0));
    if (len == 0) str = (char *)malloc(1 * sizeof(char));
    str[len] = '\0';
    return str;
}


void el_print(const el *e, FILE *f) {
    fprintf(f, "%s, %s, %d\n", e -> fio, e -> ps, e -> age);
}

void el_array_print(const el *arr, int len, FILE *f) {
    for (int i = 0; i < len; ++i) {
        el_print(arr + i, f);
    }
}

int el_array_input(el **arr, int *len, FILE *f) {
    *len = 0;
    int t = 1;
    while (t > 0) {
        ++(*len);
        *arr = (el *)realloc(*arr, *len * sizeof(el));
        ((*arr)[*len - 1].fio) = freadline(f);
        if (((*arr)[*len - 1].fio) == NULL) break;
        fscanf(f, "%8[^\n]%*c", ((*arr)[*len - 1].ps));
        t = fscanf(f, "%d", &((*arr)[*len - 1].age));
        fscanf(f, "%*c");
        if (t != 1) return 1;
    }
    --(*len);
    *arr = (el *)realloc(*arr, *len * sizeof(el));
    return 0;
}

void arr_free(el *arr, int len) {
    for (int i = 0; i < len; i++) {
        free(arr[i].fio);
    }
    free(arr);
}
