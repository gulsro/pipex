/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 11:29:49 by gozturk       #+#    #+#                 */
/*   Updated: 2023/03/29 21:13:58 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int infile, int outfile, char **argv, char **envp)
{
	int		f[2];
	pid_t	p1;
	pid_t	p2;

	if (pipe(f) < 0)
		msg_exit("pipe() failed", 1);
	p1 = fork();
	if (p1 == -1)
		msg_exit("fork() failed", 1);
	else if (p1 == 0)
		kiddo_1(infile, f, argv, envp);
	p2 = fork();
	if (p2 == -1)
		msg_exit("fork() failed", 1);
	else if (p2 == 0)
		kiddo_2(outfile, f, argv, envp);
	else
	{
		parent_process(f, p1, p2);
		close(infile);
		close(outfile);
	}
}

void	kiddo_1(int infile, int f[], char **argv, char **envp)
{
	if (dup2(infile, STDIN_FILENO) < 0 || dup2(f[1], STDOUT_FILENO) < 0)
	{
		msg_exit("dup2() failed", 1);
	}
	close(f[0]);
	close(infile);
	exe_cute(argv, 2, envp);
}

void	kiddo_2(int outfile, int f[], char **argv, char **envp)
{
	if (dup2(outfile, STDOUT_FILENO) < 0 || dup2(f[0], STDIN_FILENO) < 0)
	{
		msg_exit("dup2() failed", 1);
	}
	close(f[1]);
	close(outfile);
	exe_cute(argv, 3, envp);
}

void	parent_process(int f[], pid_t p1, pid_t p2)
{
	int	exit_status;

	close(f[0]);
	close(f[1]);
	waitpid(p1, NULL, 0);
	waitpid(p2, &exit_status, 0);
	if (exit_status != 0)
	{
		msg_exit("execution p2 failed", 127);
	}
}
