#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

void el_print(const el *e, FILE *f) {	
    fprintf(f, "%s, %s, %d\n", e -> fio, e -> ps, e -> age);
}

void el_array_print(const el *arr, int len, FILE *f) {
    for (int i = 0; i < len; ++i) {
        el_print(arr + i, f);
    }
}

void el_array_input(el **arr, int *len, FILE *f) {
    *len = 0;
    int t = 3;
    while (t == 3) {
        ++(*len);
        *arr = (el *)realloc(*arr, *len * sizeof(el));
        t = fscanf(f, "%s%s%d", ((*arr)[*len - 1].fio), ((*arr)[*len - 1].ps), &((*arr)[*len - 1].age));
    }
    --(*len);
    *arr = (el *)realloc(*arr, *len * sizeof(el));
}
