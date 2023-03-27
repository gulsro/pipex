/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 11:26:57 by gozturk       #+#    #+#                 */
/*   Updated: 2023/03/07 11:29:40 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>

# include <fcntl.h>

# include "libft/libft.h"

void	pipex(int infile, int outfile, char *argv[], char *envp[]);
void	kiddo_1(int infile, int f[], char **argv, char **envp);
void	kiddo_2(int outfile, int f[], char **argv, char **envp);
void	parent_process(int f[], pid_t p1, pid_t p2);

void	exe_cute(char **argv, int cmd_number, char *envp[]);

char	**protection(char **value);
void	msg_exit(char *msg, int exit_status);

#endif
