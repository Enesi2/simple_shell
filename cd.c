#include "shell.h"

/**
 * cd - changes the current directory
 * @env: environment variable
 * @command: pointer to command arguments
 * @program: program name
 * @buf: buffer to free
 * @n: error counter
 * @sep_arr: array of separated commands
 */
void cd(char **env, char **command, char *program, char *buf,
unsigned int *n, char **sep_arr)
{
	char *oldpwd = _getenv("OLDPWD");
	char *pwd = _getenv("PWD");

	if (command[1] == NULL || _strcmp(command[1], "~") == 0)
	{
		if (chdir(_getenv("HOME")) == -1)
			_error_cd(program, command, buf, n, sep_arr);
	}
	else if (_strcmp(command[1], "-") == 0)
	{
		if (oldpwd != NULL)
		{
			if (chdir(oldpwd) == -1)
				_error_cd(program, command, buf, n, sep_arr);
			write(STDOUT_FILENO, oldpwd, _strlen(oldpwd));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
	}
	else
	{
		if (chdir(command[1]) == -1)
			_error_cd(program, command, buf, n, sep_arr);
	}

	_setenv(env, "OLDPWD", pwd);
	_setenv(env, "PWD", getcwd(NULL, 0));

	_free(sep_arr);
	free(buf);
	free(command);
	*n = 0;
}
