/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:23:44 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/14 13:45:04 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nNumber of arguments\n", 2);
		exit (1);
	}
}

void	check_ext_format(char *path)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (open(path, O_DIRECTORY) >= 0)
	{
		fd = open(path, O_DIRECTORY);
		close(fd);
		ft_putstr_fd("Error\nThe extention is not a file\n", 2);
		exit (1);
	}
	fd = open(path, O_RDONLY);
	if ((path[len - 3] == 'b' && path[len - 2] == 'e'
			&& path[len - 1] == 'r'
			&& path[len - 4] == '.') && fd >= 0)
	{
		file_empty(fd);
		close(fd);
	}
	else
	{
		close(fd);
		ft_putstr_fd("Error\nThe extention format not valid\n", 2);
		exit (1);
	}
}

void	file_empty(int fd)
{
	char	buffer[1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == 0)
	{
		close(fd);
		ft_putstr_fd("Error\nEmpty file\n", 2);
		exit (1);
	}
	close(fd);
}

void	check_ext(char *path, int argc)
{
	check_argc(argc);
	check_ext_format(path);
}
