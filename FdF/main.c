/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:36:44 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/14 22:43:04 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

void	error_handler(int type)
{
	ft_printf("Error(%d): ", type);
	if (type == 1)
		ft_printf("You must specify 1 (and only 1) argument, the map file.");
	else if (type == 2)
		ft_printf("Your map file is not of type .fdf.");
	else if (type == 3)
		ft_printf("There was an error while reading from the file.");
	else if (type == 4)
		ft_printf("The map indicated is not valid.");
	else
		ft_printf("There was an unexpected error while running the code.");
	ft_printf("\n");
}

int	totalfree(t_fdf *fdf)
{
	mlx_destroy_image(fdf->win->mlx_ptr, fdf->img->img_ptr);
	mlx_destroy_window(fdf->win->mlx_ptr, fdf->win->win_ptr);
	mlx_destroy_display(fdf->win->mlx_ptr);
	free(fdf->win->mlx_ptr);
	exit(0);
}

int	close_fdf(t_fdf *fdf)
{
	totalfree(fdf);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

/*int	mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
{
	if (keycode == ESC)
		close_game(fractal);
	printf("d\n", keycode);
	return (0);
}

int	key*/

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		if (check_file(argv[1]) == 0)
		{
			error_handler(2);
			return (0);
		}
		if (valid_map(argv[1]) == 0)
		{
			error_handler(4);
			return (0);
		}
		fill_map(argv[1], &fdf);
		fdf.win = create_window(W_HEIGHT, W_WIDTH, "FdF");
		if (!(fdf.win))
			return (1);
		fdf.img = create_image(W_HEIGHT, W_WIDTH, fdf.win);
		if (!(fdf.img))
			return (1);
		mlx_put_image_to_window(fdf.win->mlx_ptr, fdf.win->win_ptr, fdf.img->img_ptr, 0, 0);
		mlx_loop(fdf.win->mlx_ptr);
	}
	else
		error_handler(1);
	return (0);
}
