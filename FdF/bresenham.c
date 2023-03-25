/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:21:15 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/25 11:44:30 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_round(float nbr)
{
	int	c;

	c = (int)nbr;
	if (nbr - (float)c >= 0.5)
		c++;
	return (c);
}

t_bres	init_s(t_p *p0, t_p *p1)
{
	t_bres	s;

	s.x0 = p0->x;
	s.y0 = p0->y;
	s.x1 = p1->x;
	s.y1 = p1->y;
	s.dx = ft_abs(ft_round(s.x1 - s.x0));
	s.sx = -1;
	if (s.x0 < s.x1)
		s.sx = 1;
	s.dy = -1 * ft_abs(ft_round(s.y1 - s.y0));
	s.sy = -1;
	if (s.y0 < s.y1)
		s.sy = 1;
	s.e = s.dx + s.dy;
	return (s);
}

void	plotline(t_fdf *fdf, t_p *p0, t_p *p1, int color)
{
	t_bres	s;

	s = init_s(p0, p1);
	while (1)
	{
		if (s.x0 < W_WIDTH && s.x0 > 0 && s.y0 < W_HEIGHT && s.y0 > 0)
			my_mlx_pixel_put(fdf, s.x0, s.y0, color);
		if (s.x0 == s.x1 && s.y0 == s.y1)
			break ;
		s.e2 = 2 * s.e;
		if (s.e2 >= s.dy)
		{
			if (s.x0 == s.x1)
				break ;
			s.e = s.e + s.dy;
			s.x0 = s.x0 + s.sx;
		}
		if (s.e2 <= s.dx)
		{
			if (s.y0 == s.y1)
				break ;
			s.e = s.e + s.dx;
			s.y0 = s.y0 + s.sy;
		}
	}
}

void	draw_lines(t_fdf *fdf, int color, int n_color)
{
	int	i;
	int	nc;

	i = -1;
	nc = fdf->arr->nc;
	while (++i < fdf->arr->n)
	{
		if (fdf->arr->ps[i]->color != 0)
			color = fdf->arr->ps[i]->color;
		if (n_color != 0)
			color = n_color;
		if ((i + 1) % fdf->arr->nc > 0)
			plotline(fdf, fdf->arr->ps[i], fdf->arr->ps[i + 1], color);
		if (i + fdf->arr->nc < fdf->arr->n)
			plotline(fdf, fdf->arr->ps[i], fdf->arr->ps[i + nc], color);
	}
}
