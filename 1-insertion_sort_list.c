#include "sort.h"

/* swap - swaps 2 nodes in a doubly-linked list
 * @a: address of first node
 * @b: address of second node
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b)
{
    listint_t temp_a, temp_b;

    temp_a.next = a->next;
    temp_a.prev = a->prev;
    temp_a.n = a->n;
    temp_b.next = b->next;
    temp_b.prev = b->prev;
    temp_b.n = b->n;

    a->prev = b;
    a->next = temp_b.next;
    if (temp_a.prev)
        temp_a.prev->next = b;
    b->prev = temp_a.prev;
    b->next = a;
    if (temp_b.next)
        temp_b.next->prev = a;
}

/* insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *i, *j;

    if (!list || !*list || !(*list)->next)
        return;

    i = (*list)->next;
    while (i)
    {
        printf("----> i:[%d]\n", i->n);
        j = i;
        i = i->next;
        printf("j STARTS at [%d]\n", j->n);
        while (j && j->prev)
        {
            if (j->prev->n > j->n)
            {
                printf("Swapping: [%d] [%d]\n", j->prev->n, j->n);
                swap(j->prev, j);
                if (!j->prev)
                    *list = j;
                print_list((const listint_t *)*list);
                printf("j is: [%d]\n", j->n);
            }
            else
                j = j->prev;
            if (j)
                printf("j is: now [%d]\n", j->n);
        }
        
    }
}