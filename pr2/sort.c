#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "sort.h"

int el_cmp_age_increasing(const el *p1, const el *p2) {
    return (p1->age) - (p2->age);
}

int el_cmp_fio_increasing(const el *p1, const el *p2) {
    return strcmp(p1 -> fio, p2 -> fio);
}

int el_cmp_ps_increasing(const el *p1, const el *p2) {
    return strcmp(p1 -> ps, p2 -> ps);
}
int el_cmp_age_decreasing(const el *p1, const el *p2) {
    return (p2 -> age) - (p1 -> age);
}

int el_cmp_fio_decreasing(const el *p1, const el *p2) {
    return strcmp(p2 -> fio, p1 -> fio);
}

int el_cmp_ps_decreasing(const el *p1, const el *p2) {
    return strcmp(p2 -> ps, p1 -> ps);
}

void *chouse_cmp(char *field, char *dir) {
    if (field != NULL && dir != NULL) {
        if (strcmp(field, "age") == 0 && strcmp(dir, "inc") == 0) return el_cmp_age_increasing;
        if (strcmp(field, "fio") == 0 && strcmp(dir, "inc") == 0) return el_cmp_fio_increasing;
        if (strcmp(field, "ps") == 0 && strcmp(dir, "inc") == 0) return el_cmp_ps_increasing;
        if (strcmp(field, "age") == 0 && strcmp(dir, "dec") == 0) return el_cmp_age_decreasing;
        if (strcmp(field, "fio") == 0 && strcmp(dir, "dec") == 0) return el_cmp_fio_decreasing;
        if (strcmp(field, "ps") == 0 && strcmp(dir, "dec") == 0) return el_cmp_ps_decreasing;
      }
      return el_cmp_age_increasing;
}
void *chouse_sort(int numsort) {
    switch(numsort) {
        case '3':
            printf("\nСортировка вставками\n");
            return insert_sort;
        case '2':
            printf("\nСортировка расчёской\n");
            return comb_sort;
        case '1':
            printf("\nБиблиотечный qsort\n");
            return (void (*)(el *, size_t,  size_t,  int (*)(const el *, const el *)))qsort;
        default:    
            printf("\nАлгоритм сортировки не обозначен.\nБиблиотечный qsort использован по умолчанию\n");
            break;
    }   
    return (void (*)(el *, size_t,  size_t,  int (*)(const el *, const el *)))qsort;
} 

void comb_sort(el *arr, size_t size, size_t size_el, int (*cmp)(const el*, const el*)) {
    int gap = size;
    int c = 1;
    int i, j;
    while (gap > 1 || c == 1) {
        gap = gap - 1;
        if (gap < 1)
            gap = 1;
        c = 0;
        for (i = 0; i < size - gap; ++i) {
            j = i + gap;
            if (cmp(&(arr[i]), &(arr[j])) > 0) { 
                el tmp = arr[i];  // написать swap
                arr[i] = arr[j];
                arr[j] = tmp;
                c = 1;
            }
        }
    }
}

void insert_sort(el *arr, size_t size, size_t size_el, int (*cmp)(const el*, const el*)) {
    int i, j;
    el tmp;
    for (i = 1; i < size; ++i)
    {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && cmp(arr + j, &tmp) > 0; --j) 
            arr[j + 1] = arr[j];   
        arr[j + 1] = tmp;
    }
}

