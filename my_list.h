#ifndef __MY_LIST_H
#define __MY_LIST_H

typedef struct List_node {
    int value;
    struct List_node *next;
} List;

/*
 * If return value is zero, the element pointed to by a goes before the element pointed to by b.
 * Otherwise, the element pointed to by a goes after the element pointed to by b.
 */
typedef int (*cmp_func_t)(List *a, List *b);

int compare_increasing(List *a, List *b) {
    return a->value > b->value;
}

int compare_decreasing(List *a, List *b) {
    return a->value < b->value;
}

#endif
