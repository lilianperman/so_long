/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:36:53 by liperman          #+#    #+#             */
/*   Updated: 2022/11/30 09:39:46 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	char_validation(char ch, t_data *img)
{
	if (ch != 'C' && ch != '0' && ch != '1' && ch != 'P' && ch != 'E')
	{
		ft_printf("%s\n", "Error\ninvalid map");
		free_map(img);
	}
	if (ch == 'P')
		img->count_player++;
	if (ch == 'E')
		img->count_exit++;
}

void	map_format(t_data *img)
{
	if (img->cols == img->rows)
	{
		ft_printf("%s\n", "Error\nthe map must be a rectangle!");
		exit (0);
	}
}

void	wall_validation(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (img->map[i])
	{
		while (img->map[i][j])
		{
			if (i == 0 || i == (img->rows - 1) || j == 0
				|| j == (img->cols - 1))
			{
				if (img->map[i][j] != '1')
				{
					ft_printf("%s\n", "Error\nmap must be surrounded by walls");
					free_map(img);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_validation(t_data *img)
{
	if (img->count_exit > 1 || img->count_player > 1)
	{
		ft_printf("%s\n", "Error\nwrong number of exits or players!");
		exit (0);
	}
}

void	map_validation(t_data *img)
{
	int		i;
	int		j;
	int		rows;

	i = 0;
	j = 0;
	rows = img->rows;
	img->count_exit = 0;
	img->count_player = 0;
	map_format(img);
	wall_validation(img);
	while (rows > 0)
	{
		while (img->map[i][j])
		{
			char_validation(img->map[i][j], img);
			j++;
		}
		j = 0;
		i++;
		rows--;
	}
	check_validation(img);
}
