/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 13:11:20 by gozturk       #+#    #+#                 */
/*   Updated: 2023/03/28 20:26:23 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_exit(char	*msg, int exit_status)
{
	perror(msg);
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
