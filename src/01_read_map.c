/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:19:26 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/13 18:33:45 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_to_ptr(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	line = get_next_line(data->fd);
	while (line != NULL)
	{
		data->map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!data->map[i])
			exit_fail(data, "map not valid\n");
		j = 0;
		while (line[j] != '\0')
		{
			data->map[i][j] = line[j];
			j++;
		}
		data->map[i++][j] = '\0';
		free(line);
		line = get_next_line(data->fd);
	}
	data->map[i] = NULL;
	free(line);
}

int	line_counter(t_data *data, char *file_path)
{
	int		fd;
	int		line_count;
	char	*line;

	line_count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		(exit_fail(data, "map not valid\n"));
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

void	read_map(char *file_path, t_data *data)
{
	data->i_counter = line_counter(data, file_path);
	data->path = file_path;
	data->map = (char **)malloc(sizeof(char *) * (data->i_counter + 1));
	if (!data->map)
		exit_fail(data, "map not valid\n");
	data->fd = open(file_path, O_RDONLY);
	if (data->fd < 0)
		exit_fail(data, "map not valid\n");
	else
		map_to_ptr(data);
	close(data->fd);
}
