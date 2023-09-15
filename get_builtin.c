#include "main.h"

/**
 * get_builtin - Acquire an integrated function for a given command
 * @cmd: Command
 *
 * Return: Pointer to the associated integrated function or NULL if not found
 */


int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{"env", _env},
		{"exit", exit_shell},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", cd_shell},
		{"help", get_help},
		{NULL, NULL}
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
