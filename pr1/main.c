#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "sort.h"

int main(int argc, char *argv[]) {
    getopt(argc, argv, "i:o:a::f::d::");
    FILE *f1 = fopen(optarg, "r");
    getopt(argc, argv, "i:o:a::f::d::");
    FILE *f2 = fopen(optarg, "w");
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
    
    int (*cmp)(const el*, const el*) = chouse_cmp(field, dir);
    void (*sort)(el *, size_t,  size_t,  int (*)(const el *, const el *)) = chouse_sort(numsort);

    el *arr = NULL;
    int len;
    el_array_input(&arr, &len, f1);
    clock_t begin, end;
    begin = clock();
    sort(arr, len, sizeof(el), cmp);
    end = clock();
    float time = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("\nВыполнено");
    printf("\nВремя выполнения - %f секунд", time);
    el_array_print(arr, len, f2);
    fclose(f2);
    fclose(f1);
    free(arr);
    printf("\n\nПрограмма завершена\n\n");
}
