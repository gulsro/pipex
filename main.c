#include <unistd.h>

//pseudo o_O
----------------./pipex file1 cmd1 cmd2 file2 ---------------

int main(int argc, char *argv[], char *envp[])
{
	int		infile;
	int		outfile;
	
	infile = open((infile) argv[1], O_RONLY);
	outfile = open((outfile) argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		exit(1);
	pipex(infile, outfile, argv, envp);
}

