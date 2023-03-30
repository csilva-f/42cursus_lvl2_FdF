/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_scale2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:26:49 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/30 22:33:26 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <math.h>

void	delta_z(t_fdf *fdf)
{
	int	i;
	int	min;
	int	max;

	i = -1;
	min = 0;
	max = 0;
	while (++i < fdf->arr->n)
	{
		if (max < fdf->arr->ps[i]->z)
			max = fdf->arr->ps[i]->z;
		if (min > fdf->arr->ps[i]->z)
			min = fdf->arr->ps[i]->z;
	}
	fdf->arr->zmax = max;
	fdf->arr->zmin = min;
}

void	get_z_scale(t_fdf *fdf)
{
	int		i;
	int		n_max;
	float	s;

	i = -1;
	s = 0;
	delta_z(fdf);
	if (fdf->arr->nc > fdf->arr->nl)
		n_max = fdf->arr->nc;
	else
		n_max = fdf->arr->nl;
	if (fdf->arr->zmax - fdf->arr->zmin)
		s = (0.1 * n_max * fdf->s) / (fdf->arr->zmax - fdf->arr->zmin);
	if (s < 1)
		fdf->s_z = 1;
	else
		fdf->s_z = s;
}

void	apply_z_scale(t_fdf *fdf)
{
	int		i;
	float	aux;

	i = -1;
	get_z_scale(fdf);
	while (++i < fdf->arr->n)
	{
		aux = fdf->arr->ps[i]->z;
		fdf->arr->ps[i]->z = aux * fdf->s_z;
	}
}

void	isometric_map(t_fdf *fdf)
{
	int		i;
	float	aux_x;
	float	aux_y;

	i = -1;
	while (++i < fdf->arr->n)
	{
		aux_x = fdf->arr->ps[i]->x;
		aux_y = fdf->arr->ps[i]->y;
		fdf->arr->ps[i]->x = (aux_x * cos(PI / 4)) - (aux_y * sin(PI / 4));
		fdf->arr->ps[i]->y = (aux_x * sin(PI / 4)) + (aux_y * cos(PI / 4));
	}
}

void	center_map_win(t_fdf *fdf)
{
	int		i;

	center_map(fdf);
	scale_map(fdf);
	apply_z_scale(fdf);
	isometric_map(fdf);
	center_map_win_aux(fdf);
	i = -1;
	while (++i < fdf->arr->n)
	{
		fdf->arr->ps[i]->x += (W_WIDTH / 2.0);
		fdf->arr->ps[i]->y += (W_HEIGHT / 2.0);
	}
	fdf->arr2 = (t_arr *)malloc(sizeof(t_arr));
	if (!(fdf->arr2))
		error_handler(0);
	fdf->arr2->ps = (t_p **)malloc(sizeof(t_p *) * (fdf->arr->n));
	if (!(fdf->arr2->ps))
		error_handler(0);
	i = -1;
	fdf->arr2->n = fdf->arr->n;
	fdf->arr2->nl = fdf->arr->nl;
	fdf->arr2->nc = fdf->arr->nc;
	while (++i < fdf->arr->n)
		fdf->arr2->ps[i] = fdf->arr->ps[i];
}
