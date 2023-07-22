#include "sort.h"

/**
 * swap_nodes - this swaps two nodes
 * @list: the linked list with the nodes for swapping
 * @a: the first node
 * @b: the second node
 * Return: nothing
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == NULL || b == NULL || a == b)
	{
		return;
	}

	if (a->prev != NULL)
	{
		a->prev->next = b;
	}
	else
	{
		*list = b;
	}

	if (b->prev != NULL)
	{
		b->prev->next = a;
	}

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

	if (a->next != NULL)
	{
		a->next->prev = a;
	}
}

/**
 * cocktail_sort_list - sorts arrays of integers from min to max order
 * @list: linked list to be sorted
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int did_swap;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (1)
	{
		did_swap = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				did_swap = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!did_swap)
			break;
		did_swap = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				did_swap = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
		if (!did_swap)
			break;
	}
}
