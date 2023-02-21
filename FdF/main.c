/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:36:44 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/21 19:17:22 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
	int	i;

	i = -1;
	while (++i < fdf->arr->n)
		free(fdf->arr->ps[i]);
	free(fdf->arr->ps);
	free(fdf->arr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	exit(0);
}

int	close_fdf(t_fdf *fdf)
{
	totalfree(fdf);
	exit(1);
	//exit(EXIT_SUCCESS);
	//return (EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		close_fdf(fdf);
	return (0);
}

int	close_win_x(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win->win_ptr);
	close_fdf(fdf);
	//exit (1);
	return (0);
}

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
		printf("2\n");
		center_map_win(&fdf);
		fdf.mlx_ptr = mlx_init();
		fdf.win = create_window(W_HEIGHT, W_WIDTH, "FdF", fdf.mlx_ptr);
		if (!(fdf.win))
			return (1);
		fdf.img = create_image(W_HEIGHT, W_WIDTH, fdf.win, fdf.mlx_ptr);
		if (!(fdf.img))
			return (1);
		fdf_setup(&fdf);
		mlx_key_hook(fdf.win->win_ptr, key_hook, &fdf);
		mlx_hook(fdf.win->win_ptr, 17, 1L << 17, close_win_x, &fdf);
		mlx_loop(fdf.mlx_ptr);
	}
	else
		error_handler(1);
	return (0);
}
