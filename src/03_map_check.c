/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:11:39 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/10 20:53:37 by ddania-c         ###   ########.fr       */
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
		while (data->map[i][j])
		{
			if ((data->map[i][j] != '1') && (data->map[i][j] != 'C') &&
				(data->map[i][j] != 'P') && (data->map[i][j] != '0') &&
				(data->map[i][j] != 'E') && (data->map[i][j] != '\n'))
			{
				error_check(1);
				// destroy();
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	check_rectangle(t_data *data)
{
	int	i;
	int	temp;
	int	len;

	i = 0;
	len = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		printf("Len = %d\n", len);
		temp = ft_strlen(data->map[i]);
		if (len != temp)
		{
			error_check(2);
			// destroy();
			exit (0);
		}
		len = temp;
		i++;
	}
}

void	map_check(t_data *data)
{
	check_char(data);
	check_rectangle(data);
}
