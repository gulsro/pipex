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

#include <unistd.h>

void pipex(int fd1, int fd2, char *argv[], char *envp[])
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
		kiddo_1(fd1, argv, 2, envp);
	}
	p2 = fork();
	if (p2 == -1)
	{
		perror("");
		exit(1);
	}
	else if (p2 == 0)
	{
		kiddo_2(fd2, argv, 3, envp);
	}
	else
		waitpid(p1, )

}

void kiddo_1(int fd1, char **argv, int cmd_number, char **envp)
{
	dup2(fd1, STDIN_FILENO); //fd1 as stdin
	dup2(f[1], STDOUT_FILENO); // everything will be written in f[1], so it ll be stdout
	close(f[0]);
//	first check if the cmd1 exists access()
	
       	exe_cute(argv, 2, envp);
	close(fd1);
}

void kiddo_2(int fd2, char **argv, int cmd_number, char **envp)
{
	dup2(fd2, STDOUT_FILENO)
	dup2(f[0], STDIN_FILENO)
	close(f[1]);
	exe_cute(argv, 3, envp);
	close(fd2);
}

void parent_process()
{
	
}
