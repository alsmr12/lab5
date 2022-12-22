#include <stdio.h>

#define STRUCT_H
#ifdef STRUCT_H

typedef struct {
    char fio[81];
    char ps[8];
    int age;
} el;

void el_print(const el *e, FILE *f);
void el_array_print(const el *arr, int len, FILE *f);
void el_array_input(el **arr, int *len, FILE *f);

#endif
