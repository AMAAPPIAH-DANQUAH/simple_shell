#include "main.h"

/**
 * free_data - contruct is freed
 * @datash: construct to free
 *
 * Major function that frees shell data
 */

void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}


/**
 * set_data - Contruct is loaded in this function.
 * @datash: Construct to load
 * @av: Variable storing vector
 *
 * This function loads the data_shell structure with pertinent info.
 */


void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}


/**
 * main - Entry point of the shell
 * @ac: Variable storing count
 * @av: Variable storing vector
 *
 * Return: 0 if successfully executed
 */


int main(int ac, char **av)
{
	data_shell datash;
	(void)ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);

	if (datash.status < 0)
		return (255);

	return (datash.status);
}