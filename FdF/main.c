/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:36:44 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/25 09:39:38 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	totalfree(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i < fdf->arr->n)
		free(fdf->arr->ps[i]);
	free(fdf->arr->ps);
	free(fdf->arr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
	free(fdf->img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win->win_ptr);
	free(fdf->win);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	exit(0);
}

int	close_fdf(t_fdf *fdf)
{
	totalfree(fdf);
	exit(1);
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
	close_fdf(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		if (checker(argv[1]) == 0)
			return (0);
		fill_map(argv[1], &fdf, -1);
		fdf.file = argv[1];
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

//print_fdf(&fdf);
