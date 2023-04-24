/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:17:00 by ddania-c          #+#    #+#             */
/*   Updated: 2023/04/24 21:25:35 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void	img_render(t_data *data, int width, int x, int y)
{
	if (data->map.map[x][y] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.player, width, x * IMG_SIZE);
	printf("llego aqui 1");
}

void	render(t_data *data)
{
	printf("llego aqui 1");

	int	x;
	int	y;
	int	width;

	if (data->win_ptr == NULL)
		return (error_check(7));
	x = 0;
	y = 0;
	width = 0;
	while (data->map.map[x])
	{
		while (data->map.map[x][y] && data->map.map[x][y] != '\0')
		{
			img_render(data, width, x, y);
			width += IMG_SIZE;
			y++;
		}
		y = 0;
		width = 0;
		x++;
	}
}
