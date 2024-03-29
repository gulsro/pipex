/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 13:11:20 by gozturk       #+#    #+#                 */
/*   Updated: 2023/06/08 15:30:33 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_exit(char	*msg, int exit_status)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		write(2, &msg[i], 1);
		i++;
	}
	exit(exit_status);
}

char	**protect_double(char **value)
{
	if (value == NULL)
		exit(1);
	return (value);
}

char	*protect_single(char *value)
{
	if (value == NULL)
		exit(1);
	return (value);
}
