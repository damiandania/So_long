/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_win_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:09:04 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/13 18:34:07 by ddania-c         ###   ########.fr       */
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
		return (exit_fail(data, "opening window"));
	data->win_ptr = mlx_new_window(data->mlx_ptr, IMG_SIZE * win_width(data),
			IMG_SIZE * data->i_counter, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (exit_fail(data, "opening window"));
	}
}

