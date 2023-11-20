#include "shell.h"

/**
 * _echo_status - prints the exit status
 * @status: The integer value of the exit status
 */
void _echo_status(int *status)
{
	char buffer[INT_BUFFER_SIZE];
	int len;

	len = put_int(*status);
	write(STDOUT_FILENO, buffer, len);
	_putchar('\n');
}

/**
 * _getpid - prints the process ID
 */
void _getpid(void)
{
	char buffer[INT_BUFFER_SIZE];
	int len;

	len = put_int(getpid());
	write(STDOUT_FILENO, buffer, len);
	_putchar('\n');
}
