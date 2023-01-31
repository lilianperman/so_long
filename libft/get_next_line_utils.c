/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:11:58 by liperman          #+#    #+#             */
/*   Updated: 2022/09/20 14:31:27 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_join(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*mem;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	mem = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i] != '\0')
	{
		mem[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		mem[i] = s2[j];
		i++;
		j++;
	}
	mem[i] = '\0';
	return (mem);
}

void	*ft_gnl_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = (void *)malloc(count * size);
	if (!pointer)
		return (NULL);
	ft_gnl_bzero(pointer, count * size);
	return (pointer);
}

void	ft_gnl_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_gnl_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i <= ft_gnl_strlen(str))
	{
		if (str[i] == (char) c)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
