/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:51:43 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/13 19:49:28 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	check_ext(argv[1], argc);
	read_map(argv[1], &data);
	data_init(&data);
	map_check(&data);
	win_init(&data);
	img_init(&data);
	render(&data);
	img_loop(data);
}
