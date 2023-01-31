/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:09:42 by liperman          #+#    #+#             */
/*   Updated: 2022/11/07 15:43:22 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_exit( int i, int j, t_data *img)
{
	if (img->map_cpy[i + 1][j] != 'X' && img->map_cpy[i - 1][j] != 'X'
		&& img->map_cpy[i][j + 1] != 'X' && img->map_cpy[i][j - 1] != 'X')
	{
		ft_printf("%s\n", "Error\nno way to exit!");
		exit (0);
	}
}

void	check_cpy(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (img->map_cpy[i])
	{
		while (img->map_cpy[i][j])
		{
			if (img->map_cpy[i][j] == 'C')
			{
				ft_printf("%s\n", "Error\nno way to collect all avocados!");
				exit (0);
			}
			else if (img->map_cpy[i][j] == 'E')
			{
				check_exit(i, j, img);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_infect(int i, int j, t_data *img)
{
	if (img->map_cpy[i][j] && (img->map_cpy[i][j] == '0'
		|| img->map_cpy[i][j] == 'C' || img->map_cpy[i][j] == 'P'))
	{
		img->map_cpy[i][j] = 'X';
		ft_infect(i + 1, j, img);
		ft_infect(i - 1, j, img);
		ft_infect(i, j + 1, img);
		ft_infect(i, j - 1, img);
	}
	else
		return ;
}

void	path_validation(t_data *img)
{
	img->player_row_path = 0;
	img->player_col_path = 0;
	while (img->map_cpy[img->player_row_path])
	{
		while (img->map_cpy[img->player_row_path][img->player_col_path])
		{
			if (img->map_cpy[img->player_row_path][img->player_col_path] == 'P')
				ft_infect(img->player_row_path, img->player_col_path, img);
			img->player_col_path++;
		}
		img->player_col_path = 0;
		img->player_row_path ++;
	}
	check_cpy(img);
}
