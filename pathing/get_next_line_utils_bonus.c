/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:02:18 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 14:57:24 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*creatit(char *str)
{
	int		i;
	char	*newone;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	newone = malloc(sizeof(char) * (i + 2));
	if (!newone)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		newone[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		newone[i] = '\n';
		i++;
	}
	newone[i] = '\0';
	return (newone);
}

int	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_2(char *s1, char *s2)
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
	free(s2);
	free(s1);
	return (bigstr);
}

char	*savetheend(char *str)
{
	char	*newstr;
	int		i;
	int		a;

	a = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i])
	{
		newstr = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
		if (!newstr)
			return (NULL);
		i++;
		a = -1;
		while (str[i])
			newstr[++a] = str[i++];
		newstr[++a] = '\0';
		free(str);
		return (newstr);
	}
	free(str);
	return (NULL);
}
