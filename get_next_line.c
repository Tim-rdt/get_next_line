/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:36:55 by troudot           #+#    #+#             */
/*   Updated: 2022/11/29 06:40:28 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//return (1) if he are \n in the line else return (0)
int	check_if_return(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(str, 1);
	while (++i < j)
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*next_line(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = ft_strlen(str, 2);
	new = malloc(ft_strlen(str, 1) - j + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[j])
		new[i++] = str[j++];
	new[i] = 0;
	free(str);
	return (new);
}

char	*return_in_line(char *str)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str, 2) + 1);
	if (!tmp)
		return (0);
	i = -1;
	while (str[++i] != '\n' && str[i])
		tmp[i] = str[i];
	tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

char	*get_the_line(int fd, char *str)
{
	int				a;
	char			*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	a = 1;
	while (a && !check_if_return(str))
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[a] = 0;
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = get_the_line(fd, str);
	if (!str)
		return (NULL);
	line = return_in_line(str);
	str = next_line(str);
	return (line);
}

// int main()
// {
// 	char			*buffer = "1234567890Azzzzz\ngdfgdfcvdf";
// 	static char		*str = "azerty";
// 	char			*line = "qwerty";

// 	printf("%s\n", return_in_line(buffer, &str, line));
// 	printf("%s\n", str);
// }

//https://pythontutor.com/render.html#code=%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstdio.h%3E%0A%0Asize_t%20%20%20%20ft_strlen%28const%20char%20*str%29%0A%7B%0A%20%20%20%20int%20%20%20%20i%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20while%20%28str%5Bi%5D%29%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20return%20%28i%29%3B%0A%7D%0A%0Asize_t%20%20%20%20ft_strlenn%28const%20char%20*str%29%0A%7B%0A%20%20%20%20size_t%20%20%20%20i%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20while%20%28str%5Bi%5D%20!%3D%20'%5Cn'%20%26%26%20str%5Bi%5D%29%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20return%20%28i%29%3B%0A%7D%0A%0Asize_t%20%20%20%20ft_strlcpy%28char%20*dst,%20const%20char%20*src,%20size_t%20dstsize%29%0A%7B%0A%20%20%20%20size_t%20%20%20%20i%3B%0A%0A%20%20%20%20if%20%28dstsize%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20return%20%28ft_strlen%28src%29%29%3B%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20while%20%28src%5Bi%5D%20%26%26%20i%20%3C%20%28dstsize%20-%201%29%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20dst%5Bi%5D%20%3D%20src%5Bi%5D%3B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20dst%5Bi%5D%20%3D%20'%5C0'%3B%0A%20%20%20%20return%20%28ft_strlen%28src%29%29%3B%0A%7D%0A%0Achar%20%20%20%20*ft_strjoin%28char%20const%20*s1,%20char%20const%20*s2%29%0A%7B%0A%20%20%20%20char%20%20%20%20*str%3B%0A%0A%20%20%20%20if%20%28!s1%20%7C%7C%20!s2%29%0A%20%20%20%20%20%20%20%20return%20%28NULL%29%3B%0A%20%20%20%20str%20%3D%20malloc%28sizeof%28char%29%20*%20%28ft_strlen%28s1%29%20%2B%20ft_strlenn%28s2%29%20%2B%201%29%29%3B%0A%20%20%20%20if%20%28!str%29%0A%20%20%20%20%20%20%20%20return%20%28NULL%29%3B%0A%20%20%20%20ft_strlcpy%28str,%20s1,%20ft_strlen%28s1%29%20%2B%201%29%3B%0A%20%20%20%20ft_strlcpy%28str%20%2B%20ft_strlen%28s1%29,%20s2,%20ft_strlenn%28s2%29%20%2B%201%29%3B%0A%20%20%20%20return%20%28str%29%3B%0A%7D%0A%0Achar%20%20%20%20*return_in_line%28char%20*buffer,%20char%20*str,%20char%20*line%29%0A%7B%0A%20%20%20%20int%20%20%20%20%20%20%20%20j%3B%0A%20%20%20%20int%20%20%20%20%20%20%20%20i%3B%0A%20%20%20%20char%20%20%20%20*tmp%3B%0A%20%20%20%20char%20%20%20%20*result%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20j%20%3D%20ft_strlenn%28buffer%29%20%2B%201%3B%0A%20%20%20%20str%20%3D%20malloc%28sizeof%28char%29%20*%20%28ft_strlen%28buffer%29%20-%20ft_strlenn%28buffer%29%20-%201%29%29%3B%0A%20%20%20%20while%20%28buffer%5Bj%5D%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20str%5Bi%5D%20%3D%20buffer%5Bj%5D%3B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20j%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20tmp%20%3D%20malloc%28sizeof%28char%29%20*%20%28j%20-%20i%20%2B%201%29%29%3B%0A%20%20%20%20i%20%3D%20-1%3B%0A%20%20%20%20while%20%28buffer%5B%2B%2Bi%5D%20!%3D%20'%5Cn'%29%0A%20%20%20%20%20%20%20%20tmp%5Bi%5D%20%3D%20buffer%5Bi%5D%3B%0A%20%20%20%20tmp%5Bi%5D%20%3D%20'%5C0'%3B%0A%20%20%20%20result%20%3D%20ft_strjoin%28line,%20tmp%29%3B%0A%20%20%20%20free%28tmp%29%3B%0A%20%20%20%20free%28buffer%29%3B%0A%20%20%20%20return%20%28result%29%3B%0A%7D%0A%0Aint%20main%28%29%0A%7B%0A%20%20char%20*buffer%20%3D%20%22ahsjdadhajvcsjhavxcjhdvfsdfsfsdfs%5Cnasd%5Cndsfsj%22%3B%0A%20%20char%20*str%20%3D%20%22%22%3B%0A%20%20char%20*line%20%3D%20%22zzzzzzzzzzzzzzzzzzzz%22%3B%0A%20%20printf%28%22%25s%22,%20return_in_line%28buffer,%20str,%20line%29%29%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
//https://pythontutor.com/render.html#code=%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstdio.h%3E%0A%0Asize_t%20%20%20%20ft_strlen%28const%20char%20*str%29%0A%7B%0A%20%20%20%20int%20%20%20%20i%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20while%20%28str%5Bi%5D%29%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20return%20%28i%29%3B%0A%7D%0A%0Asize_t%20%20%20%20ft_strlenn%28const%20char%20*str%29%0A%7B%0A%20%20%20%20size_t%20%20%20%20i%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20while%20%28str%5Bi%5D%20!%3D%20'%5Cn'%20%26%26%20str%5Bi%5D%29%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20return%20%28i%29%3B%0A%7D%0A%0Asize_t%20%20%20%20ft_strlcpy%28char%20*dst,%20const%20char%20*src,%20size_t%20dstsize%29%0A%7B%0A%20%20%20%20size_t%20%20%20%20i%3B%0A%0A%20%20%20%20if%20%28dstsize%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20return%20%28ft_strlen%28src%29%29%3B%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20while%20%28src%5Bi%5D%20%26%26%20i%20%3C%20%28dstsize%20-%201%29%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20dst%5Bi%5D%20%3D%20src%5Bi%5D%3B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20dst%5Bi%5D%20%3D%20'%5C0'%3B%0A%20%20%20%20return%20%28ft_strlen%28src%29%29%3B%0A%7D%0A%0Achar%20%20%20%20*ft_strjoin%28char%20const%20*s1,%20char%20const%20*s2%29%0A%7B%0A%20%20%20%20char%20%20%20%20*str%3B%0A%0A%20%20%20%20if%20%28!s1%20%7C%7C%20!s2%29%0A%20%20%20%20%20%20%20%20return%20%28NULL%29%3B%0A%20%20%20%20str%20%3D%20malloc%28sizeof%28char%29%20*%20%28ft_strlen%28s1%29%20%2B%20ft_strlen%28s2%29%20%2B%201%29%29%3B%0A%20%20%20%20if%20%28!str%29%0A%20%20%20%20%20%20%20%20return%20%28NULL%29%3B%0A%20%20%20%20ft_strlcpy%28str,%20s1,%20ft_strlen%28s1%29%20%2B%201%29%3B%0A%20%20%20%20ft_strlcpy%28str%20%2B%20ft_strlen%28s1%29,%20s2,%20ft_strlenn%28s2%29%20%2B%201%29%3B%0A%20%20%20%20return%20%28str%29%3B%0A%7D%0A%0Achar%20%20%20%20*return_in_line%28char%20*buffer,%20char%20*str,%20char%20*line%29%0A%7B%0A%20%20%20%20int%20%20%20%20%20%20%20%20j%3B%0A%20%20%20%20int%20%20%20%20%20%20%20%20i%3B%0A%20%20%20%20char%20%20%20%20*tmp%3B%0A%20%20%20%20char%20%20%20%20*result%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20j%20%3D%20ft_strlenn%28buffer%29%20%2B%201%3B%0A%20%20%20%20str%20%3D%20malloc%28sizeof%28char%29%20*%20%28ft_strlen%28buffer%29%20-%20ft_strlenn%28buffer%29%20-%201%29%29%3B%0A%20%20%20%20while%20%28buffer%5Bj%5D%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20str%5Bi%5D%20%3D%20buffer%5Bj%5D%3B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20j%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20tmp%20%3D%20malloc%28sizeof%28char%29%20*%20%28j%20-%20i%20%2B%201%29%29%3B%0A%20%20%20%20i%20%3D%20-1%3B%0A%20%20%20%20while%20%28buffer%5B%2B%2Bi%5D%20!%3D%20'%5Cn'%29%0A%20%20%20%20%20%20%20%20tmp%5Bi%5D%20%3D%20buffer%5Bi%5D%3B%0A%20%20%20%20tmp%5Bi%2B%2B%5D%20%3D%20'%5Cn'%3B%0A%20%20%20%20tmp%5Bi%5D%20%3D%20'%5C0'%3B%0A%20%20%20%20result%20%3D%20ft_strjoin%28line,%20tmp%29%3B%0A%20%20%20%20return%20%28result%29%3B%0A%7D%0A%0Aint%20main%28%29%0A%7B%0A%20%20char%20*buffer%20%3D%20%22ahsjdadhajvcsjhavxcjhdvfsdfsfsdfs%5Cnasd%5Cndsfsj%22%3B%0A%20%20char%20*str%20%3D%20%22%22%3B%0A%20%20char%20*line%20%3D%20%22zzzzzzzzzzzzzzzzzzzz%22%3B%0A%20%20printf%28%22%25s%22,%20return_in_line%28buffer,%20str,%20line%29%29%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false