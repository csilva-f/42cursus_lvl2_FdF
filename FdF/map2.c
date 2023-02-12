/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:43:34 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/12 20:22:01 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_coord_color(t_fdf *fdf, char *str, int k)
{
	int		i;
	char	**s;

	i = 0;
	s = ft_split((const char *)str, ',');
	while (s[i] != 0)
		i++;
	if (i != 2)
		error_handler(0);
	else
	{
		fdf->arr->ps[k]->z = ft_atoi((const char *)s[0]);
		fdf->arr->ps[k]->color = hex_atoi(s[1]);
	}
}

void	fill_map_2(char *aux, t_fdf *fdf, int k, int i)
{
	int		j;
	char	**strs;

	j = 0;
	strs = ft_split((const char *)aux, ' ');
	while (strs[j] != 0)
	{
		fdf->arr->ps[k]->x = j;
		fdf->arr->ps[k]->y = i;
		if (check_coma(strs[j]) == 1)
			fill_coord_color(fdf, strs[j], k);
		else
		{
			fdf->arr->ps[k]->z = ft_atoi(strs[j]);
			fdf->arr->ps[k]->color = 0;
			fdf->arr->ps[k]->is_f = 0;
			fdf->arr->ps[k]->xmax = 0;
		}
		j++;
	}
	fdf->arr->ps[k]->is_f = 1;
	fdf->arr->ps[k]->xmax = j;
}

void	fill_map(char *argv, t_fdf *fdf)
{
	char	*aux;
	int		i;
	int		k;
	int		fd;

	i = 0;
	k = 0;
	dim_map(argv, fdf);
	fd = open(argv, O_RDONLY);
	aux = get_next_line(fd);
	if (aux == NULL)
		error_handler(3);
	else
		aux = rem_line_feed(aux);
	while (aux != NULL)
	{
		fill_map_2(aux, fdf, k, i);
		free(aux);
		aux = get_next_line(fd);
		i++;
		k++;
	}
	fdf->arr->nl = i;
	close(fd);
}

int	valid_map(t_fdf fdf)
{
	int	i;
	int	aux;
	int	flag;

	i = 0;
	flag = 0;
	while (i < fdf.arr->n)
	{
		if (fdf.arr->ps[i]->is_f == 1)
		{
			if (flag == 1 && aux != fdf.arr->ps[i]->xmax)
				return (0);
			else if (flag == 0)
				aux = fdf.arr->ps[i]->xmax;
			flag = 1;	
		}
		i++;
	}
	return (1);
}
