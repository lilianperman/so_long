/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:13:02 by liperman          #+#    #+#             */
/*   Updated: 2022/12/01 13:46:07 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_size(t_data *img)
{
	int		i;
	size_t	len;

	i = 0;
	img->cols = (ft_strlen(img->map[0]));
	len = img->cols;
	while (img->map[i])
	{
		if (ft_strlen(img->map[i]) != len)
		{
			ft_printf("%s\n", "Error\nall rows must be equal in size");
			exit (0);
		}
		i++;
	}
	img->rows = i;
}

void	map_cpy(t_data *img, char *map)
{
	char	**map_vector;
	char	**map_cpy;

	map_vector = ft_split(map, '\n');
	map_cpy = ft_split(map, '\n');
	img->map = map_vector;
	img->map_cpy = map_cpy;
}

static char	*read_map(int fd)
{
	static char	*map;
	char		*line;
	int			i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (i == 0)
			{
				ft_printf("Error\nempty map\n");
				exit(0);
			}
			break ;
		}
		map = ft_strjoin(map, line);
		free (line);
		i++;
	}
	close(fd);
	return (map);
}

void	map_termination(char *path_to_map)
{
	int	i;

	i = 0;
	while (path_to_map[i])
		i++;
	if (path_to_map[i - 1] != 'r' || path_to_map[i - 2] != 'e'
		|| path_to_map[i - 3] != 'b' || path_to_map[i - 4] != '.')
	{
		ft_printf("%s\n", "Error\nthe map should end with '.ber'");
		exit (0);
	}
}

void	map_gen(t_data *img, char *path_to_map)
{
	int		fd;
	char	*map;

	map_termination(path_to_map);
	fd = open(path_to_map, O_RDONLY);
	map = read_map(fd);
	map_cpy(img, map);
	map_size(img);
	free(map);
}
