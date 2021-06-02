/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:26:08 by mahmad-j          #+#    #+#             */
/*   Updated: 2021/06/02 15:23:58 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*ft_strnew(size_t size)
{
	void	*ptr;
	
	ptr = malloc(size);
	if (ptr = NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len > 0)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}

int	ft_memdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		n;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*statline;
	
	n = 1;
	statline = NULL;
	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (statline == NULL)
		statline = ft_strnew(1 * sizeof(char));
	if (!ft_strchr(statline, '\n'))
		n = read(fd, buff, BUFFER_SIZE);
	while (!ft_strchr(statline, '\n') && n > 0)
	{
		buff[n] = '\0';
		tmp = ft_strjoin(statline, buff);
		ft_memdel((void **)&statline);
		statline = tmp;
		if (!ft_strchr(statline, '\n'))
			n = read(fd, buff, BUFFER_SIZE);
	}
	if (r == 0)
	{
		*line = ft_strdup(statline);
		tmp = ft_strdup(statline + ft_strlen(*line));
	}
	else if (r > 0)
	{
		*line = ft_substr(statline, 0, (ft_strchr(statline, '\n') - statline));
		tmp = ft_strdup(statline + ft_strlen(*line) + 1);
	}
	else
		return (-1);
	ft_memdel((void **)&statline);
	statline = tmp;
	if (r == 0)
	{
		
	}
	

}