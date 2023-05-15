/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_win_img_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:09:04 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/15 22:12:49 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	win_width(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
		i++;
	return (i - 1);
}

void	win_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit_hard(data, "Trying to open the window\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, IMG_SIZE * win_width(data),
			IMG_SIZE * data->i_counter, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		exit_hard(data, "Trying to open the window\n");
	}
	img_init(data);
}

void	img_init(t_data *data)
{
	img_init_player(data);
	data->img.collec_1 = mlx_xpm_file_to_image(data->mlx_ptr, COLLEC_1,
			&data->img.width, &data->img.heigth);
	data->img.collec_2 = mlx_xpm_file_to_image(data->mlx_ptr, COLLEC_2,
			&data->img.width, &data->img.heigth);
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_DIR,
			&data->img.width, &data->img.heigth);
	data->img.space = mlx_xpm_file_to_image(data->mlx_ptr, SPACE_DIR,
			&data->img.width, &data->img.heigth);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL_DIR,
			&data->img.width, &data->img.heigth);
}

void	img_init_player(t_data *data)
{
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
}
