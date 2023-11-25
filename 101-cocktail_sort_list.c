#include "sort.h"

/**
 * switch_nodes - is a function to swap two nodes
 * @head: head node
 * @node1: is a node to swap
 * @node2: another node to swap
 */
void switch_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (*head == node1)
		*head = node2;

	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;

	node2->next = node1;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker algorithm
 *
 * @list: head of linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int isSwap = 1;
	listint_t *node;

	if (!list || !*list || (*list)->next == NULL)
		return;
	while (isSwap)
	{
		isSwap = 0;
		node = *list;

		while (node && node->next)
		{
			if (node->n > node->next->n)
			{
				switch_nodes(list, node, node->next);
				print_list((const listint_t *)*list);
				isSwap = 1;
			} else
				node = node->next;
		}
		if (!isSwap)
			break;

		isSwap = 0;
		node = node->prev;

		while (node && node->prev)
		{
			if (node->n < node->prev->n)
			{
				switch_nodes(list, node->prev, node);
				print_list((const listint_t *)*list);
				isSwap = 1;
			} else
				node = node->prev;
		}
	}
}
