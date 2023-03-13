#include <unistd.h>

//pseudo o_O
----------------./pipex file1 cmd1 cmd2 file2 ---------------

int main(int argc, char *argv[], char *envp[])
{
	int		fd1[2]; //writing in infile fd1[1], reading from fd1[0]
	int		fd2[2];
	
	fd1 = open((infile) argv[1], O_WRONLY);
	fd2 = open((outfile) argv[4], O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		exit(1);
	pipex(f1, f2, argv, envp);
}
