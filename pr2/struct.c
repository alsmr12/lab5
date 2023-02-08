#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

void el_print(const el *e, FILE *f) {
    fprintf(f, "%s, %s, %d\n", e -> fio, e -> ps, e -> age);
}

void el_array_print(const el *arr, int len, FILE *f) {
    int i;
    for (i = 0; i < len; ++i) {
        el_print(arr + i, f);
    }
}

void el_array_input(el **arr, int len) {
    *arr = (el *)malloc(len * sizeof(el));
    char *s = NULL;
    for (int i = 0; i < len; i++) {
        s = (char *)malloc(11 * sizeof(char));
        for (int j = 0; j < 10; j++) {
            s[j] = (char)(rand() % 26 + 97);
        }
        s[10] = '\0';
        ((*arr)[i]).fio = s;
        for (int j = 0; j < 3; j++) {
            ((*arr)[i].ps)[j] = (char)(rand() % 26 + 97);
        }
        ((*arr)[i].ps)[3] = '-';
        for (int j = 4; j < 7; j++) {
            ((*arr)[i].ps)[j] = rand() % 9 + 48;
        }
        ((*arr)[i].ps)[7] = '\0';
        (*arr)[i].age = rand() % 100 + 18;
    }
}

void free_arr(el **arr, int len) {
    for (int i = 0; i < len; i++) {
        free((*arr)[i].fio);
    }
    free(*arr);
}
