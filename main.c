/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:29:53 by troudot           #+#    #+#             */
/*   Updated: 2022/11/27 23:21:57 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd1;
	int		fd2;

	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	return (0);
}
