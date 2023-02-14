/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:48:51 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/14 20:30:21 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	count_l(char *argv)
{
	char	*aux;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (1)
	{
		aux = get_next_line(fd);
		i++;
		if (aux == NULL)
			break ;
	}
	close(fd);
	return (i);
}

void	init_fdf(t_fdf *fdf, int i, int j, int k)
{
	fdf->arr = (t_arr *)malloc(sizeof(t_arr));
	if (!(fdf->arr))
		error_handler(0);
	fdf->arr->ps = (t_p **)malloc(sizeof(t_p *) * k);
	if (!(fdf->arr->ps))
		error_handler(0);
	fdf->arr->n = k;
	fdf->arr->nl = i;
	fdf->arr->nc = j;
}
