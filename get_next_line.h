/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:26:14 by mahmad-j          #+#    #+#             */
/*   Updated: 2021/06/02 23:04:59 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_memdel(void **ptr);
void	get_next_line_2(ssize_t n, char **line, char **statline, char **tmp);
void	init(ssize_t *n, int fd, char **statline, char **tmp, char buff[][BUFFER_SIZE + 1]);
int		get_next_line(int fd, char **line);

#endif