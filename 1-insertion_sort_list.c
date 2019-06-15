#include "sort.h"

/* swap - swaps 2 nodes in a doubly-linked list
 * @a: address of first node
 * @b: address of second node
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b)
{
    listint_t temp;
    temp.next = b->next;
    temp.prev = b->prev;
    temp.n = b->n;
    

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
        j = i->prev;
        while (j->prev)
        {
            if (j->prev->n > j->n)
            {
                swap(j->prev, j);
                print_list((const listint_t *)list);
            }
            j = j->prev;
        }
        i = i->next;
    }
}