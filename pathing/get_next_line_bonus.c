/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:47:26 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 14:59:22 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*printit(char *bigstr, char const *s1, char const *s2)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s1[i])
	{
		bigstr[i] = s1[i];
		i++;
	}
	while (s2[a])
	{
		bigstr[i] = s2[a];
		a++;
		i++;
	}
	bigstr[i] = '\0';
	return (bigstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*bigstr;

	if (!s1)
	{
		s1 = malloc (sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	bigstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (bigstr == NULL)
		return (NULL);
	printit(bigstr, s1, s2);
	free(s1);
	return (bigstr);
}

char	*ft_strchr(const char *s, int c )
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*getstatic(char *thestatic, int fd)
{
	int		count;
	char	*buffer;

	count = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((ft_strchr(thestatic, '\n')) == NULL && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		thestatic = ft_strjoin(thestatic, buffer);
	}
	free(buffer);
	return (thestatic);
}

char	*get_next_line(int fd)
{
	static char	*strstock[1024];
	char		*newstr;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	strstock[fd] = getstatic(strstock[fd], fd);
	if (!strstock[fd])
	{
		free(strstock[fd]);
		return (NULL);
	}
	newstr = creatit(strstock[fd]);
	strstock[fd] = savetheend(strstock[fd]);
	return (newstr);
}
