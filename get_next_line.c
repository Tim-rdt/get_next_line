/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:36:55 by troudot           #+#    #+#             */
/*   Updated: 2022/11/25 03:39:37 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// return (1) if he are \n in the string else return (0)
int	check_if_return(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

// return the actual line
char	*get_line(int fd, char *buffer, char *str)
{
	int	a;

	while (check_if_return(buffer) == 0)
	{
		buffer = malloc(sizeof(char *) * BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		a = read(fd, buffer, BUFFER_SIZE);
		if (!a)
			return (0);
		if (a == -1)
			return (-1);
		str = ft_strjoin(str, buffer);
		free(buffer);
	}
	if (check_if_return(buffer) == 1)
	{
		
	}
	return (str);
}

//go to the next line
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
}
