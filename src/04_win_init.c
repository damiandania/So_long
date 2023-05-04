/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_win_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:09:04 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/04 15:24:36 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// cierre de la ventana con el boton X
// int	close_window(int keycode, t_data *data)
// {
// 	(void)keycode;
// 	(void)data;
// 	data_destroy(data);
// 	return (0);
// }

// cierre de la ventana con la tecla Esc
int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void	win_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (error_check(5));
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (error_check(5));
	}
	// Cierre de la ventana
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &keypress, &data);
	// mlx_hook(data->win_ptr, 17, 0, &close_window, NULL);
	printf("1/1, ");
}

