/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:36:55 by troudot           #+#    #+#             */
/*   Updated: 2022/11/26 02:40:21 by troudot          ###   ########.fr       */
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

char	*return_in_line(char *buffer, char *str)
{
	int		j;
	int		i;
	char	*tmp;

	i = 0;
	j = ft_strlenn(buffer);
	tmp = 0;
	while (buffer[j])
		tmp[i++] = buffer[j++];
	ft_strjoin(str, tmp);
	ft_bzeroo(buffer, 0);
	j = 0;
	i = ft_strlenn(buffer);
	while (buffer[i])
		buffer[j++] = buffer[i++];
	ft_bzeroo(buffer, j);
	return (str);
}

// return the actual line
char	*get_line(int fd, char *buffer, char *str)
{
	int	a;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	a = read(fd, buffer, BUFFER_SIZE);
	if (!a)
		return (0);
	if (a == -1)
		return (-1);
	while (check_if_return(buffer) == 0)
	{
		str = ft_strjoin(str, buffer);
		free(buffer);
	}
	if (check_if_return(buffer) == 1)
		return (return_in_line(buffer, str));
	return (str);
}

//go to the next line
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	return (get_line(fd, buffer, str));
}
