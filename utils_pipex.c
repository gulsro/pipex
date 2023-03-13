/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_pipex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 13:22:33 by gozturk       #+#    #+#                 */
/*   Updated: 2023/03/13 15:20:24 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char *get_cmd_path(char *str, int argv_number, char *envp[])
{
	char	*path_envp;
	char	**arg_list;
	char	**path_list;
	int	i;
	
	i = 0;
	path_envp = PATH=
	path_list = ft_split();
	if (ft_strchr(str, " "))
	{
		arg_list = ft_split(str, " ");
	}

}
