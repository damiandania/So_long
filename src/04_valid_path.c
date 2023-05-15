/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:08:52 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/15 22:13:27 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_path_next(int i, int j, t_data *data, char **map)
{
	if (j < data->j_counter)
		find_path(i, j + 1, data, map);
	if (j > 0)
		find_path(i, j - 1, data, map);
	if (i < data->i_counter - 1)
		find_path(i + 1, j, data, map);
	if (i > 0)
		find_path(i - 1, j, data, map);
}

void	find_path(int i, int j, t_data *data, char **map)
{
	if (map[i][j] == '2')
		return ;
	else if (map[i][j] == '1')
		return ;
	else if (map[i][j] == 'P')
		map[i][j] = '2';
	else if (map[i][j] == '0')
		map[i][j] = '2';
	else if (map[i][j] == 'C')
	{
		data->c_doubles++;
		map[i][j] = '2';
	}
	else if (map[i][j] == 'E')
	{
		data->e_doubles++;
		map[i][j] = '1';
		return ;
	}
	find_path_next(i, j, data, map);
}

void	free_map2(char **map, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->i_counter)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	valid_path(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	copy_map(data, &map);
	while (i < data->i_counter)
	{
		j = 0;
		while (j < data->j_counter)
		{
			if (map[i][j] == 'P')
			{
				find_path(i, j, data, map);
				break ;
			}
			j++;
		}
		i++;
	}
	free_map2(map, data);
	if (data->c_doubles != data->c_counter)
		exit_soft(data, "No access to collecs\n");
	if (data->e_doubles != 1)
		exit_soft(data, "No access to the exit\n");
}

void	copy_map(t_data *data, char ***map)
{
	int	i;

	i = 0;
	*map = (char **)malloc(data->i_counter * sizeof(char *));
	while (i < data->i_counter)
	{
		(*map)[i] = (char *)malloc((data->j_counter + 1) * sizeof(char));
		ft_memcpy((*map)[i], data->map[i], data->j_counter + 1);
		i++;
	}
}
