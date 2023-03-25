/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:45:58 by csilva-f          #+#    #+#             */
/*   Updated: 2023/03/25 16:46:02 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_findchr(char *s, char c);
char	*ft_strjoinfree(char *s1, char *s2);
char	*ft_substrfree(char *s, unsigned int start, size_t len, int f);
char	*ft_getl(char *pocket, ssize_t	*n);
char	*ft_fillpocket(char *pocket, ssize_t *n);

#endif
