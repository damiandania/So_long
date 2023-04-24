/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:19:26 by ddania-c          #+#    #+#             */
/*   Updated: 2023/04/24 20:55:15 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_draw(int i, int x, int y, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[x] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[x])
			return (error_check(1));
		while (line[i] != '\0')
		{
			data->map.map[x][y] = line[i];
			printf("%c", data->map.map[x][y]); //quitar al final
			y++;
			i++;
		}
		data->map.map[x][y] = '\0';
		free(line);
		line = get_next_line(data->map.fd);
		y = 0;
		i = 0;
		x++;
	}
	data->map.map = NULL;
	printf("map_read 2/3 \n");
}

int	line_counter(char *file_path)
{
	int	fd;
	int		line_count;
	char	*line;

	line_count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		(error_check(1));
		return (0);
	}
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	printf("map_read 1/3 \n");
	return (line_count);
}

void	map_read(char *file_path, t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	data->map.line_count = line_counter(file_path);
	data->map.path = file_path;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof (char *));
	if (data->map.map == 0)
		return (error_check(1));
	data->map.fd = open(file_path, O_RDONLY);
	if (data->map.fd < 0)
		return (error_check(1));
	else
	{
		map_draw(i, x, y, data);
		close(data->map.fd);
	}

	printf("El numero de lineas es: %d\n", data->map.line_count); //quitar al final
	printf("map_read 3/3 \n");
	return ;
}
