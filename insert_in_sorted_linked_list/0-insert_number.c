#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to pointer of head node of the list.
 * @number: integer to insert into the list.
 * Return: the address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current;

    // Allocate memory for the new node.
    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);  // Memory allocation failed.

    // Initialize the new node.
    new_node->n = number;
    new_node->next = NULL;

    // Handle case when list is empty or the new node should be inserted at the beginning.
    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    // Traverse the list to find the correct position to insert the new node.
    current = *head;
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }

    // Insert the new node after the current node.
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
