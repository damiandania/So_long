/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_exit_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:22:10 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/15 21:37:49 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_soft(t_data *data, char *msg)
{
	if (data->map)
		free_map(data->map);
	ft_printf("%s\n", msg);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	exit_hard(t_data *data, char *msg)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	destroy_img(data);
	free(data->mlx_ptr);
	data->win_ptr = NULL;
	exit_soft(data, msg);
	exit (1);
}

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
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
