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

#include "pipex.h"

static	char	*get_path_from_envp(char **envp)
{
	char	**lst_paths;
	char	*cmp_word;
	char	*str_all_paths;
	int	len_path;
//	int	i;

	cmp_word = "PATH=";
//	i = 0;
	while (*envp)
	{
		if (ft_strncmp(*envp, cmp_word, 5) == 0)
		{
			break ;
		}
		envp++;
	}
//	len_path = ft_strlen(envp[i]);
//	str_all_paths = ft_substr(envp[i], 5, len_path - 5); //MM
	str_all_paths = *envp + 5;
//	lst_paths = protection(ft_split(str_all_paths, ':')); //MM
//	free(str_all_paths);
	return (str_all_paths);
}

static	char *get_cmd_from_argv(char **argv, int cmd_number)
{
	char	**lst_cmd;
	char	*cmd;
	
	if (ft_strrchr(argv[cmd_number], ' '))
	{
		lst_cmd = protection(ft_split(argv[cmd_number], ' '));
		cmd = lst_cmd[0];
	}
	else
	{
		cmd = argv[cmd_number];
	}
	return (cmd); // ls
}

static	char *get_command_path(char **argv, int cmd_number, char **envp)
{
	char	*lst_paths;
	char	**path_array;
	char	*with_slash;
	char	*command;
	char	*cmd;

	cmd = get_cmd_from_argv(argv, cmd_number);
	lst_paths = get_path_from_envp(envp);
	path_array = protection(ft_split(lst_paths, ':'));
	while (*path_array)
	{
		with_slash = ft_strjoin(*path_array, "/"); //MM
		command = ft_strjoin(with_slash, cmd);
		free(with_slash);
		if (access(command, F_OK) == 0)
		{
			return (command);
		}	
		free(command);
		path_array++;
	}
	return (NULL); ///usr/local/bin/ls
} //now we have a command path ready to use in exec.

void	exe_cute(char **argv, int cmd_number, char *envp[])
{
	char	*command;
	char	**lst_cmd;
	char    **lst_cmd_with_null;
	int exec;

	lst_cmd = protection(ft_split(argv[cmd_number], ' '));
	command = get_command_path(argv, cmd_number, envp);
	if (!command)
		exit(1);
	if (execve(command, lst_cmd, envp))
	{
		perror("execve failed");
		exit(1);
	}
	
}
