/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:48:42 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/18 12:34:59 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*rem_bl2(char *str)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] != '\n')
		return (str);
	else if (len == 1 && str[len - 1] == '\n')
		return (NULL);
	else
	{
		new = (char *)malloc(len * sizeof(char));
		if (!new)
			error_handler(0);
		i = -1;
		while (str[++i] != '\n')
			new[i] = str[i];
		new[i] = '\0';
	}
	return (new);
}

int	valid_map_aux(int *graph)
{
	char	***gstr;
	char	*aux;

	gstr = (char ***)malloc(sizeof(char **) * graph[3]);
	if (!gstr)
		return (-1);
	while (1)
	{
		graph[1] = 0;
		aux = get_next_line(graph[2]);
		if (aux == NULL)
			break ;
		gstr[++graph[0]] = ft_split(rem_bl2(aux), ' ');
		while (gstr[graph[0]][graph[1]] != 0)
			graph[1]++;
		if (graph[5] == 1 && graph[4] != graph[1])
			return (0);
		else if (graph[5] == 0)
			graph[4] = graph[1];
		graph[5] = 1;
		free(aux);
	}
	free(aux);
	graph[0] = -1;
	while (++graph[0] < (graph[3] - 1))
	{
		graph[1] = -1;
		while (gstr[graph[0]][++graph[1]] != 0)
			free(gstr[graph[0]][graph[1]]);
		free(gstr[graph[0]]);
	}
	free(gstr);
	return (1);
}

int	valid_map(char *argv)
{
	int		*graph;
	int		isvalid;

	graph = (int *)malloc(6 * sizeof(int));
	graph[5] = 0;
	graph[3] = count_l(argv);
	graph[0] = -1;
	graph[2] = open(argv, O_RDONLY);
	isvalid = valid_map_aux(graph);
	if (isvalid == -1)
		error_handler(0);
	close(graph[2]);
	free(graph);
	return (isvalid);
}

void	print_fdf(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->arr->n)
	{
		printf("i: %d |x: %d  |y: %d |z: %d |", i, fdf->arr->ps[i]->x, \
				fdf->arr->ps[i]->y, fdf->arr->ps[i]->z);
		printf("if: %d |max: %d |color: %i\n", fdf->arr->ps[i]->is_f, \
				fdf->arr->ps[i]->xmax, fdf->arr->ps[i]->color);
		i++;
	}
}
