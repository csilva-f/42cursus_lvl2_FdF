/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:21:15 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/20 22:50:47 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs_float(float c)
{
	if (c < 0)
		c *= -1;
	return (c);
}

void	line_low(t_fdf *fdf, t_p *p0, t_p *p1)
{
	float	dy;
	float	y;
	float	x;
	float	p;

	dy = p1->y - p0->y;
	if (dy < 0)
		dy *= -1;
	p = (2 * dy) - (p1->x - p0->x);
	y = p0->y;
	x = p0->x;
	while (x <= p1->x)
	{
		my_mlx_pixel_put(fdf, x++, y, 0xFF0000);
		if (p > 0)
		{
			if (dy < 0)
				y--;
			else
				y++;
			p = p + (2 * (dy - (p1->x - p0->x)));
		}
		else
			p = p + 2 * dy;
	}
}

void	line_high(t_fdf *fdf, t_p *p0, t_p *p1)
{
	float	dx;
	float	y;
	float	x;
	float	p;

	dx = p1->x - p0->x;
	if (dx < 0)
		dx *= -1;
	p = (2 * dx) - (p1->y - p0->y);
	y = p0->y;
	x = p0->x;
	while (y <= p1->y)
	{
		my_mlx_pixel_put(fdf, x, y++, 0xFF0000);
		if (p > 0)
		{
			if (dx < 0)
				x--;
			else
				x++;
			p = p + (2 * (dx - (p1->y - p0->y)));
		}
		else
			p = p + 2 * dx;
	}
}

void	line(t_fdf *fdf, t_p *p0, t_p *p1)
{
	if (ft_abs_float(p1->y - p0->y) < ft_abs_float(p1->x - p0->x))
	{
		//if (p0->x > p1->x)
			//line_low(fdf, p1, p0);
	//	else
			line_low(fdf, p0, p1);
	}
	else
	{
		if (p0->y > p1->y)
			line_high(fdf, p1, p0);
		else
			line_high(fdf, p0, p1);
	}
}

void	draw_lines(t_fdf *fdf)
{
	int	i;
	int	nc;

	i = -1;
	nc = fdf->arr->nc;
	while (++i < fdf->arr->n)
	{
		printf("i: %d----------------------------------------\n", i);
		if (fdf->arr->ps[i]->is_f == 0)
		{
			line(fdf, fdf->arr->ps[i], fdf->arr->ps[i + 1]);
			printf("H\n");
		}
		if ((i / fdf->arr->nc) < (fdf->arr->nl - 1))
		{	
			line(fdf, fdf->arr->ps[i], fdf->arr->ps[i + nc]);
			printf("V\n");
		}
	}
}
