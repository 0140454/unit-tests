#include "swap.c"

void merge_sort(List **head, cmp_func_t cmp)
{
    if (head == NULL || (*head == NULL) || (*head)->next == NULL)
        return;

    List *left = *head, *right = (*head)->next;
    List *next_node = NULL, *last_node = NULL;

    while(right) {
        right = right->next;

        if (right) {
            left = left->next;
            right = right->next;
        }
    }

    right = left->next;
    left->next = NULL;
    left = *head;

    merge_sort(&left, cmp);
    merge_sort(&right, cmp);

    *head = NULL;
    while(left && right) {
        if (cmp(left, right)) {
            next_node = right;
            right = right->next;
        } else {
            next_node = left;
            left = left->next;
        }

        if (*head) last_node->next = next_node;
        else *head = next_node;

        last_node = next_node;
    }

    last_node->next = (left) ? left : right;
}
