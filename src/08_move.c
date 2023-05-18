/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:11 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/18 13:20:04 by ddania-c         ###   ########.fr       */
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
		if (data->c_counter == 0)
		{
			exit_ok(data, "Game finished\n");
			return (0);
		}
		else
			return (0);
	}
	return (1);
}

void	player_go(t_data *data, char key)
{
	data->map[data->ppi][data->ppj] = '0';
	if (key == A)
	{
		data->ppj--;
		data->direction = 'a';
	}
	else if (key == D)
	{
		data->ppj++;
		data->direction = 'd';
	}
	else if (key == W)
	{
		data->ppi--;
		data->direction = 'w';
	}
	else if (key == S)
	{
		data->ppi++;
		data->direction = 's';
	}
	check_collec(data);
	data->map[data->ppi][data->ppj] = 'P';
}

void	check_collec(t_data *data)
{
	if (data->map[data->ppi][data->ppj] == 'C')
		data->c_counter--;
}

void	player_move(t_data *data, char key)
{
	if (system("clear") != 0)
		exit_hard(data, "cleaning the screen\n");
	ft_printf("Steps counter: %d\n", ++data->move_count);
	if ((check_wall(data, key) == 1) && (check_exit(data, key) == 1))
		player_go(data, key);
}
