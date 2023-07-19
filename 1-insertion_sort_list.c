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
	listint_t *cur_node, *next_swap;

	if (list == NULL || *list == NULL)
		return;
	cur_node = (*list)->next;
	while (cur_node != NULL)
	{
		next_swap = cur_node->next;
		while (cur_node->prev != NULL && cur_node->prev->n > cur_node->n)
		{
			cur_node->prev->next = cur_node->next;
			if (cur_node->next != NULL)
				cur_node->next->prev = cur_node->prev;
			cur_node->next = cur_node->prev;
			cur_node->prev = cur_node->next->prev;
			cur_node->next->prev = cur_node;
			if (cur_node->prev == NULL)
				*list = cur_node;
			else
				cur_node->prev->next = cur_node;
			print_list(*list);
		}
		cur_node = next_swap;
	}
}
