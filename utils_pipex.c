/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_pipex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 13:22:33 by gozturk       #+#    #+#                 */
/*   Updated: 2023/03/08 14:55:14 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len_s;

	i = 0;
	len_s = ft_strlen(s) + 1;
	while (i < len_s)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (0);
}

char *get_cmd_path(char *str)
{
	argv[3]
	int	i;
	int flag;

	i = 0;
	flag = 0;
	if (ft_strchr(str, " "))
	{
		

}
