/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:08:43 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/12 21:13:43 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_HEIGHT	1080
# define W_WIDTH	1920

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

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
char	*rem_line_feed(char *str);
int		check_coma(char *str);
int		hex_atoi(char *str);
void	dim_map(char *argv, t_fdf *fdf);
void	fill_coord_color(t_fdf *fdf, char *str, int k);
void	fill_map_2(char *aux, t_fdf *fdf, int k, int i);
void	fill_map(char *argv, t_fdf *fdf);
int		valid_map(t_fdf fdf);
void	print_map(t_fdf fdf);
t_win	*create_window(int h, int w, char *str);
t_img	*create_image(int h, int w, t_win *window);

#endif
