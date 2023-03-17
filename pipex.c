/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 11:29:49 by gozturk       #+#    #+#                 */
/*   Updated: 2023/03/13 15:19:50 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void pipex(int infile, int outfile, char *argv[], char *envp[])
{
	int 	f[2];
	pid_t	p1; //kiddo_1
	pid_t	p2; //kiddo_2

	pipe(f);
	p1 = fork();
	if (p1 == -1)
	{
		perror("");
    		exit(1);
	}
	else if (p1 == 0)
	{
		kiddo_1(infile, f, argv, envp);
	}
	p2 = fork();
	if (p2 == -1)
	{
		perror("");
		exit(1);
	}
	else if (p2 == 0)
	{
		kiddo_2(outfile, f, argv, envp);
	}
	else
		parent_process(f, p1, p2);
}

void kiddo_1(int infile, int f[], char **argv, char **envp)
{
	dup2(infile, STDIN_FILENO); //infile as stdin
	dup2(f[1], STDOUT_FILENO); // everything will be written in f[1], so it ll be stdout
	close(f[0]);
       	exe_cute(argv, 2, envp);
	close(infile);
}

void kiddo_2(int outfile, int f[], char **argv, char **envp)
{
	dup2(outfile, STDOUT_FILENO);
	dup2(f[0], STDIN_FILENO);
	close(f[1]);
	exe_cute(argv, 3, envp);
	close(outfile);
}

void parent_process(int f[], pid_t p1, pid_t p2)
{
	int	exit_status;

	waitpid(p1, NULL, 0);
	waitpid(p2, &exit_status, 0);
	if (exit_status != 0)
	{
		exit(127);
	}
}
