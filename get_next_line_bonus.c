/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:26:08 by mahmad-j          #+#    #+#             */
/*   Updated: 2021/06/04 23:55:08 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && len--)
		{
			ret[i] = s[start + i];
			i++;
		}
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = 0;
	return (ret);
}

ssize_t	get_next_line_2(ssize_t n, char **line, char **linearr, char **tmp)
{
	ssize_t	ret;

	if (n == 0)
	{
		*line = ft_strdup(*linearr);
		*tmp = ft_strdup(*linearr + ft_strlen(*line) + 1);
		ret = 0;
	}
	else if (n > 0)
	{
		*line = ft_substr(*linearr, 0,
				(ft_strchr(*linearr, '\n') - *linearr));
		*tmp = ft_strdup(*linearr + ft_strlen(*line) + 1);
		ret = 1;
	}
	else
	{
		ft_memdel((void **)linearr);
		return (ret = -1);
	}
	ft_memdel((void **)linearr);
	*linearr = *tmp;
	if (n == 0)
		ft_memdel((void **)linearr);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		ret;
	ssize_t		n;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*linearr[FD_SIZE];

	n = 1;
	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (linearr[fd] == NULL)
		linearr[fd] = ft_strnew(1 * sizeof(char));
	if (!ft_strchr(linearr[fd], '\n'))
		n = read(fd, buff, BUFFER_SIZE);
	while (!ft_strchr(linearr[fd], '\n') && n > 0)
	{
		buff[n] = '\0';
		tmp = ft_strjoin(linearr[fd], buff);
		ft_memdel((void **)&linearr[fd]);
		linearr[fd] = tmp;
		if (!ft_strchr(linearr[fd], '\n'))
			n = read(fd, buff, BUFFER_SIZE);
	}
	ret = get_next_line_2(n, line, (char **)&linearr[fd], &tmp);
	return (ret);
}
