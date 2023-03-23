/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:21:15 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/23 02:39:27 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs_float(float c)
{
	if (c < 0)
		c *= -1;
	return (c);
}

float	ft_max_fl(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	bres(t_fdf *fdf, t_p *p0, t_p *p1, int color)
{
	float	x_st;
	float	y_st;
	float	max;

	x_st = p1->x - p0->x;
	y_st = p1->y - p0->y;
	max = ft_max_fl(ft_abs_float(x_st), ft_abs_float(y_st));
	x_st = x_st / max;
	y_st = y_st / max;
	while ((int)(p0->x - p1->x) || (int)(p0->y - p1->y))
	{
		if (p0->x > 0 && p0->x < W_WIDTH && p0->y > 0 && p0->y < W_HEIGHT)
			my_mlx_pixel_put(fdf, p0->x, p0->y, color);
		p0->x += x_st;
		p0->y += y_st;
	}
}

void	draw_lines_2(t_fdf *fdf)
{
	int	i;
	int	nc;
	int	color;

	i = 0;
	color = 0xFF0000;
	nc = fdf->arr->nc;
	while (i < fdf->arr->n)
	{
		if (fdf->arr->ps[i]->color != 0)
			color = fdf->arr->ps[i]->color;
		if (fdf->arr->ps[i]->is_f == 0 && (i % nc) != (nc - 1))
			//line_low(fdf, fdf->arr->ps[i], fdf->arr->ps[i + 1], color);
			bres(fdf, fdf->arr->ps[i], fdf->arr->ps[i + 1], color);
		i++;
	}	
}

void	draw_lines(t_fdf *fdf)
{
	int	i;
	int	nc;
	int	color;

	i = -1;
	color = 0xFF0000;
	nc = fdf->arr->nc;
	while (++i < fdf->arr->n)
	{
		if (fdf->arr->ps[i]->color != 0)
			color = fdf->arr->ps[i]->color;
		if ((i / nc) < (fdf->arr->nl - 1))
			bres(fdf, fdf->arr->ps[i], fdf->arr->ps[i + nc], color);
	}
	draw_lines_2(fdf);
}

/*void	line_aux(float *dx1, float *dx2, t_p *p0, t_p *p1)
{
	(*dx1) = 0;
	(*dx2) = 0;
	if ((p1->x - p0->x) < 0)
	{
		(*dx1) = -1;
		(*dx2) = -1;
	}
	else if ((p1->x - p0->x) > 0)
	{
		(*dx1) = 1;
		(*dx2) = 1;
	}
}

void	line_aux_2(float *dy1, float *dy2, t_p *p0, t_p *p1)
{
	(*dy1) = 0;
	(*dy2) = 0;
	if ((p1->y - p0->y) < 0)
		(*dy1) = -1;
	else if ((p1->y - p0->y) > 0)
		(*dy1) = 1;
}

void	line(t_fdf *fdf, t_p *p0, t_p *p1)
{
	float		*d;
	int		i;

	d = (float *)malloc(7 * sizeof(float));
	line_aux(&d[0], &d[1], p0, p1);
	line_aux_2(&d[2], &d[3], p0, p1);
	d[4] = ft_abs_float(p1->x - p0->x);
	d[5] = ft_abs_float(p1->y - p0->y);
	if (!(d[4] > d[5]))
	{
        d[4] = ft_abs_float(p1->y - p0->y);
        d[5] = ft_abs_float(p1->x - p0->x);
        if (p1->y - p0->y < 0)
			d[3] = -1;
		else if (p1->y - p0->y > 0)
			d[3] = 1;
        d[1] = 0;
	}
	i = -1;
	d[6] = (int)d[4] >> 1;
	while (++i <= d[4])
	{
        my_mlx_pixel_put(fdf, p0->x, p0->y, 0xFF0000);
        d[6] += d[5];
		if (!(d[6] < d[4]))
		{
			d[6] -= d[4];
			p0->x += d[0];
			p0->y += d[2];
		}
		else
		{
			p0->x += d[1];
			p0->y += d[3];
		}
	}
	free(d);
}

void	line_low(t_fdf *fdf, t_p *p0, t_p *p1, int color)
{
	float	dy;
	float	dx;
	float	y;
	float	x;
	float	p;

	dy = p1->y - p0->y;
	dx = p1->x - p0->x;
	p = 2 * dy - dx;
	y = p0->y;
	x = p0->x;
	while (x <= p1->x)
	{
		my_mlx_pixel_put(fdf, x++, y, color);
		if (p >= 0)
		{
			y++;
			p = p - 2 * dx + 2 * dy;
		}
		else
			p = p + 2 * dy;
	}
}*/
