/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_pipex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 13:22:33 by gozturk       #+#    #+#                 */
/*   Updated: 2023/03/29 21:13:41 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*get_path_from_envp(char **envp)
{
	char	*cmp_word;
	char	*str_all_paths;

	cmp_word = "PATH=";
	while (*envp)
	{
		if (ft_strncmp(*envp, cmp_word, 5) == 0)
		{
			break ;
		}
		envp++;
	}
	str_all_paths = *envp + 5;
	return (str_all_paths);
}

static	char	*get_cmd_from_argv(char **argv, int cmd_number)
{
	char	**lst_cmd;
	char	*cmd;

	if (ft_strchr(argv[cmd_number], ' '))
	{
		lst_cmd = protect_double(ft_split(argv[cmd_number], ' '));
		cmd = lst_cmd[0];
	}
	else
	{
		cmd = argv[cmd_number];
	}
	return (cmd);
}

static	char	*get_command_path(char **argv, int cmd_number, char **envp)
{
	char	**path_array;
	char	*with_slash;
	char	*command;
	char	*cmd;
	int		i;

	i = 0;
	cmd = get_cmd_from_argv(argv, cmd_number);
//	path_array = protect_double(ft_split(get_path_from_envp(envp), ':'));
	path_array = ft_split(get_path_from_envp(envp), ':');
	if (!path_array)
		msg_exit("command cant be found", 127);
	while (path_array[i])
	{
		with_slash = protect_single(ft_strjoin(path_array[i], "/"));
		command = protect_single(ft_strjoin(with_slash, cmd));
		free(with_slash);
		if (access(command, F_OK) == 0)
		{
			return (command);
		}	
		free(command);
		i++;
	}
	free(path_array);
	return (NULL);
}

void	exe_cute(char **argv, int cmd_number, char *envp[])
{
	char	*command;
	char	**lst_cmd;

	lst_cmd = protect_double(ft_split(argv[cmd_number], ' '));
	command = get_command_path(argv, cmd_number, envp);
	if (!command)
	{
		msg_exit("command can't be found", 127);
	}
	execve(command, lst_cmd, envp);
	msg_exit("execve failed", 1);
}
