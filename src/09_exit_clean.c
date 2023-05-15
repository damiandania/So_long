/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_exit_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:22:10 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/14 13:50:15 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_ok(t_data *data, char *msg)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	destroy_img(data);
	free(data->mlx_ptr);
	ft_printf("%s\n", msg);
	if (data->map)
		free_map(data->map);
	data->win_ptr = NULL;
	exit (0);
}

void	exit_fail(t_data *data, char *msg)
{
	if (data->mlx_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr != NULL)
		destroy_img(data);
	free(data->mlx_ptr);
	if (data->map)
		free_map(data->map);
	data->win_ptr = NULL;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit (1);
}

void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.wall);
	mlx_destroy_image(data->mlx_ptr, data->img.exit);
	mlx_destroy_image(data->mlx_ptr, data->img.player_a1);
	mlx_destroy_image(data->mlx_ptr, data->img.player_a2);
	mlx_destroy_image(data->mlx_ptr, data->img.player_w1);
	mlx_destroy_image(data->mlx_ptr, data->img.player_w2);
	mlx_destroy_image(data->mlx_ptr, data->img.player_d1);
	mlx_destroy_image(data->mlx_ptr, data->img.player_d2);
	mlx_destroy_image(data->mlx_ptr, data->img.player_s1);
	mlx_destroy_image(data->mlx_ptr, data->img.player_s2);
	mlx_destroy_image(data->mlx_ptr, data->img.collec_1);
	mlx_destroy_image(data->mlx_ptr, data->img.collec_2);
	mlx_destroy_image(data->mlx_ptr, data->img.space);
	mlx_destroy_display(data->mlx_ptr);
}

void	free_map(char **map)
{
	size_t	i;

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
