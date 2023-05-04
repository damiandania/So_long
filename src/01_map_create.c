/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:19:26 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/04 19:17:51 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_draw(t_data *data)
{
	char	*line;

	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;

	line = get_next_line(data->fd);
	while (line != NULL)
	{
		data->map[x] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!data->map[x])
			return (error_check(1));
		while (line[i] != '\0')
		{
			data->map[x][y] = line[i];
			printf("%c", data->map[x][y]);
			y++;
			i++;
		}
		data->map[x][y] = '\0';
		free(line);
		line = get_next_line(data->fd);
		y = 0;
		i = 0;
		x++;
	}
	data->map[x] = NULL;
	printf("2/3, ");
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
	printf("1/3, \n");
	return (line_count);
}

void	map_read(char *file_path, t_data *data)
{
	data->line_count = line_counter(file_path);
	printf("line_ count = %d\n", data->line_count);

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

	printf("3/3, ");

	return ;
}
