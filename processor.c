#include "main.h"

/**
* process -	Checks the text entered against some built-ins
*			commands like exit and env, then it redirects accordingly
*
* @toks:	The token list of text entered;
* @env:		The environment var
* @status:	This determines whether or not the flow
*			will reach the exec function
*
* Return:	Returns nothing
*/

void process(char **toks, char **env __attribute__((unused)), int *status)
{
	int i;

	if (_strcmp(toks[0], "exit") == 0)
	{
		printf("Entered exit branch\n");
		(*status) = 0;
		free(toks);
		exit(0);
	}
	else if (_strcmp(toks[0], "env") == 0)
	{
		printf("Entered env branch\n");
		(*status) = 0;
		i = 0;
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	else
	{
		addPath(toks, env, status);
	}
}

/**
* addPath -	Adds the full path of a command to the tokens before execution
* @command: All command tokens, otherwise referred to as toks
*			some place else in this repo
*
* @env:		This is the environment var
* @status:	If the command is not found status will be reset to 0
*			so it never reaches the execve function in shell.c
*
* Return: Null void
*/

void addPath(char **command, char **env, int *status)
{
	char *path;
	char **paths;
	struct stat buf;
	int i = 0;

	char *mycwd = getcwd(NULL, 0);

	path = pathfinder(env);
	paths = populate(path, 1);

	(*status) = 0;
	while (paths[i])
	{
		chdir(paths[i]);
		if (stat(command[0], &buf) == 0)
		{
			(*status) = 1;
			command[0] = _strcat(paths[i], command[0]);
			break;
		}
		i++;
	}
	chdir(mycwd);
}
