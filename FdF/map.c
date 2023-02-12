/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:48:51 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/12 21:36:03 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	check_file(char *file_name)
{
	int	i;
	int	c;

	i = 0;
	c = -1;
	while (file_name[i] != '\0' && file_name[i] != '.')
		i++;
	if (file_name[i] == '.')
	{
		i++;
		c = ft_strncmp(&file_name[i], "fdf", 3);
	}
	if (c == 0)
		return (1);
	return (0);
}

char	*rem_line_feed(char *str)
{
	int		len;
	char	*new;
	int		i;

	i = -1;
	len = ft_strlen(str);
	if (str[len] != '\0' || str[len - 1] != '\n')
	{
		error_handler(3);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
	{
		error_handler(3);
		return (NULL);
	}
	while (str[++i] != '\n')
		new[i] = str[i];
	if (str[i] == '\n')
		new[i] = '\0';
	return (new);
}

int	check_coma(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i > 0 && str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	hex_atoi(char *str)
{
	int	i;
	int	res;
	int	n;

	i = 0;
	res = 0;
	if (str[0] == '0' && str[1] == 'x')
		i = 2;
	while (i > 1 && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 16 + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
		{
			n = str[i] - 'a' + 10;
			res = res * 16 + n;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			n = str[i] - 'A' + 10;
			res = res * 16 + n;
		}
		i++;
	}
	return (res);
}

void	dim_map(char *argv, t_fdf *fdf)
{
	char	*aux;
	char	**strs;
	int		i;
	int		fd;
	t_arr	*arr;

	i = 0;
	fd = open(argv, O_RDONLY);
	aux = get_next_line(fd);
	if (aux == NULL)
		error_handler(3);
	else
		aux = rem_line_feed(aux);
	while (aux != NULL)
	{
		strs = ft_split((const char *)aux, ' ');
		while (strs[i] != 0)
			i++;
		free(aux);
		aux = get_next_line(fd);
	}
	i++;
	arr = (t_arr *)malloc(sizeof(t_arr));
	fdf->arr = arr;
	fdf->arr->ps = (t_p **)malloc(sizeof(t_p *) * i);
	if (!(fdf->arr->ps))
		error_handler(0);
	fdf->arr->n = i;
	close(fd);
}
