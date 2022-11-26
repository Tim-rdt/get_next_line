/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:36:55 by troudot           #+#    #+#             */
/*   Updated: 2022/11/26 09:42:33 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// return (1) if he are \n in the line else return (0)
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

char	*return_in_line(char *buffer, char *str, char *line)
{
	int		j;
	int		i;
	char	*tmp;

	i = 0;
	j = ft_strlenn(buffer + 1);
	tmp = 0;
	while (buffer[j])
		tmp[i++] = buffer[j++];
	free(buffer);
	i = -1;
	while (tmp[++i])
		str[i] = tmp[i];
	return (ft_strjoin(line, tmp));
}

// return the actual line
char	*get_next_line(int fd)
{
	int			a;
	char		*buffer;
	char		*line;
	static char	*str;

	line = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (fd)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (!a)
			return (0);
		if (a == -1)
			return (NULL);
		if (check_if_return(buffer) == 0)
		{
			line = ft_strjoin(str, ft_strjoin(line, buffer));
			free(str);
		}
		if (check_if_return(buffer) == 1)
			return (return_in_line(buffer, str, line));
	}
	return (0);
}

