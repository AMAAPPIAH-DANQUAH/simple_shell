#include "main.h"


/**
 * add_rvar_node - Adds a variable node at the end of a r_var list.
 * @head: Pointer to the head of the linked list.
 * @lvar: How long the variable is.
 * @val: The value of the variable.
 * @lval: The actual length of the value.
 *
 * Return: Pointer of the head.
 */


r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

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
 * free_rvar_list - Frees memory allocated to r_var list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: No return value.
 */


void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

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
