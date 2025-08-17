#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Entry point
 *
 * @list: function that sorts a doubly linked list of integers
 *
 * Return: Always 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{

			if (tmp->prev->prev)
				tmp->prev->prev->next = tmp;
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;
			tmp->next->prev = tmp;


			if (!tmp->prev)
				*list = tmp;

			print_list(*list);
		}
		current = current->next;
	}
}
