/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:36:55 by troudot           #+#    #+#             */
/*   Updated: 2022/11/26 04:40:42 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// return (1) if he are \n in the string else return (0)
int	check_if_return(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*return_in_line(char *buffer, char *str, char *string)
{
	int		j;
	int		i;
	char	*tmp;

	i = 0;
	j = ft_strlenn(string + 1);
	tmp = 0;
	while (string[j])
		tmp[i++] = string[j++];
	free(string);
	i = -1;
	while (tmp[++i])
		str[i] = tmp[i];
	return (ft_strjoin());
}

// return the actual line
char	*get_next_line(int fd)
{
	int				a;
	char			*buffer;
	char			*string;
	static char		*str;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (fd)
	{
		a = read(fd, string, BUFFER_SIZE);
		if (!a)
			return (0);
		if (a == -1)
			return (NULL);
		while (check_if_return(str) == 0)
		{
			buffer = ft_strjoin(str, buffer);
			free(str);
		}
		if (check_if_return(str) == 1)
			return (return_in_line(buffer, str, string));
	}
	return (buffer);
}
