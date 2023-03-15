#include <stdio.h>

void	func(char **lst)
{
	while (*lst)
	{
		if (*lst[0] == 'a')
			printf("yes");
		else
			printf("nooo");
		lst++;
	}
}

int main()
{
	const char *lst[] = {"banana", "lemon"};
//	func(lst);
	printf("%s\n", *lst + 1);
}
