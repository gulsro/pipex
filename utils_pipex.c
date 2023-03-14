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

static	char	**get_path_from_envp(char *envp[])
{
	char	*lst_paths[];
	char	*cmp_word;
	char	*str_all_paths;
	int	len_path;
	int	i;

	cmp_word = "PATH=";
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], cmp_word, 5) == 0)
		{
			break ;
		}
		i++;
	}
	len_path = ft_strlen(envp[i]);
	str_all_paths = ft_substr(envp[i], 5, len_path - 5); //MM
	lst_paths = ft_split(str_paths, ":"); //MM
	free(str_all_paths);
	return (lst_paths);
}

static void	add_slash_to_end(char *lst_paths[])
{
	int	i;
	
	i = 0;
	while (lst_paths[i])
	{
		ft_strjoin(lst_paths[i], "/"); //MM
		i++;
	}
}

void	exec_cute(char *argv[], int argv_number, char *envp[])
{
	char	*lst_paths[];
	char	*list_cmd[];
	char	*full_path;
	int	i;
	
	i = 0;
	lst_paths = get_path_from_envp(envp);
//	lst_paths = ft_split(str_paths, ":"); //MM
	add_slash_to_end(lst_paths); //MM

	lst_cmd = ft_split(argv[argv_number], " ");
	while (lst_paths[i])
	{
		ft_strjoin(lst_paths[i], )
	}
	execve();
}
