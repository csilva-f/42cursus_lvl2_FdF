/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:58:06 by csilva-f          #+#    #+#             */
/*   Updated: 2023/02/12 11:27:44 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <limits.h>

# define ESC 53
# define ENTER 36
# define FOLLOW 3
# define COLOR 8
# define UP 126
# define DOWN 125
# define RAND_COLOR 35

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
	int		line_len;
}		t_img;

typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}		t_square;

#endif
