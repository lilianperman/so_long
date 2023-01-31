/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:43:37 by liperman          #+#    #+#             */
/*   Updated: 2022/09/20 14:40:56 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_free(char *static_var, char *buffer)
{
	char	*temp;

	temp = ft_gnl_join(static_var, buffer);
	free (static_var);
	return (temp);
}

char	*ft_gnl_next(char *static_var)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (static_var[i] && static_var[i] != '\n')
		i++;
	if (!static_var[i])
	{
		free(static_var);
		return (NULL);
	}
	result = ft_gnl_calloc((ft_strlen(static_var) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (static_var[i])
		result[j++] = static_var[i++];
	free (static_var);
	return (result);
}

char	*ft_line(char *static_var)
{
	char	*line;
	int		i;

	i = 0;
	if (!static_var[i])
		return (NULL);
	while (static_var[i] && static_var[i] != '\n')
		i++;
	line = ft_calloc (i + 2, sizeof(char));
	i = 0;
	while (static_var[i] && static_var[i] != '\n')
	{
		line[i] = static_var[i];
		i++;
	}
	if (static_var[i] && static_var[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *static_var)
{
	char	*buffer;
	int		byte_read;

	buffer = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0 && !(ft_gnl_strchr(buffer, '\n')))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		if (!static_var)
		{
			static_var = ft_gnl_calloc(1, 1);
		}
		static_var = ft_gnl_free(static_var, buffer);
	}
	free (buffer);
	return (static_var);
}

char	*get_next_line(int fd)
{
	static char	*static_var;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_var = read_file(fd, static_var);
	if (!static_var)
		return (NULL);
	line = ft_line(static_var);
	static_var = ft_gnl_next(static_var);
	return (line);
}
