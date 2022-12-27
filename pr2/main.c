#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "sort.h"

int main(int argc, char *argv[]) {
    getopt(argc, argv, "q:a::f::d::");
    int len = atoi(optarg);
    //getopt(argc, argv, "q:a::f::d::");
    //FILE *f2 = fopen(optarg, "w");
    int numsort = 0;
    char *field = NULL;
    char *dir = NULL;
    int opt;
    while ((opt = getopt(argc, argv, "q:o:a::f::d::")) != -1) {
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
    el_array_input(&arr, len);
    clock_t begin, end;
    begin = clock();
    sort(arr, len, sizeof(el), cmp);
    end = clock();
    float time = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("\nВыполнено");
    printf("\nВремя выполнения - %f секунд", time);
    //el_array_print(arr, len, f2);
    //fclose(f2);
    free_arr(&arr, len);
    printf("\n\nПрограмма завершена\n\n");
}
