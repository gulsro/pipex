/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 13:11:34 by gozturk       #+#    #+#                 */
/*   Updated: 2023/03/28 13:11:36 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;

	if (argc != 5)
	{
		perror("wrong number of arguments");
		exit(1);
	}
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
	{
		//msg_exit("open() failed", 1);
		perror("errors");
	}
	pipex(infile, outfile, argv, envp);
}
