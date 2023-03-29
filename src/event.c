#include "../includes/so_long.h"

// cierre de la ventana
int	close_window(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	destroy_data(data);
	return (0);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}
