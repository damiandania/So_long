/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:19:26 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/05 16:49:45 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_draw(t_data *data)
{
	char	*line;
	int	i;
	int	x;
	int	y;

	x = 0;
	line = get_next_line(data->fd);
	while (line != NULL)
	{
		data->map[x] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!data->map[x])
			return (error_check(1));
		y = 0;
		i = 0;
		while (line[i] != '\0')
		{
			data->map[x][y++] = line[i++];
			// printf("%c", data->map[x][y]);
		}
		data->map[x++][y] = '\0';
		free(line);
		line = get_next_line(data->fd);
	}
	data->map[x] = NULL;
	free(line);
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
	return (line_count);
}

void	map_read(char *file_path, t_data *data)
{
	data->line_count = line_counter(file_path);
	data->path = file_path;
	data->map = (char **)malloc(sizeof(char *) * (data->line_count + 1));
	if (!data->map)
		return (error_check(1));
	data->fd = open(file_path, O_RDONLY);
	if (data->fd < 0)
		return (error_check(1));
	else
	{
		map_draw(data);
		close(data->fd);
	}
}
