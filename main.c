#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	int		infile;
	int		outfile;
	
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		exit(1);
	pipex(infile, outfile, argv, envp);
}

