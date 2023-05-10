/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:13:18 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/10 20:42:56 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_data *data, int i, int j, int size)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.wall,
			size, i * IMG_SIZE);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.space,
			size, i * IMG_SIZE);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.player,
			size, i * IMG_SIZE);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.exit,
			size, i * IMG_SIZE);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.collec,
			size, i * IMG_SIZE);
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
	mlx_hook(data.win_ptr, 17, LeaveWindowMask,
		&press_exit, &data);
	mlx_loop(data.mlx_ptr);
}

