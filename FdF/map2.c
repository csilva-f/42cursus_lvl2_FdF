/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:43:34 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/18 13:32:43 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***dim_map(char *argv, t_fdf *fdf, int nl)
{
	char	*aux;
	char	***gstr;
	int		*graph;

	graph = (int *)malloc(4 * sizeof(int));
	gstr = (char ***)malloc(sizeof(char **) * nl);
	if (!gstr)
		error_handler(0);
	graph[0] = -1;
	graph[3] = open(argv, O_RDONLY);
	while (1)
	{
		graph[1] = -1;
		aux = get_next_line(graph[3]);
		if (aux == NULL)
			break ;
		gstr[++graph[0]] = ft_split(aux, ' ');
		while (gstr[graph[0]][++graph[1]] != 0)
			graph[2]++;
		printf("%s\n", aux);
		free(aux);
	}
	free(aux);
	init_fdf(fdf, ++graph[0], (graph[2] / graph[0]), graph[2]);
	close(graph[3]);
	free(graph);
	return (gstr);
}

void	fill_coord_color(t_fdf *fdf, char *str, int k)
{
	int		i;
	char	**s;

	i = 0;
	s = ft_split((const char *)str, ',');
	while (s[i] != 0)
		i++;
	if (i != 2)
		error_handler(0);
	else
	{
		fdf->arr->ps[k]->z = ft_atoi((const char *)s[0]);
		fdf->arr->ps[k]->color = hex_atoi(s[1]);
		fdf->arr->ps[k]->is_f = 0;
		fdf->arr->ps[k]->xmax = 0;
	}
	i = -1;
	while (s[++i] != 0)
		free(s[i]);
	free(s);
}

char	***rem_bl(char ***gstr, int nl)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < nl)
	{
		j = -1;
		while (gstr[i][++j] != 0)
		{
			if (gstr[i][j + 1] == 0)
			{
				k = ft_strlen(gstr[i][j]) - 1;
				if (gstr[i][j][k] == '\n')
					gstr[i][j] = ft_split(gstr[i][j], '\n')[0];
			}
		}
	}
	return (gstr);
}

void	fill_params(t_fdf *fdf, int *g, char ***gstr)
{
	fdf->arr->ps[g[2]]->z = ft_atoi(gstr[g[0]][g[1]]);
	fdf->arr->ps[g[2]]->color = 0;
	if (g[1] == (fdf->arr->nc - 1))
	{
		fdf->arr->ps[g[2]]->is_f = 1;
		fdf->arr->ps[g[2]]->xmax = g[1];
	}
	else
	{
		fdf->arr->ps[g[2]]->is_f = 0;
		fdf->arr->ps[g[2]]->xmax = 0;
	}
}

void	fill_map(char *argv, t_fdf *fdf)
{
	int		*g;
	char	***gstr;

	gstr = dim_map(argv, fdf, count_l(argv));
	printf("n: %d |nl: %d| nc: %d\n", fdf->arr->n, fdf->arr->nl, fdf->arr->nc);
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
	g[0] = -1;
	while (++g[0] < fdf->arr->nl)
	{
		g[1] = -1;
		while (gstr[g[0]][++g[1]] != 0)
			free(gstr[g[0]][g[1]]);
		free(gstr[g[0]]);
	}
	free(gstr);
	free(g);
	print_fdf(fdf);
}
