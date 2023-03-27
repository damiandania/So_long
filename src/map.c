/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:35:13 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/20 15:14:56 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	read_map(char *filename, t_game *game)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	game->map = malloc(sizeof(char *) * WIN_HEIGHT);
	if (!game->map)
		return (-1);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (-1);
		game->map[i] = line;
		i++;
	}
	close(fd);
	return (0);
}

// Esta función itera a través de la matriz game->map y comprueba
// si los caracteres en cada posición son válidos (es decir, son '1',
// '0', 'P' o 'E'). Si no lo son, devuelve -1 para indicar que el
// mapa no es válido. También cuenta el número de jugadores y salidas
// en el mapa y verifica que solo, haya uno de cada uno. Si no es así,
// devuelve -1 para indicar que el mapa no es válido.
// Si el mapa es válido, devuelve 0.

int	validate_map(t_game *game)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
						&& game->map[i][j] != 'P' && game->map[i][j] != 'E')
				return (-1);
			if (game->map[i][j] == 'P')
				player_count++;
			if (game->map[i][j] == 'E')
				exit_count++;
		}
	}
	if (player_count != 1 || exit_count != 1)
		return (-1);
	return (0);
}
