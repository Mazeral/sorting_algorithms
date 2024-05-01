#include "sort.h"

/**
 * swap_nodes - swap two nodes in a listint_t doubly-linked list.
 * @h: a pointer to the head of the doubly-linked list.
 * @n1: a pointer to the first node to swap.
 * @n2: the second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != null)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != null)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: a pointer to the head of a doubly-linked list of integers.
 *
 * description: prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == null || *list == null || (*list)->next == null)
		return;

	for (iter = (*list)->next; iter != null; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != null && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
