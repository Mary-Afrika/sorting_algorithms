#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion
 * sort algorithm
 * @list: unsorted doubly linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *next_swap;

	if (list == NULL || *list == NULL)
		return;
	current_node = (*list)->next;
	while (current_node != NULL)
	{
		next_swap = current_node->next;
		while (current_node->prev != NULL && current_node->prev->n > current_node->n)
		{
			current_node->prev->next = current_node->next;
			if (current_node->next != NULL)
				current_node->next->prev = current_node->prev;
			current_node->next = current_node->prev;
			current_node->prev = current_node->next->prev;
			current_node->next->prev = current_node;
			if (current_node->prev == NULL)
				*list = current_node;
			else
				current_node->prev->next = current_node;
			print_list(*list);
		}
		current_node = next_swap;
	}
}
