/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:51:43 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/14 13:13:51 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	check_ext(argv[1], argc);
	printf("check_ext\n");

	read_map(argv[1], &data);
	printf("read_map\n");

	data_init(&data);
	printf("data_init\n");

	map_check(&data);
	printf("map_check\n");

	win_init(&data);
	printf("win_init\n");

	img_init(&data);
	printf("img_init\n");

	render(&data);
	printf("render\n");

	img_loop(data);
	printf("img_loop\n");
}
