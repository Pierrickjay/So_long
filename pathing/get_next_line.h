/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:48:21 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 15:13:43 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "../ft_printf/libftprintf.h"

char	*creatit(char *str);
char	*savetheend(char *str);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
						/*Change for so_long*/
char	**ft_mapped(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
int		ft_check_map(char **str);
int		check_rectangle(char **str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_2(char *s1, char *s2);
char	*printit(char *bigstr, char const *s1, char const *s2);

#endif
