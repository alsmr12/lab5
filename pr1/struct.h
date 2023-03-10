#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>

typedef struct {
    char *fio;
    char ps[8];
    int age;
} el;

void el_print(const el *e, FILE *f);
void el_array_print(const el *arr, int len, FILE *f);
int el_array_input(el **arr, int *len, FILE *f);
void arr_free(el *arr, int len);

#endif
