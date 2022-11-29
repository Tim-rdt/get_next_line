/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:29:53 by troudot           #+#    #+#             */
/*   Updated: 2022/11/29 22:32:19 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd1;
	int		fd2;

	fd1 = open("file1", O_RDONLY);
	fd2 = open("file2", O_RDONLY);
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	return (0);
}
