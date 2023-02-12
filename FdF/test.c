/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:07:56 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/12 21:13:19 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_fdf fdf)
{
	int	i;

	i = 0;
	while (i < fdf.arr->n)
	{
		printf("x:%d y:%d z:%d c:%d is_f:%d max:%d\n", fdf.arr->ps[i]->x, fdf.arr->ps[i]->y,
				fdf.arr->ps[i]->z, fdf.arr->ps[i]->color, fdf.arr->ps[i]->is_f, fdf.arr->ps[i]->xmax);
		i++;
	}
}
