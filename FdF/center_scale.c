/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:30:47 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/21 20:07:40 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_scale(t_fdf *fdf)
{
	int		dh;
	int		dw;
	//int		n;
	float	aux;

	dh = ft_abs(W_HEIGHT - 1080);
	dw = ft_abs(W_WIDTH - 1920);
	//if (fdf->arr->nc > fdf->arr->nl)
	//	n = (10 * 45) / fdf->arr->nc;
	//else
	//	n = (10 * 45) / fdf->arr->nl;
	fdf->s = 0.05;//n;
	if (dh != 0 || dw != 0)
	{
		if (dh > dw)
			aux = (W_HEIGHT * 55.0) / 1080;
		else
			aux = (W_WIDTH * 55.0) / 1920;
		fdf->s = aux;
	}
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
	while (++i < fdf->arr->n)
	{
		aux = fdf->arr->ps[i]->x;
		fdf->arr->ps[i]->x = aux * fdf->s;
		aux = fdf->arr->ps[i]->y;
		fdf->arr->ps[i]->y = aux * fdf->s;
	}
}

void	center_map_win(t_fdf *fdf)
{
	int		i;
	float	aux;

	i = -1;
	center_map(fdf);
	scale_map(fdf);
	while (++i < fdf->arr->n)
	{
		aux = fdf->arr->ps[i]->x;
		fdf->arr->ps[i]->x = aux + (W_WIDTH / 2.0);
		aux = fdf->arr->ps[i]->y;
		fdf->arr->ps[i]->y = aux + (W_HEIGHT / 2.0);
	}
	print_fdf(fdf);
}
