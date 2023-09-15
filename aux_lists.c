#include "main.h"

/**
 * add_sep_node_end - Adds a division node to the end of a sep_list.
 * @head: Pointer to the head of the linked list.
 * @sep: Division character (';', '|', or '&').
 *
 * Return: Pointer of the head.
 */


sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


/**
 * free_sep_list - Frees memory allocated for a sep_list.
 * @head: Pointer to the head of the linked list.
 * Return: No return value.
 */


void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - Adds a command line node to the end of a line_list.
 * @head: Pointer to the head of the linked list.
 * @line: Command line string.
 *
 * Return: Pointer of the head.
 */


line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


/**
 * free_line_list - Frees memory allocated for a line_list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: No return value.
 */


void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
