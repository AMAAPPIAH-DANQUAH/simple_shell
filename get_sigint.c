#include "main.h"

/**
 * get_sigint - Signal handler for Ctrl+C- provides a lightning responses.
 * @sig: The signal number.
 */


void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
