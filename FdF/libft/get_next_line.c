/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:45:37 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/25 16:45:40 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_emptypocket(char **pocket)
{
	if (*pocket != NULL && !ft_findchr(*pocket, '\0'))
	{
		free(*pocket);
		*pocket = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*pocket;
	char		*l;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n >= 0)
			buffer[n] = '\0';
		else
			buffer[0] = '\0';
		pocket = ft_strjoinfree(pocket, buffer);
		l = ft_getl(pocket, &n);
		pocket = ft_fillpocket(pocket, &n);
	}
	ft_emptypocket(&pocket);
	free(buffer);
	return (l);
}
