#define SORT_H
#ifdef SORT_H

int el_cmp_age_increasing(const el *p1, const el *p2);
int el_cmp_fio_increasing(const el *p1, const el *p2);
int el_cmp_ps_increasing(const el *p1, const el *p2);
int el_cmp_age_decreasing(const el *p1, const el *p2);
int el_cmp_fio_decreasing(const el *p1, const el *p2);
int el_cmp_ps_decreasing(const el *p1, const el *p2);

el *comb_sort(el *arr, int size, int (*cmp)(const el*, const el*));
el *insert_sort(el *arr, int size, int (*cmp)(const el*, const el*));

#endif
