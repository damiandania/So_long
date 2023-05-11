/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:11:39 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/11 17:58:03 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if ((data->map[i][j] != '1') && (data->map[i][j] != 'C') &&
					(data->map[i][j] != 'P') && (data->map[i][j] != '0') &&
					(data->map[i][j] != 'E') && (data->map[i][j] != '\n'))
				safe_exit(data, "map not valid");
			if (data->c_counter < 1)
				safe_exit(data, "collectibles");
			if (data->p_counter != 1)
				safe_exit(data, "player");
			if (data->e_counter != 1)
				safe_exit(data, "exit");
			j++;
		}
		i++;
	}
}

void	check_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->j_counter - 1))
	{
		if ((data->map[0][i] != '1') || (data->map[data->i_counter - 1][i] != '1'))
			safe_exit(data, "walls no valid");
		i++;
	}
	i = 0;
	while (i < (data->i_counter - 1))
	{
		if ((data->map[i][0] != '1') || (data->map[i][data->j_counter - 2] != '1'))
			safe_exit(data, "walls no valid");
		i++;
	}
}

void	check_rectangle(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	data->j_counter = ft_strlen(data->map[i]);
	while (i < (data->i_counter - 1))
	{
		temp = ft_strlen(data->map[i]);
		if (data->j_counter != temp)
			safe_exit(data, "map is not rectangle");
		data->j_counter = temp;
		i++;
	}
}

void	map_check(t_data *data)
{
	check_char(data);
	check_rectangle(data);
	check_walls(data);
}
