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

static	char	**get_path_from_envp(char **envp)
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
	lst_paths = protection(ft_split(str_paths, ":")); //MM
	free(str_all_paths);
	return (lst_paths); // {"/usr/local/bin", "/usr/bin", "/bin"}
}

static	char *get_cmd_from_argv(char **argv, int cmd_number)
{
	char	**lst_cmd;
	char	*cmd;
	int	i;

	i = 0;
	lst_cmd = protection(ft_split(argv[cmd_number], ' '));
	cmd = lst_cmd[0];
	return (cmd); // ls
}

static char *get_command_path(char **argv, int cmd_number, char **envp)
{
	char	**lst_paths;
	char	*with_slash;
	char	*command;
	char	*cmd;

	cmd = get_cmd_from_argv(argv, cmd_number);
	lst_paths = get_path_from_envp(envp);
	while (*lst_paths)
	{
		with_slash = ft_strjoin(lst_paths[i], "/"); //MM
		command = ft_strjoin(with_slash, cmd);
		free(with_slash);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		lst_paths++;
	}
	//free lst_paths and cmd ??
	free(with_slash);
	return (NULL); ///usr/local/bin/ls
} //now we have a command path ready to use in exec.

void	exe_cute(char **argv, int cmd_number, char *envp[])
{
	char	*command;

	command = get_command_path(argv, cmd_number, envp);
	execve(command, argv, envp);
}
