/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:43:32 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/25 14:19:57 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

int	checker(char *argv)
{
	if (check_file(argv) == 0)
	{
		error_handler(2);
		return (0);
	}
	if (valid_map(argv) == 0)
	{
		error_handler(4);
		return (0);
	}
	return (1);
}
