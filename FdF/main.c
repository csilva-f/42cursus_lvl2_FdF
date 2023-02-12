/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:36:44 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/12 20:22:46 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/ft_printf.h"

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
		ft_printf("The map introduced is not valid.");
	else
		ft_printf("There was an unexpected error while running the code.");
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_win	*win;
	t_img	*img;
	t_fdf	fdf;

	if (argc == 2)
	{
		if (check_file(argv[1]) == 0)
		{
			error_handler(2);
			return (0);
		}
		fill_map(argv[1], &fdf);
		if (valid_map(fdf) == 0)
		{
			error_handler(4);
			return (0);
		}
		win = create_window(W_HEIGHT, W_WIDTH, "FdF");
		if (!win)
			return (1);
		img = create_image(W_HEIGHT, W_WIDTH, win);
		if (!img)
			return (1);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
		mlx_loop(win->mlx_ptr);
		return (0);
	}
	error_handler(1);
	return (0);
}
