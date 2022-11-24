/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:36:55 by troudot           #+#    #+#             */
/*   Updated: 2022/11/25 00:05:07 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_if_return(char *str)
{
	while (*str)
		if (*str == '\0')
			return (1);
	return (0);
}

// return the actual line
char	*get_line(int fd)
{
	static char	*str;
	char		*str2;
	int			tmp;

	read(fd, str, BUFFER_SIZE);
	tmp = check_if_return(str);
	if (!tmp)
	{
		read(fd, str2, BUFFER_SIZE);
		str = ft_strjoin(str, str2);
	}
	str = malloc(sizeof(char *) * check_if_return(str));
	if (!str)
		return (NULL);
	return (str);
}

//go to the next line
char	*get_next_line(int fd)
{
	
}
