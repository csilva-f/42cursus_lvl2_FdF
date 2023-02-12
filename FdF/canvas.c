/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:37:51 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/12 12:41:45 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	*create_window(int h, int w, char *str)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_win	*wind;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (NULL);
	win_ptr = mlx_new_window(mlx_ptr, w, h, str);
	wind = (t_win *)malloc(sizeof(t_win));
	if (!win_ptr || !wind)
		return (NULL);
	wind->mlx_ptr = mlx_ptr;
	wind->win_ptr = win_ptr;
	wind->h = h;
	wind->w = w;
	return (wind);
}

t_img	*create_image(int h, int w, t_win *window)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->wind = window;
	img->img_ptr = mlx_new_image(window->mlx_ptr, w, h);
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->llen), \
			&(img->endian));
	img->h = h;
	img->w = w;
	return (img);
}
