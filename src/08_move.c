/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:11 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/10 20:30:22 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_wall(t_data *data, char key)
{
	if ((key == A && data->map[data->ppi][data->ppj - 1] != '1') ||
			(key == D && data->map[data->ppi][data->ppj + 1] != '1') ||
			(key == W && data->map[data->ppi - 1][data->ppj] != '1') ||
			(key == S && data->map[data->ppi + 1][data->ppj] != '1'))
		return (1);
	else
		return (0);
}

int	check_exit(t_data *data, char key)
{
	if ((key == A && data->map[data->ppi][data->ppj - 1] == 'E') ||
			(key == D && data->map[data->ppi][data->ppj + 1] == 'E') ||
			(key == W && data->map[data->ppi - 1][data->ppj] == 'E') ||
			(key == S && data->map[data->ppi + 1][data->ppj] == 'E'))
	{
		if (data->n_collec == 0)
		{
			ft_printf("\n~ Game completed ~\n");
			ft_printf("~ Total steps: %d ~\n", ++data->move_count);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
			exit (0);
		}
		else
			return (0);
	}
	return (1);
}

void	check_collec(t_data *data)
{
	if (data->map[data->ppi][data->ppj] == 'C')
		data->n_collec--;
}

void	player_move(t_data *data, char key)
{
	if ((check_wall(data, key) == 1) && (check_exit(data, key) == 1))
	{
		data->map[data->ppi][data->ppj] = '0';
		if (key == A)
			data->ppj--;
		else if (key == D)
			data->ppj++;
		else if (key == W)
			data->ppi--;
		else if (key == S)
			data->ppi++;
		check_collec(data);
		data->map[data->ppi][data->ppj] = 'P';
		ft_printf("Step counter: %d\n", ++data->move_count);
	}
}
