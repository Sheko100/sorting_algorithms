#include "sort.h"

/**
 * swapnodes - swaps two nodes of a doubly linkes list
 * @lftnode: the node on the left
 * @ritnode: the node on the right
 * @head: the list head
 *
 * Return: new left position node
 */
listint_t *swapnodes(listint_t *lftnode, listint_t *ritnode, listint_t **head)
{
	listint_t *leftmostnode = lftnode->prev;
	listint_t *rightmostnode = ritnode->next;

	lftnode->next = rightmostnode;
	lftnode->prev = ritnode;
	ritnode->next = lftnode;
	ritnode->prev = leftmostnode;

	if (leftmostnode)
		leftmostnode->next = ritnode;
	else
		*head = ritnode;

	if (rightmostnode)
		rightmostnode->prev = lftnode;

	return (ritnode);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: pointer to the header of doubly linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *currnode, *nextnode, *prevnode, *newcurrnode = 0;

	if (!list || !*list || !(*list)->next)
		return;

	currnode = *list;
	nextnode = currnode->next;
	while (nextnode)
	{
		if (currnode->n > nextnode->n)
		{
			newcurrnode = swapnodes(currnode, nextnode, list);
			print_list(*list);
		}
		else
			currnode = nextnode;
		nextnode = currnode->next;

		while (newcurrnode && newcurrnode->prev)
		{
			prevnode = newcurrnode->prev;
			if (prevnode->n > newcurrnode->n)
			{
				newcurrnode = swapnodes(prevnode, newcurrnode, list);
				print_list(*list);
			}
			else
				break;
		}
	}
}
