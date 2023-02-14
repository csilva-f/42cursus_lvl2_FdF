/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:48:42 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/14 03:32:25 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map(char *argv, t_fdf *fdf)
{
	int		*g;
	char	***gstr;

	gstr = dim_map(argv, fdf);
	g = (int *)malloc(3 * sizeof(int));
	g[0] = -1;
	g[2] = 0;
	while (++g[0] < fdf->arr->nl)
	{
		g[1] = -1;
		while (++g[1] < fdf->arr->nc)
		{
			gstr = rem_bl(gstr, fdf->arr->nl);
			fdf->arr->ps[g[2]] = (t_p *)malloc(sizeof(t_p));
			if (!(fdf->arr->ps[g[2]]))
				error_handler(0);
			fdf->arr->ps[g[2]]->x = g[1];
			fdf->arr->ps[g[2]]->y = g[0];
			if (check_coma(gstr[g[0]][g[1]]) == 1)
				fill_coord_color(fdf, gstr[g[0]][g[1]], g[2]);
			else
				fill_params(fdf, g, gstr);
			g[2]++;
		}
	}
	print_fdf(fdf);
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
			return (-1);
		gstr[++graph[0]] = ft_split(aux, ' ');
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
