#include "sort.h"

/**
 * swap_nodes - swaps 2 nodes of a linked list
 * @a: first node
 * @b: second node
 */

void swap_nodes(listint_t *a, listint_t *b)
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
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       in ascending order
 * @list: double pointer to the head of a doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorter, *marker;

	if (!list || !*list || !((*list)->next))
		return;

	marker = (*list)->next;
	while (marker)
	{
		sorter = marker;
		marker = marker->next;
		while (sorter && sorter->prev)
		{
			if (sorter->prev->n > sorter->n)
			{
				swap_nodes(sorter->prev, sorter);
				if (!sorter->prev)
					*list = sorter;
				print_list(*list);
			}
			else
				sorter = sorter->prev;
		}
	}
}
