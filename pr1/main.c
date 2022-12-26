#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "sort.h"

int main(int argc, char *argv[]) {
    FILE *f1;
    FILE *f2;
    getopt(argc, argv, "i:o:a::f::d::");
    f1 = fopen(optarg, "r");
    getopt(argc, argv, "i:o:a::f::d::");
    f2 = fopen(optarg, "w");
    int numsort = 0;
    char *field = NULL;
    char *dir = NULL;
    int opt;
    while ((opt = getopt(argc, argv, "i:o:a::f::d::")) != -1) {
		switch (opt) {
		    case 'a':
                numsort = (int)*optarg;
                break;
		    case 'f':
                field = optarg;
                break;
		    case 'd':
                dir = optarg;
                break;
            default:
                printf("\n! Была проигнорированна неверно введённая опция\n");
        }
    }

    int (*cmp)(const el*, const el*) = el_cmp_fio_increasing;
    if (field != NULL && dir != NULL) {
        if (strcmp(field, "age") == 0 && strcmp(dir, "inc") == 0) cmp = el_cmp_age_increasing;
        if (strcmp(field, "fio") == 0 && strcmp(dir, "inc") == 0) cmp = el_cmp_fio_increasing;
        if (strcmp(field, "ps") == 0 && strcmp(dir, "inc") == 0) cmp = el_cmp_ps_increasing;
        if (strcmp(field, "age") == 0 && strcmp(dir, "dec") == 0) cmp = el_cmp_age_decreasing;
        if (strcmp(field, "fio") == 0 && strcmp(dir, "dec") == 0) cmp = el_cmp_fio_decreasing;
        if (strcmp(field, "ps") == 0 && strcmp(dir, "dec") == 0) cmp = el_cmp_ps_decreasing;
    }

    el *arr = NULL;
    int len;
    el_array_input(&arr, &len, f1);
    clock_t begin, end;
    switch(numsort) {
        case '3':
            printf("\nСортировка вставками\n");
            begin = clock();
            insert_sort(arr, len, cmp);
            end = clock();
            break;
        case '2':
            printf("\nСортировка расчёской\n");
            begin = clock();
            comb_sort(arr, len, cmp);
            end = clock();
            break;
        case '1':
            printf("\nБиблиотечный qsort\n");
            begin = clock();
            qsort(arr, len, sizeof(el),
                (int (*)(const void *, const void *)) cmp);
            end = clock();
            break;
        default:
            printf("\nАлгоритм сортировки не обозначен.\nБиблиотечный qsort использован по умолчанию\n");
            begin = clock();
            qsort(arr, len, sizeof(el),
                 (int (*)(const void *, const void *)) cmp);
            end = clock();
            break;
    }
    float time = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("\nВыполнено");
    printf("\nВремя выполнения - %f секунд", time);
    el_array_print(arr, len, f2);
    fclose(f2);
    fclose(f1);
    free(arr);
    printf("\n\nПрограмма завершена\n\n");
}
