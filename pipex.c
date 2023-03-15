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
	pid_t	p1;
	pid_t	p2;

	pipe(f);
	p1 = fork();
    if (p1 == 0)
        kiddo_1(fd1);
    else if (p1 == -1)
       // handle

}

void kiddo_1(int fd1, argv[2])
{
	dup2(fd1, STDIN_FILENO); //fd1 as stdin
	dup2(f[1], STDOUT_FILENO); // everything will be written in f[1], so it ll be stdout
	close(f[0]);
//	first check if the cmd1 exists access()
	
	execve("/bin/ls", {"/bin/ls", "-l", NULL} so:array of strings, each string represents an argument to the process-NULL at the end>it tells execve where to ends array of string, $PATH(all posibble paths the program wil be seached) )
	close(fd1);
}

void kiddo_2(int fd2, argv[3])
{
	wait();
	dup2(fd2, STDOUT_FILENO)
	dup2(f[0], STDIN_FILENO)
	close(f[1]);
	check if cmd2 exists 
	execute things cmd2
	close(fd2);
}

void parent_process()
{
	
}
