/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:24:32 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/15 17:25:13 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_data *data, int i, int j, int size)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.wall, size, i * IMG_SIZE);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.space, size, i * IMG_SIZE);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.exit,
			size, i * IMG_SIZE);
}

void	animation_1(t_data *data, int i, int j, int size)
{
	if (data->map[i][j] == 'C' && data->img.timer <= 100)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.collec_1, size, i * IMG_SIZE);
	else if (data->map[i][j] == 'P' && data->img.timer <= 100)
	{
		if (data->direction == 'a')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.player_a1, size, i * IMG_SIZE);
		else if (data->direction == 'w')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.player_w1, size, i * IMG_SIZE);
		else if (data->direction == 'd')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.player_d1, size, i * IMG_SIZE);
		else if (data->direction == 's')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.player_s1, size, i * IMG_SIZE);
		data->img.timer++;
	}
}

void	animation_2(t_data *data, int i, int j, int size)
{
	if (data->map[i][j] == 'C' && data->img.timer > 100)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.collec_2, size, i * IMG_SIZE);
	if (data->map[i][j] == 'P' && data->img.timer > 100)
	{
		if (data->direction == 'a')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.player_a2, size, i * IMG_SIZE);
		else if (data->direction == 'w')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.player_w2, size, i * IMG_SIZE);
		else if (data->direction == 'd')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.player_d2, size, i * IMG_SIZE);
		else if (data->direction == 's')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.player_s2, size, i * IMG_SIZE);
		data->img.timer++;
		if (data->img.timer > 199)
			data->img.timer = 0;
	}
}

int	render(t_data *data)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	while (i < data->i_counter)
	{
		j = 0;
		size = 0;
		while (data->map[i][j] != '\0')
		{
			put_img(data, i, j, size);
			animation_1(data, i, j, size);
			animation_2(data, i, j, size);
			j++;
			size += IMG_SIZE;
		}
		i++;
	}
	return (0);
}

void	img_loop(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, &press_exit, &data);
	mlx_loop(data.mlx_ptr);
}
