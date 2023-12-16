#include "sort.h"

/**
 * swap_node - Swap 2 nodes in a listint_t doubly-linked list.
 * @node1: parameter1
 * @node2: parameter2
 *
 * Return: void
 */
void swap_node(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: A pointer to the head of node
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *t;

	if (!list || !*list || !(*list)->next)
		return;

	i = (*list)->next;
	while (i)
	{
		t = i;
		i = i->next;
		while (t && t->prev)
		{
			if (t->prev->n > t->n)
			{
				swap_node(t->prev, t);
				if (!t->prev)
					*list = t;
				print_list((const listint_t *)*list);
			}
			else
				t = t->prev;
		}
	}
}
