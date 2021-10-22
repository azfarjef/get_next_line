/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:26:08 by mahmad-j          #+#    #+#             */
/*   Updated: 2021/10/20 16:47:20 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line_2(ssize_t n, char **statline, char **tmp)
{
	char	*line;

	line = NULL;
	if (n == 0)
		line = ft_strdup(*statline);
	if (n > 0)
		line = ft_substr(*statline, 0,
				(ft_strchr(*statline, '\n') - *statline + 1));
	*tmp = ft_strdup(*statline + ft_strlen(line));
	ft_memdel((void **)statline);
	*statline = *tmp;
	if (n < 0 || (*line == 0 && n == 0))
		ft_memdel((void **)&line);
	*tmp = ft_strdup("");
	ft_memdel((void **)tmp);
	if (n <= 0)
		ft_memdel((void **)statline);
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t		n;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*statline = NULL;

	n = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (statline == NULL)
		statline = ft_strnew(1 * sizeof(char));
	while (!ft_strchr(statline, '\n') && n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
		{
			ft_memdel((void **)&statline);
			return (NULL);
		}
		buff[n] = '\0';
		tmp = ft_strjoin(statline, buff);
		ft_memdel((void **)&statline);
		statline = tmp;
	}
	return (get_next_line_2(n, (char **)&statline, &tmp));
}
