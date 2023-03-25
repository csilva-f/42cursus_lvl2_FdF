/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:08:43 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/25 14:39:39 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define W_HEIGHT	1020
# define W_WIDTH	1980
# define PI		3.141592654

# define MENU_WIDTH 200
# define MENU_COLOR 0x202020

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define ESC 65307
# define ENTER 65293
# define HELP 104 //H
# define Y1 65436 //1
# define R2 65433 //2
# define B3 65435 //3
# define P4 65430 //4
# define G5 65437 //5
# define G6 65432 //6
# define G7 65429 //7
# define G8 65431 //8
# define ISO 105 //I
# define PAR 112 //P
# define RESET 114 //R
# define AU 65362 //arrow up
# define AR 65363 //arrow right
# define AD 65364 //arrow down
# define AL 65361 //arrow left

# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define GREEN 0X00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define PINK 0xFF00FF

typedef struct s_win
{
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
	float	x;
	float	y;
	int		z;
	int		color;
	int		is_f;
	int		xmax;
}		t_p;

typedef struct s_arr
{
	t_p	**ps;
	int	nl;
	int	nc;
	int	n;
	int	zmin;
	int	zmax;
}		t_arr;

typedef struct s_fdf
{
	char	*file;
	void	*mlx_ptr;
	t_win	*win;
	t_img	*img;
	t_arr	*arr;
	float	s;
	float	s_z;
	t_arr	*arr2;
}		t_fdf;

typedef struct s_bres
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
}		t_bres;

int		check_file(char *file_name);
void	error_handler(int type);
int		check_coma(char *str);
int		hex_atoi(char *str);
int		count_l(char *argv);
void	init_fdf(t_fdf *fdf, int i, int j, int k);
char	***dim_map(char *argv, t_fdf *fdf, int nl, int g3);
void	fill_coord_color(t_fdf *fdf, char *str, int k);
char	***rem_bl(char ***gstr, int nl);
void	fill_params(t_fdf *fdf, int *g, char ***gstr, int g2);
void	fill_map_2(t_fdf *fdf, char ***gstr, int *g, int g2);
void	fill_map(char *argv, t_fdf *fdf, int g2);
char	*rem_bl2(char *str);
int		valid_map_aux(int fd, int nw, int f, int res);
int		valid_map(char *argv);
int		checker(char *argv);
void	find_scale(t_fdf *fdf);
void	center_lines(t_fdf *fdf, int i);
void	center_map(t_fdf *fdf);
void	scale_map(t_fdf *fdf);
void	center_map_win_aux(t_fdf *fdf);
void	center_map_win(t_fdf *fdf);
void	print_fdf(t_fdf *fdf);
t_win	*create_window(int h, int w, char *str, void *mlx_ptr);
t_img	*create_image(int h, int w, t_win *window, void *mlx_ptr);
void	create_menu(t_fdf *fdf);
void	init_menu(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
float	ft_abs_float(float c);
void	line_low(t_fdf *fdf, t_p *p0, t_p *p1, int color);
void	line(t_fdf *fdf, t_p *p0, t_p *p1);
void	draw_lines_2(t_fdf *fdf, int color, int n_color);
void	draw_lines(t_fdf *fdf, int color, int n_color);
void	render_fdf(t_fdf *fdf);
void	fdf_setup(t_fdf *fdf);
void	move_to_side(t_fdf *fdf, int right);
void	move_to_updo(t_fdf *fdf, int down);
void	change_color(t_fdf *fdf, int color);
void	gradient(t_fdf *fdf, int color1, int color2);

#endif
