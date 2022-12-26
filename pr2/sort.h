#ifndef SORT_H
#define SORT_H

int el_cmp_age_increasing(const el *p1, const el *p2);
int el_cmp_fio_increasing(const el *p1, const el *p2);
int el_cmp_ps_increasing(const el *p1, const el *p2);
int el_cmp_age_decreasing(const el *p1, const el *p2);
int el_cmp_fio_decreasing(const el *p1, const el *p2);
int el_cmp_ps_decreasing(const el *p1, const el *p2);
void *chouse_cmp(char *field, char *dir);
void *chouse_sort(int numsort);

void comb_sort(el *arr, size_t size, size_t size_el, int (*cmp)(const el*, const el*));
void insert_sort(el *arr, size_t size, size_t size_el, int (*cmp)(const el*, const el*));

#endif
