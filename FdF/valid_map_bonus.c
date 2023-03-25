/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:48:42 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/25 14:21:52 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	check_file(char *file_name)
{
	int	i;
	int	c;

	i = ft_strlen(file_name) - 1;
	c = -1;
	while (i > 0 && file_name[i] != '.')
		i--;
	if (file_name[i] == '.')
	{
		i++;
		c = ft_strncmp(&file_name[i], "fdf", 3);
	}
	if (c == 0)
		return (1);
	return (0);
}

char	*rem_bl2(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] != '\n')
		return (str);
	else if (len == 1 && str[len - 1] == '\n')
		return (NULL);
	else
	{
		i = -1;
		while (str[++i] != '\0')
		{
			if (str[i] == '\n')
				str[i] = ' ';
		}
	}
	return (str);
}

int	count_col(char *str)
{
	int	i;
	int	f;
	int	c;

	i = -1;
	f = 0;
	c = 0;
	while (str[++i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && f == 0)
		{
			c++;
			f = 1;
		}
		if (str[i] == ' ' || str[i] == '\n')
			f = 0;
	}
	return (c);
}

int	valid_map_aux(int fd, int nw, int f, int res)
{
	char	*a;
	int		i;

	while (1)
	{
		i = -1;
		a = get_next_line(fd);
		if (a == NULL)
			break ;
		if (f == 0)
		{
			nw = count_col(a);
			f = 1;
		}
		if (nw != count_col(a) && f == 1)
		{
			res = 0;
			break ;
		}
		free(a);
	}
	free(a);
	return (res);
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
	isvalid = valid_map_aux(graph[2], 0, 0, 1);
	close(graph[2]);
	free(graph);
	return (isvalid);
}

/*int	count_bt_sp(char *str, int w, int res, int c)
{
	int	*n;

	n = (int *)malloc(3 * sizeof(int));
	n[0] = -1;
	n[1] = 0;
	n[2] = 0;
	while (str[++n[0] + 1] != '\0' && ft_strlen(str) > 1)
	{
		if (str[n[0]] != ' ' && str[n[0]] != '\n' && n[2] == 0)
		{
			c++;
			n[1] = 1;
			n[2] = 1;
		}
		else if (str[n[0]] == ' ' && str[n[0] + 1] == ' ' && n[1] == 1 && c < w)
		{
			printf("teste1\n");
			res = 0;
			break ;
		}
		else if (str[n[0]] == ' ')
			n[2] = 0;
	}
	free(n);
	return (res);
}*/
