/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:08:43 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/14 22:43:20 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_HEIGHT	1080
# define W_WIDTH	1920

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define ESC 53
# define ENTER 36
# define HELP 4
# define COLOR 8

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		h;
	int		w;
}		t_win;

typedef struct s_img
{
	t_win	*wind;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		llen;
}		t_img;

typedef struct s_p
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	is_f;
	int	xmax;
}		t_p;

typedef struct s_arr
{
	t_p	**ps;
	int	nl;
	int	nc;
	int	n;
}		t_arr;

typedef struct s_fdf
{
	t_win	*win;
	t_img	*img;
	t_arr	*arr;
}		t_fdf;

int		check_file(char *file_name);
void	error_handler(int type);
int		check_coma(char *str);
int		hex_atoi(char *str);
int		count_l(char *argv);
void	init_fdf(t_fdf *fdf, int i, int j, int k);
char	***dim_map(char *argv, t_fdf *fdf, int nl);
void	fill_coord_color(t_fdf *fdf, char *str, int k);
char	***rem_bl(char ***gstr, int nl);
void	print_fdf(t_fdf *fdf);
void	fill_params(t_fdf *fdf, int *g, char ***gstr);
void	fill_map(char *argv, t_fdf *fdf);
char	*rem_bl2(char *str);
int		valid_map_aux(int *graph, char *aux);
int		valid_map(char *argv);
void	print_map(t_fdf fdf);
t_win	*create_window(int h, int w, char *str);
t_img	*create_image(int h, int w, t_win *window);

#endif
