#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	char	**lst_cmd;
	char	**lst_cmd_n;

	if (argc != 5)
	{
		perror("wrong number of arguments");
		exit(1);
	}
	infile = open(argv[1], O_RDONLY | O_CREAT, 0644);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
	{
		msg_exit("open() failed", 1);
	}
	pipex(infile, outfile, argv, envp);
}
