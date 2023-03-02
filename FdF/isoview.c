/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoview.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:20:25 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/01 21:54:02 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate_45(t_fdf *fdf)
{
	int		i;
	float	aux_x;
	float	aux_y;

	i = 0;
	while (i < fdf->arr->n)
	{
		printf("i: %d | ", i);
		aux_x = fdf->arr->ps[i]->x;
		aux_y = fdf->arr->ps[i]->y;
		printf("t2 | ");
		fdf->arr->ps[i]->x = (aux_x * cos(45)) - (aux_y * sin(45));
		printf("t3 | ");
		fdf->arr->ps[i]->y = (aux_x * sin(45)) + (aux_y * cos(45));
		printf("t4\n");
		i++;
	}
	printf("teste");
}
