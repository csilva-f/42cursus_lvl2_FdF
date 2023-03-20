/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:30:47 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/20 21:34:44 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	find_scale(t_fdf *fdf)
{
	float	h_real;
	float	h_scale;
	float	a;
	float	b;

	a = fdf->arr->ps[fdf->arr->n - 1]->x - fdf->arr->ps[0]->x;
	b = fdf->arr->ps[fdf->arr->n - 1]->y - fdf->arr->ps[0]->y;
	h_real = sqrtf(powf(a, 2) + powf(b, 2));
	if (W_HEIGHT > W_WIDTH)
		h_scale = 0.7 * W_WIDTH;
	else
		h_scale = 0.7 * W_HEIGHT;
	fdf->s = h_scale / h_real;
}

int	max_z(t_fdf *fdf)
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
}

void	center_lines(t_fdf *fdf, int i)
{
	int	nc;
	int	nl;
	int	aux;

	nc = fdf->arr->nc;
	nl = fdf->arr->nl;
	if (nl % 2 == 0)
	{
		aux = i / nc;
		fdf->arr->ps[i]->y = ((nl / -2.0) + aux + 0.5);
	}
	else
	{
		aux = ((nl - 1) / -2) + (i / nc);
		fdf->arr->ps[i]->y = aux;
	}	
}

void	center_map(t_fdf *fdf)
{
	int	i;
	int	nc;
	int	nl;
	int	aux;

	i = -1;
	nc = fdf->arr->nc;
	nl = fdf->arr->nl;
	while (++i < fdf->arr->n)
	{
		if (nc % 2 == 0)
		{
			aux = (i % nc);
			fdf->arr->ps[i]->x = ((nc / -2.0) + aux + 0.5);
		}
		else
		{
			aux = ((nc - 1) / -2.0) + (i % nc);
			fdf->arr->ps[i]->x = aux;
		}
		center_lines(fdf, i);
	}
}

void	scale_map(t_fdf *fdf)
{
	int		i;
	float	aux;

	i = -1;
	find_scale(fdf);
	printf("scale: %f\n", fdf->s);
	//find_scale_z(fdf);
	while (++i < fdf->arr->n)
	{
		aux = fdf->arr->ps[i]->x;
		fdf->arr->ps[i]->x = aux * fdf->s;
		aux = fdf->arr->ps[i]->y;
		fdf->arr->ps[i]->y = aux * fdf->s;
		//aux = fdf->arr->ps[i]->z;
		//fdf->arr->ps[i]->z = aux * 2;//(fdf->s / 10);
	}
}

void	center_map_win(t_fdf *fdf)
{
	int		i;
	float	aux;
	float	aux_x;
	float	aux_y;
	float	aux_z;

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
	i = -1;
	while (++i < fdf->arr->n)
	{
		aux_y = fdf->arr->ps[i]->y;
		aux_z = fdf->arr->ps[i]->z;
		fdf->arr->ps[i]->y = (aux_y * cos(atan(sqrt(2)))) - (aux_z * sin(atan(sqrt(2))));
		fdf->arr->ps[i]->z = (aux_y * sin(atan(sqrt(2)))) + (aux_z * cos(atan(sqrt(2))));
	}
	i = -1;
	while (++i < fdf->arr->n)
	{
		aux = fdf->arr->ps[i]->x;
		fdf->arr->ps[i]->x = aux + (W_WIDTH / 2.0);
		aux = fdf->arr->ps[i]->y;
		fdf->arr->ps[i]->y = aux + (W_HEIGHT / 2.0);
	}
}
