#include "pipex.h"

void	msg_exit(char	*msg, int exit_status)
{
	perror(msg);
	exit(exit_status);
}

char	**protection(char **value)
{
	if (value == NULL)
		exit(1);
	return (value);
}
