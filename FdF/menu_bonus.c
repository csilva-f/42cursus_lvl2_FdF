/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:49:21 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/25 09:13:16 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_menu_2(int y, void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, y += 20, WHITE, "Change color:");
	mlx_string_put(mlx, win, 10, y += 15, WHITE, "   - Yellow [1]");
	mlx_string_put(mlx, win, 10, y += 15, WHITE, "   - Red [2]");
	mlx_string_put(mlx, win, 10, y += 15, WHITE, "   - Blue [3]");
	mlx_string_put(mlx, win, 10, y += 15, WHITE, "   - Pink [4]");
	mlx_string_put(mlx, win, 10, y += 15, WHITE, "   - Green [5]");
	mlx_string_put(mlx, win, 10, y += 20, WHITE, "Apply gradient:");
	mlx_string_put(mlx, win, 10, y += 15, WHITE, "   - [6] [7] [8]");
	mlx_string_put(mlx, win, 10, y += 20, WHITE, "Reset: [R]");
	mlx_string_put(mlx, win, 10, y += 20, WHITE, "Exit: ESC");
}

void	create_menu(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	int		y;

	y = 0;
	mlx = fdf->mlx_ptr;
	win = fdf->win->win_ptr;
	if (W_HEIGHT > 350 && W_WIDTH > 100)
	{
		mlx_set_font(mlx, win, "6x12");
		mlx_string_put(mlx, win, 10, y += 15, WHITE, "Move: Arrow keys");
		mlx_string_put(mlx, win, 10, y += 15, WHITE, "Zoom: Mouse wheel");
		mlx_string_put(mlx, win, 60, y += 20, WHITE, "Rotate:");
		mlx_string_put(mlx, win, 10, y += 15, WHITE, "X-Axis");
		mlx_string_put(mlx, win, 10, y += 15, WHITE, "Y-Axis");
		mlx_string_put(mlx, win, 10, y += 15, WHITE, "Z-Axis");
		mlx_string_put(mlx, win, 10, y += 20, WHITE, "Change Projection:");
		mlx_string_put(mlx, win, 10, y += 15, WHITE, "   - Isometric [I]");
		mlx_string_put(mlx, win, 10, y += 15, WHITE, "   - Parallel [P]");
		create_menu_2(y, mlx, win);
	}
}

float	get_min_x(t_fdf *fdf)
{
	int		i;
	float	min;

	i = -1;
	min = 0;
	while (++i < fdf->arr->n && fdf->arr->n > 0)
	{
		if (i == 0 || fdf->arr->ps[i]->x < min)
			min = fdf->arr->ps[i]->x;
	}
	return (min);
}

float	get_max_x(t_fdf *fdf)
{
	int		i;
	float	max;

	i = -1;
	max = 0;
	while (++i < fdf->arr->n && fdf->arr->n > 0)
	{
		if (i == 0 || fdf->arr->ps[i]->x > max)
			max = fdf->arr->ps[i]->x;
	}
	return (max);
}

void	move_to_side(t_fdf *fdf, int right)
{
	int		i;

	i = -1;
	if (get_min_x(fdf) > 0 && get_max_x(fdf) < W_WIDTH)
	{
		while (++i < fdf->arr->n)
		{
			if (right == 1)
				fdf->arr->ps[i]->x += 10;
			else
				fdf->arr->ps[i]->x -= 10;
		}
		mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
		fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr, W_WIDTH, W_HEIGHT);
		fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp,
				&fdf->img->llen, &fdf->img->endian);
		//render_fdf(fdf);
		draw_lines(fdf, YELLOW, 0);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win->win_ptr, fdf->img->img_ptr, 0, 0);
	}
}

float	get_min_y(t_fdf *fdf)
{
	int		i;
	float	min;

	i = -1;
	min = 0;
	while (++i < fdf->arr->n && fdf->arr->n > 0)
	{
		if (i == 0 || fdf->arr->ps[i]->y < min)
			min = fdf->arr->ps[i]->y;
	}
	return (min);
}

float	get_max_y(t_fdf *fdf)
{
	int		i;
	float	max;

	i = -1;
	max = 0;
	while (++i < fdf->arr->n && fdf->arr->n > 0)
	{
		if (i == 0 || fdf->arr->ps[i]->y > max)
			max = fdf->arr->ps[i]->y;
	}
	return (max);
}

void	move_to_updo(t_fdf *fdf, int down)
{
	int		i;

	i = -1;
	if (get_min_y(fdf) > 0 && get_max_y(fdf) < W_HEIGHT)
	{
		while (++i < fdf->arr->n)
		{
			if (down == 1)
				fdf->arr->ps[i]->y += 10;
			else
				fdf->arr->ps[i]->y -= 10;
		}
		mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
		fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr, W_WIDTH, W_HEIGHT);
		fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp,
				&fdf->img->llen, &fdf->img->endian);
		//render_fdf(fdf);
		draw_lines(fdf, YELLOW, 0);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win->win_ptr, fdf->img->img_ptr, 0, 0);
	}
}

void	change_color(t_fdf *fdf, int color)
{
	int i;

	i = -1;
	while (++i < fdf->arr->n)
		fdf->arr->ps[i]->color = color;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
		fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr, W_WIDTH, W_HEIGHT);
		fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp,
				&fdf->img->llen, &fdf->img->endian);
		//render_fdf(fdf);
		draw_lines(fdf, YELLOW, color);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win->win_ptr, fdf->img->img_ptr, 0, 0);
}

void	gradient(t_fdf *fdf, int color1, int color2)
{
	int	i;
	int	delta;

	i = -1;
	delta = (color2 - color1) / fdf->arr->nc;
	while (++i < fdf->arr->n)
	{
		if ((i % fdf->arr->nc) == 0 && i > 0)
			color1 += delta;
		fdf->arr->ps[i]->color = color1;
	}
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
	fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr, W_WIDTH, W_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp,
			&fdf->img->llen, &fdf->img->endian);
	//render_fdf(fdf);
	draw_lines(fdf, YELLOW, color1);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win->win_ptr, fdf->img->img_ptr, 0, 0);
}
