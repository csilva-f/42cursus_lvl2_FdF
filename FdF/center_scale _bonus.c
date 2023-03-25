/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:30:47 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/23 21:29:32 by csilva-f         ###   ########.fr       */
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
	while (++i < fdf->arr->n)
	{
		aux = fdf->arr->ps[i]->x;
		fdf->arr->ps[i]->x = aux * fdf->s;
		aux = fdf->arr->ps[i]->y;
		fdf->arr->ps[i]->y = aux * fdf->s;
	}
}

void	center_map_win_aux(t_fdf *fdf)
{
	int		i;
	float	aux_y;
	float	aux_z;
	float	aux;

	i = -1;
	aux = atan(sqrt(2));
	while (++i < fdf->arr->n)
	{
		aux_y = fdf->arr->ps[i]->y;
		aux_z = fdf->arr->ps[i]->z;
		fdf->arr->ps[i]->y = (aux_y * cos(aux)) - (aux_z * sin(aux));
		fdf->arr->ps[i]->z = (aux_y * sin(aux)) + (aux_z * cos(aux));
	}
}
