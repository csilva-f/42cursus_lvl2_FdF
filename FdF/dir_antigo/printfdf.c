/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:27:29 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/21 10:27:38 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_fdf(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->arr->n)
	{
		printf("i: %d |x: %f  |y: %f |z: %d |", i, fdf->arr->ps[i]->x, \
				fdf->arr->ps[i]->y, fdf->arr->ps[i]->z);
		printf("if: %d |max: %d |color: %i\n", fdf->arr->ps[i]->is_f, \
				fdf->arr->ps[i]->xmax, fdf->arr->ps[i]->color);
		i++;
	}
}
