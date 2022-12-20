/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:06:04 by pjay              #+#    #+#             */
/*   Updated: 2022/12/13 15:11:47 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**freemalloc(char **s, size_t index)
{
	while ((int)index >= 0)
	{
		free(s[index]);
		index--;
	}
	free(s);
	return (NULL);
}

int	countword(const char *str, char c)
{
	int	index;
	int	countword;
	int	check;

	index = 0;
	countword = 0;
	check = 0;
	while (str[index])
	{
		if (str[index] != c && check == 0)
		{
			countword++;
			check = 1;
		}
		else if (str[index] == c)
			check = 0;
		index++;
	}
	return (countword);
}

char	*dup_word(const char *str, char c, int index)
{
	char	*split;
	int		i;
	size_t	j;
	int		count;

	count = 0;
	i = index;
	j = 0;
	while (i >= 0 && str[i] != c && str[i])
	{
		i--;
		count++;
	}
	i++;
	split = malloc(sizeof(char) * (count + 1));
	if (split == NULL)
		return (NULL);
	while (str[i] != c && str[i])
	{
		split[j] = str[i];
		i++;
		j++;
	}
	split[j] = '\0';
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		a;
	size_t		index;

	index = 0;
	split = malloc(sizeof(char *) * (countword(s, c) + 1));
	if (split == NULL || s == NULL)
		return (NULL);
	a = 0;
	while ((int)index < ft_strlen(s))
	{
		if (s[index] != c)
		{
			while (s[index] != c && s[index])
				index++;
			split[a] = dup_word(s, c, index - 1);
			if (split[a] == NULL)
				return (freemalloc(split, a));
			a++;
		}
		else
			index++;
	}
	split[a] = NULL;
	return (split);
}
