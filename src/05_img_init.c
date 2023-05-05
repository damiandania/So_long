#include "../includes/so_long.h"

void	img_init(t_data *data)
{
	data->img.collec = mlx_xpm_file_to_image(data->mlx_ptr, COLLEC_DIR,
			&data->img.width, &data->img.heigth);
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_DIR,
			&data->img.width, &data->img.heigth);
	data->img.player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_DIR,
			&data->img.width, &data->img.heigth);
	data->img.space = mlx_xpm_file_to_image(data->mlx_ptr, SPACE_DIR,
			&data->img.width, &data->img.heigth);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL_DIR,
			&data->img.width, &data->img.heigth);
}

