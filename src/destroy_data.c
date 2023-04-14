/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:15:54 by ddania-c          #+#    #+#             */
/*   Updated: 2023/04/01 16:15:20 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void destroy_data(t_data *data)
{
	if (data != 0)
	{
		if (data->collec != 0)
			mlx_destroy_image(data->mlx_ptr, data->collec);
		if (data->exit != 0)
			mlx_destroy_image(data->mlx_ptr, data->exit);
		if (data->player != 0)
			mlx_destroy_image(data->mlx_ptr, data->player);
		if (data->space != 0)
			mlx_destroy_image(data->mlx_ptr, data->space);
		if (data->wall != 0)
			mlx_destroy_image(data->mlx_ptr, data->wall);
		if (data->win_ptr != 0)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->mlx_ptr != 0)
			mlx_destroy_display(data->mlx_ptr);
		free(data);
	}
	exit (0);
}
