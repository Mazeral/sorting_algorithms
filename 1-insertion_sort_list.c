#include "sort.h"

/**
 * insertion_sort_list - a function sorts a doubly linked list with insertion sort algo
 * @list: The linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t **current = NULL;
	listint_t **current2 = NULL;
	listint_t **smallest = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = list;
	while ((*current)->next != NULL)
	{
		current2 = current;
		while((*current2)->next != NULL)
		{
			if ((*current2)->n < (*current)->n)
				smallest = current2;
			*current2 = (*current2)->next;
		}
		if (smallest != NULL)
		{
			/* TODO: Switch between the smallest and the current nodes*/
			(*current)->prev = smallest->prev;
			if ((*smallest)->prev != NULL)
				(*smallest)->prev->next = (*smallest)->next;
			(*smallest)->next = malloc(sizeof(listint_t));
			(*smallest)->next = *current;
		}
		print_list(*list);
		*current = (*current)->next;
	}
}
