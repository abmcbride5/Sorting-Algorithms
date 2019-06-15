#include "sort.h"
/*
*swap - swaps 2 nodes in a doubly-linked list
*@a: address of first node
*@b: address of second node
*
*Return: void
*/
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}



/**
*cocktail_sort_list - sorts linked list using cocktail shaker sort
*
*@list: doubly linked list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *head, *len;
	int i = 0, j = 0;

	len = *list;
	for (i = 0; len; i++)
	{
		len = len->next;
	}
	head = *list;
	while (j < i)
	{
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap(head, head->next);
				print_list(*list);
			}
			else
				head = head->next;
			if (head->next == NULL)
				tail = head;
		}
		while (tail && tail->prev)
		{
			if (tail->n < tail->prev->n)
			{
				swap(tail->prev, tail);
				if (tail->prev == NULL)
					*list = tail;
				print_list(*list);

			}
			else
				tail = tail->prev;
			if (tail->prev == NULL)
				head = tail;
		}
		j++;
	}
}
