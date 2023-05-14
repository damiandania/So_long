/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:13:21 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/13 18:50:31 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_init(t_data *data)
{
	data->img.collec = mlx_xpm_file_to_image(data->mlx_ptr, COLLEC_DIR,
			&data->img.width, &data->img.heigth);
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_DIR,
			&data->img.width, &data->img.heigth);
	data->img.player_a1 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_A1,
			&data->img.width, &data->img.heigth);
	data->img.player_a2 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_A2,
			&data->img.width, &data->img.heigth);
	data->img.player_w1 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_W1,
			&data->img.width, &data->img.heigth);
	data->img.player_w2 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_W2,
			&data->img.width, &data->img.heigth);
	data->img.player_d1 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_D1,
			&data->img.width, &data->img.heigth);
	data->img.player_d2 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_D2,
			&data->img.width, &data->img.heigth);
	data->img.player_s1 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_S1,
			&data->img.width, &data->img.heigth);
	data->img.player_s2 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_S2,
			&data->img.width, &data->img.heigth);
	data->img.space = mlx_xpm_file_to_image(data->mlx_ptr, SPACE_DIR,
			&data->img.width, &data->img.heigth);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL_DIR,
			&data->img.width, &data->img.heigth);
}
