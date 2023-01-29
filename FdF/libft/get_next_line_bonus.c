/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:48:01 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/19 10:20:03 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_str_from_fd(int fd, char *str)
{
	int		nbr;
	char	*buf_str;

	buf_str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf_str == NULL)
		return (NULL);
	nbr = 1;
	while (!ft_strchr(str, '\n') && nbr != 0)
	{
		nbr = read(fd, buf_str, BUFFER_SIZE);
		if (nbr < 0)
		{
			free(str);
			free(buf_str);
			return (NULL);
		}
		buf_str[nbr] = '\0';
		str = ft_strjoin(str, buf_str);
	}
	free(buf_str);
	return (str);
}

char	*ft_trim_line(char	*str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
	{
		line[i] = str[i];
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trim_str(char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str_new;

	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	str_new = (char *)malloc(sizeof(char) * (len - i + 1));
	if (str_new == NULL)
		return (NULL);
	j = 0;
	while (str[++i] != '\0')
		str_new[j++] = str[i];
	str_new[j] = '\0';
	free(str);
	return (str_new);
}

char	*get_next_line(int fd)
{
	static char	*arr_str[100000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!arr[fd])
	{
		arr[fd] = malloc(1 * sizeof(char));
		arr[fd][0] = '\0';
	}
	arr_str[fd] = get_str_from_fd(fd, arr_str[fd]);
	if (arr_str[fd] == NULL)
		return (NULL);
	line = ft_trim_line(arr_str[fd]);
	arr_str[fd] = ft_trim_str(arr_str[fd]);
	return (line);
}
