/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:38:50 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/12 11:27:34 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "structs.h"
#include <limits.h>
#include <stdlib.h>

int	size = 10;
int	follow = 0;

int	gen_trgb(int opacity, int red, int green, int blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (0);
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

int	get_opacity(int trgb)
{
	return ((trgb >> 24) & 0XFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0XFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0XFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

t_win	*create_window(int h, int w, char *str)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_win	*wind;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (NULL);
	win_ptr = mlx_new_window(mlx_ptr, w, h, str);
	if (!win_ptr)
		return (NULL);
	wind = (t_win *)malloc(sizeof(t_win));
	if (!wind)
		return (NULL);
	wind->mlx_ptr = mlx_ptr;
	wind->win_ptr = win_ptr;
	wind->h = h;
	wind->w = w;
	return (wind); 
}

t_img	*create_img(int h, int w, t_win *window)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	if (!image)
		return (NULL);
	image->wind = window;
	image->img_ptr = mlx_new_image(window->mlx_ptr, w, h);
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp), &(image->line_len), &(image->endian));
	image->h = h;
	image->w = w;
	return (image);
}

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;
	
	if (x >= 0 && x < img->w && y >= 0 && y < img->h)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_square(t_square square, t_img *img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < square.size && i + square.y < img->h)
	{
		j = 0;
		while (j < square.size && j + square.x < img->w)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

int	exit_tutorial(t_img *img)
{
	if (img)
	{
		if (img->wind)
			free(img->wind);
		free(img);
	}
	exit(EXIT_SUCCESS);
}

int	get_color(int next)
{
	static int	colors[8] = {0xFFFFFF, 0x0000FF, 0x00FF00, 0xFF0000, 0x00FFFF, 0xFF00FF, 0xFFFF00, 0x000000};
	static int	count = 0;
	if (next)
		count = (count + 1) % 8;
	return colors[count];
}

int	read_keys(int key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (key_pressed == 	ESC || !img)
		exit_tutorial(img);
	else if (key_pressed == ENTER)
		draw_square((t_square){0, 0, img->w, 0xFFFFFF}, img);
	else if (key_pressed == FOLLOW)
		follow = !follow;
	else if (key_pressed == COLOR)
		get_color(1);
	else
		return (-1);
	mlx_put_image_to_window(img->wind->mlx_ptr, img->wind->win_ptr, img->img_ptr, 0, 0);
	return (0);
}

int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	int			x;
	int			y;
	t_img		*img;
	t_square	s;

	img = (t_img *)param;
	if (!img)
		return (-1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, get_color(0)};
	draw_square(s, img);
	mlx_put_image_to_window(img->wind->mlx_ptr, img->wind->win_ptr, img->img_ptr, 0, 0);
	(void)button;
	return (0);
}

int	main(void)
{
	t_win	*window;
	t_img	*image;

	window = create_window(450, 400, "New window");
	if (!window)
		return (1);
	image = create_img(300, 300, window);
	if (!image)
		return (-1);
	draw_square((t_square){0, 0, 400, 0x00FF00}, image);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->img_ptr, 0, 0);
	mlx_key_hook(window->win_ptr, read_keys, &image);
	mlx_mouse_hook(window->win_ptr, read_mouse, image);
	mlx_hook(window->win_ptr, 17, 0, exit_tutorial, &window);
	mlx_loop(window->mlx_ptr);
	free(window);
	free(image);
	return (0);
}
