/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:19:46 by ddania-c          #+#    #+#             */
/*   Updated: 2023/04/12 18:22:26 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_img(t_data *data, t_img **img, char *path)
{
	int	width;
	int	heigth;

	*img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &heigth);
	if (img == 0)
		destroy_data(0);
	(*img)->width = width;
	(*img)->heigth = heigth;
}

void	render_textures(t_data *data)
{
	load_img(data, &data->collec, COLLEC_DIR);
	load_img(data, &data->exit, EXIT_DIR);
	load_img(data, &data->player, PLAYER_DIR);
	load_img(data, &data->space, SPACE_DIR);
	load_img(data, &data->wall, WALL_DIR);
}
