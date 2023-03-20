#include "pipex.h"


int main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	char	**lst_cmd;
	char	**lst_cmd_n;
/*	
	char	*gli;
	char **pff;

	gli = get_path_from_envp(envp);
	pff = ft_split(gli, ':');
	for(int i = 0; i < 10; i++)
	{
		printf("list paths: %s\n", pff[i]);
	}
//	lst_cmd = protection(ft_split(argv[2], ' '));
//	printf("str_paths= %s\n", get_path_from_envp(envp));	
	printf("cmd = %s\n", get_cmd_from_argv(argv, 2));
	printf("command = %s\n", get_command_path(argv, 2, envp));
	while(*lst_cmd)
	{
		printf("%s\n", *lst_cmd);
		lst_cmd++;
	}
*/
	if (argc != 5)
	{
		perror("wrong number of arguments");
		exit(1);
	}
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0)
	{
		perror("infile does not exist");
		infile = open(argv[1], O_RDONLY | O_CREAT, 0644);
	}
	if (infile < 0 || outfile < 0)
	{
		msg_exit("open() failed", 1);
	}
	pipex(infile, outfile, argv, envp);
}

