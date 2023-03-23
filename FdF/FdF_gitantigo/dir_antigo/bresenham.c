/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:21:15 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/21 00:35:34 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs_float(float c)
{
	if (c < 0)
		c *= -1;
	return (c);
}

/*void	line_low(t_fdf *fdf, t_p *p0, t_p *p1)
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
		if (p0->x > p1->x)
			line_low(fdf, p1, p0);
		else
			line_low(fdf, p0, p1);
	}
	else
	{
		if (p0->y > p1->y)
			line_high(fdf, p1, p0);
		else
			line_high(fdf, p0, p1);
	}
}*/

/*void	line(t_fdf *fdf, t_p *p0, t_p *p1)
{
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	float	x;
	float	y;
	float	e;
	float	e2;

	dx = ft_abs_float(p1->x - p0->x);
	dy = -1 * ft_abs_float(p1->y - p0->y);
	sx = 1;
	sy = 1;
	if (p0->x > p1->x)
		sx *= -1;
	if (p0->y > p1->y)
		sy *= -1;
	sx = p0->x < p1->x ? 1 : -1;
	sy = p0->y < p1->y ? 1 : -1;
	e = dx + dy;
	x = p0->x;
	y = p0->y;
	while (1)
	{
		my_mlx_pixel_put(fdf, x, y, 0xFF0000);
		if (x == p1->x && y == p1->y)
			break ;
		e2 = 2 * e;
		if (e2 >= dy)
		{
			if (x == p1->x)
				break ;
			e += dy;
			x += sx;
		}
		if (e2 <= dx)
		{
			if (y == p1->y)
				break ;
			e += dx;
			y += sy;
		}
	}
}*/

void	line(t_fdf *fdf, t_p *p0, t_p *p1)
{
    float	w;
    float	h;
    float	dx1;
	float	dy1;
	float	dx2;
	float	dy2;
	float	longest;
    float	shortest;

	w = p1->x - p0->x;
	h = p1->y - p0->y;
	dx1 = 0;
	dy1 = 0;
	dx2 = 0;
	dy2 = 0;
    if (w < 0 || w > 0)
	{
		if (w < 0)
		{
			dx1 = -1;
			dx2 = -1;
		}
		else
		{
			dx1 = 1;
			dx2 = 1;
		}
	}
    if (h < 0 || h > 0)
	{
		if (h < 0)
			dy1 = -1;
		else
			dy1 = 1;
	}
	longest = ft_abs_float(w);
    shortest = ft_abs_float(h);
    if (!(longest > shortest))
	{
        longest = ft_abs_float(h);
        shortest = ft_abs_float(w);
        if (h < 0)
			dy2 = -1;
		else if (h > 0)
			dy2 = 1;
        dx2 = 0;            
    }
    int	numerator = (int)longest >> 1 ;
    for (int i = 0; i <= longest ; i++) {
        my_mlx_pixel_put(fdf, p0->x, p0->y, 0xFF0000) ;
        numerator += shortest ;
        if (!(numerator<longest)) {
            numerator -= longest ;
            p0->x += dx1 ;
            p0->y += dy1 ;
        } else {
            p0->x += dx2 ;
            p0->y += dy2 ;
        }
    }
}

void	draw_lines(t_fdf *fdf)
{
	int	i;
	int	nc;
	int	count;

	i = -1;
	nc = fdf->arr->nc;
	count = 0;
	while (++i < fdf->arr->n)
	{
		printf("i: %d----------------------------------------\n", i);
		if (fdf->arr->ps[i]->is_f == 0)
		{
			line(fdf, fdf->arr->ps[i], fdf->arr->ps[i + 1]);
			printf("H\n");
		}
		/*if ((i / nc) < (fdf->arr->nl - 1) && count < 3)
		{	
			line(fdf, fdf->arr->ps[i], fdf->arr->ps[i + nc]);
			printf("V\n");
			count++;
		}*/
	}
	i = 0;
	while (i < fdf->arr->n)
	{
		/*printf("i: %d----------------------------------------\n", i);
		if (fdf->arr->ps[i]->is_f == 0)
		{
			line(fdf, fdf->arr->ps[i], fdf->arr->ps[i + 1]);
			printf("H\n");
		}*/
		if ((i / nc) < (fdf->arr->nl - 1) && count < 3)
		{
			line(fdf, fdf->arr->ps[i], fdf->arr->ps[i + nc]);
			count++;
		}
		i++;
	}
}
