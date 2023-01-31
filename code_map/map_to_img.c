/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:04:01 by liperman          #+#    #+#             */
/*   Updated: 2022/12/01 16:22:52 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_walkable(char ch, int position_row, int position_col, t_data *img)
{
	if (ch == 'P')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->floor,
			position_col * DIMENSION, position_row * DIMENSION);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player,
			position_col * DIMENSION, position_row * DIMENSION);
		img->player_col = img->position_col;
		img->player_row = img->position_row;
	}
	else if (ch == '0')
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->floor, position_col * DIMENSION, position_row * DIMENSION);
	else if (ch == 'C')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->floor,
			position_col * DIMENSION, position_row * DIMENSION);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->collectable,
			position_col * DIMENSION, position_row * DIMENSION);
		img->count_collectable++;
	}
}

void	print_map(char ch, int position_row, int position_col, t_data *img)
{
	int	dimension;

	dimension = DIMENSION;
	img->wall = mlx_xpm_file_to_image(img->mlx, WALL, &dimension, &dimension);
	img->floor = mlx_xpm_file_to_image(img->mlx, FLOOR, &dimension, &dimension);
	img->player = mlx_xpm_file_to_image(img->mlx,
			PLAYER, &dimension, &dimension);
	img->collectable = mlx_xpm_file_to_image(img->mlx,
			COLLECTABLE, &dimension, &dimension);
	img->exit = mlx_xpm_file_to_image(img->mlx, EXIT, &dimension, &dimension);
	if (ch == 'E')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->floor,
			position_col * DIMENSION, position_row * DIMENSION);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit,
			position_col * DIMENSION, position_row * DIMENSION);
		img->exit_col = img->position_col;
		img->exit_row = img->position_row;
	}
	else if (ch == '1')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->wall,
			position_col * DIMENSION, position_row * DIMENSION);
	else if (ch == 'P' || ch == '0' || ch == 'C')
		print_walkable(ch, position_row, position_col, img);
}

void	start_map(t_data	*img)
{
	int	rows;

	img->position_row = 0;
	img->position_col = 0;
	rows = img->rows;
	img->count_collectable = 0;
	while (rows > 0)
	{
		while (img->map[img->position_row][img->position_col] != '\0')
		{
			print_map(img->map[img->position_row][img->position_col],
				img->position_row, img->position_col, img);
			img->position_col++;
		}
	img->position_col = 0;
	img->position_row++;
	rows--;
	}
}
