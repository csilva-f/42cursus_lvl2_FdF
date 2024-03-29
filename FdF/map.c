/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:48:51 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/25 09:33:39 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

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
		free(aux);
	}
	free(aux);
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

char	***dim_map(char *argv, t_fdf *fdf, int nl, int g3)
{
	char	*aux;
	char	***gstr;
	int		*graph;

	graph = (int *)malloc(3 * sizeof(int));
	gstr = (char ***)malloc(sizeof(char **) * nl);
	graph[0] = -1;
	graph[2] = open(argv, O_RDONLY);
	while (1)
	{
		graph[1] = -1;
		aux = get_next_line(graph[2]);
		if (aux == NULL)
			break ;
		gstr[++graph[0]] = ft_split(rem_bl2(aux), ' ');
		while (gstr[graph[0]][++graph[1]] != 0)
			g3++;
		free(aux);
	}
	free(aux);
	init_fdf(fdf, ++graph[0], (g3 / graph[0]), g3);
	fdf->file = argv;
	close(graph[2]);
	free(graph);
	return (gstr);
}
