#include "../includes/so_long.h"

void	win_init(t_data *data)
{
	// Creacion del puntero de la ventana
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == 0)
		destroy_data(data);
	// Abrir la ventana
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
	if (data->win_ptr == 0)
		destroy_data(data);
	// Creacion del puntero de la imagen
	data->img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	// if (data->img != 0)
	// 	destroy_data(data);

	// Cierre de la ventana
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &keypress, &data);
	mlx_hook(data->win_ptr, 17, 0, &close_window, NULL);

	// crear el loop
	mlx_loop(data->mlx_ptr);
}
