/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_scale_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:26:49 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/21 22:27:12 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	center_map_win(t_fdf *fdf)
{
	int		i;
	float	aux_x;
	float	aux_y;

	center_map(fdf);
	scale_map(fdf);
	i = -1;
	while (++i < fdf->arr->n)
	{
		aux_x = fdf->arr->ps[i]->x;
		aux_y = fdf->arr->ps[i]->y;
		fdf->arr->ps[i]->x = (aux_x * cos(PI / 4)) - (aux_y * sin(PI / 4));
		fdf->arr->ps[i]->y = (aux_x * sin(PI / 4)) + (aux_y * cos(PI / 4));
	}
	center_map_win_aux(fdf);
	i = -1;
	while (++i < fdf->arr->n)
	{
		fdf->arr->ps[i]->x += (W_WIDTH / 2.0);
		fdf->arr->ps[i]->y += (W_HEIGHT / 2.0);
	}
}

/*int	max_z(t_fdf *fdf)
{
	int	i;
	int	aux;

	i = 0;
	while (i < fdf->arr->n)
	{
		if (i == 0 || aux < fdf->arr->ps[i]->z)
			aux = fdf->arr->ps[i]->z;
		i++;
	}
	return (aux);
}

int	min_z(t_fdf *fdf)
{
	int	i;
	int	aux;

	i = 0;
	while (i < fdf->arr->n)
	{
		if (i == 0 || aux > fdf->arr->ps[i]->z)
			aux = fdf->arr->ps[i]->z;
		i++;
	}
	return (aux);
}

void	find_scale_z(t_fdf *fdf)
{
	int	delta;

	delta = max_z(fdf) - min_z(fdf);
	fdf->s_z = 250 / delta;
}*/
