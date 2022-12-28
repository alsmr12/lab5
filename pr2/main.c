#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "sort.h"

int main(int argc, char *argv[]) {
    int t = getopt(argc, argv, "l:q:a::f::d::");
    if (t != (int)'l') {
        printf("Ошибка. Не были введены обязательные аргументы,\nлибо были введены в неправильном порядке.\n");
        exit(1);
    }
    int len = atoi(optarg);
    t = getopt(argc, argv, "l:q:a::f::d::");
    if (t != (int)'q') {
        printf("Ошибка. Не были введены обязательные аргументы.\n");
        exit(1);
    }
    int q = atoi(optarg);
    int numsort = 0;
    char *field = NULL;
    char *dir = NULL;
    int opt;
    while ((opt = getopt(argc, argv, "l:q:a::f::d::")) != -1) {
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
    
    int (*cmp)(const el*, const el*) = chouse_cmp(field, dir);
    void (*sort)(el *, size_t,  size_t,  int (*)(const el *, const el *)) = chouse_sort(numsort);

    el *arr = NULL;
    clock_t begin, end;
    float time = 0;
    for (int i = 0; i < q; i++) {
        el_array_input(&arr, len);
        begin = clock();
        sort(arr, len, sizeof(el), cmp);
        end = clock();
        free_arr(&arr, len);
        time = time + (float)(end - begin) / CLOCKS_PER_SEC;
        //printf("\nВремя выполнения - %f секунд", (float)(end - begin) / CLOCKS_PER_SEC);
    }
    printf("\nВыполнено");
    printf("\nСреднее время выполнения - %f секунд", time / q);
    printf("\n\nПрограмма завершена\n\n");
}
