/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:08:21 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/11 17:31:24 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	data_init(t_data *data)
{
	data->img.heigth = IMG_SIZE;
	data->img.width = IMG_SIZE;
	data->move_count = 0;
	data->ppi = 0;
	data->ppj = 0;
	data->c_counter = 0;
	data->p_counter = 0;
	data->e_counter = 0;
	data->direction = 'd';
	data->img.timer = 0;
	player_init(data);
}

void	player_init(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->ppi = i;
				data->ppj = j;
			}
			if (data->map[i][j] == 'C')
				data->c_counter++;
			if (data->map[i][j] == 'E')
				data->e_counter++;
			if (data->map[i][j++] == 'P')
				data->p_counter++;
		}
		i++;
	}
}
