/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:22:10 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/11 17:00:05 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	safe_exit(t_data *data, char *msg)
{
	if (data->map)
		data_free(data->map);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	destroy_img(t_data data)
{
	mlx_destroy_image(data.mlx_ptr, data.img.wall);
	mlx_destroy_image(data.mlx_ptr, data.img.exit);
	mlx_destroy_image(data.mlx_ptr, data.img.player);
	mlx_destroy_image(data.mlx_ptr, data.img.collec);
	mlx_destroy_image(data.mlx_ptr, data.img.space);
	mlx_destroy_display(data.mlx_ptr);
}

void	data_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return ;
}

