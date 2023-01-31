/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:41:19 by liperman          #+#    #+#             */
/*   Updated: 2022/11/23 19:22:45 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*mem;

	if (s1 == NULL)
		s1 = ft_strdup("");
	i = 0;
	j = 0;
	mem = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!mem)
		return (NULL);
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
	free(s1);
	return (mem);
}
