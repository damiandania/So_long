#include "../includes/so_long.h"

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit (0);
	}
	else if (keysym == A || keysym == S || keysym == W || keysym == D)
	{
		player_move(data, keysym);
	}
	return (0);
}

int	press_exit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	exit (0);
}
