/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:48:42 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/14 21:09:37 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*rem_bl2(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n' && str[i + 1] == '\0')
	{
		new = (char *)malloc((i + 1) * sizeof(char));
		if (!new)
			error_handler(0);
		i = -1;
		while (str[++i] != '\n')
			new[i] = str[i];
		new[i] = '\0';
	}
	return (new);
}

int	valid_map_aux(int *graph, char *aux)
{
	char	***gstr;

	gstr = (char ***)malloc(sizeof(char **) * graph[4]);
	if (!gstr)
		return (-1);
	while (1)
	{
		graph[1] = -1;
		aux = get_next_line(graph[3]);
		if (aux == NULL)
			break ;
		gstr[++graph[0]] = ft_split(rem_bl2(aux), ' ');
		while (gstr[graph[0]][++graph[1]] != 0)
			graph[2]++;
		if (graph[6] == 1 && graph[5] != graph[1])
			return (0);
		else if (graph[6] == 0)
			graph[5] = graph[1];
		graph[6] = 1;
		free(aux);
	}
	free(aux);
	return (1);
}

int	valid_map(char *argv)
{
	char	aux;
	int		*graph;
	int		isvalid;

	graph = (int *)malloc(7 * sizeof(int));
	graph[6] = 0;
	graph[4] = count_l(argv);
	graph[0] = -1;
	graph[3] = open(argv, O_RDONLY);
	isvalid = valid_map_aux(graph, &aux);
	if (isvalid == -1)
		error_handler(0);
	close(graph[3]);
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
		printf("if: %d |max: %d\n", fdf->arr->ps[i]->is_f, \
				fdf->arr->ps[i]->xmax);
		i++;
	}
}
