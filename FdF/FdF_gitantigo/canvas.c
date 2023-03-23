/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:37:51 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/23 02:31:57 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	*create_window(int h, int w, char *str, void *mlx_ptr)
{
	void	*win_ptr;
	t_win	*wind;

	if (!mlx_ptr)
		return (NULL);
	win_ptr = mlx_new_window(mlx_ptr, w, h, str);
	wind = (t_win *)malloc(sizeof(t_win));
	if (!win_ptr || !wind)
		return (NULL);
	wind->win_ptr = win_ptr;
	wind->h = h;
	wind->w = w;
	return (wind);
}

t_img	*create_image(int h, int w, t_win *window, void *mlx_ptr)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->wind = window;
	img->img_ptr = mlx_new_image(mlx_ptr, w, h);
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->llen), \
			&(img->endian));
	img->h = h;
	img->w = w;
	return (img);
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->img->addr + (y * fdf->img->llen + x * (fdf->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	fdf_setup(t_fdf *fdf)
{
	int	i;

	i = -1;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
	fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr, W_WIDTH, W_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp,
			&fdf->img->llen, &fdf->img->endian);
	//while (++i < fdf->arr->n)
	//	my_mlx_pixel_put(fdf, fdf->arr->ps[i]->x, fdf->arr->ps[i]->y, 0xFF0000);
	draw_lines(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win->win_ptr, \
			fdf->img->img_ptr, 0, 0);
}
