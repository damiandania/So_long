#include "../includes/so_long.h"

void	img_load(t_data *data, t_img *img, char *path)
{
	printf("holaaaaaa");
	int	width;
	int	heigth;

	*img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &heigth);
	if (img == 0)
		return (error_check(8));
	(*img)->width = width;
	(*img)->heigth = heigth;
}

void	img_init(t_data *data)
{
	// // Creacion del puntero de la imagen
	// data->img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	// if (data->img == NULL)
	// 	return (error_check(6));

	img_load(data, &data->img.collec, COLLEC_DIR);
	img_load(data, &data->img.exit, EXIT_DIR);
	img_load(data, &data->img.player, PLAYER_DIR);
	img_load(data, &data->img.space, SPACE_DIR);
	img_load(data, &data->img.wall, WALL_DIR);
	printf("holaaaaaa");
}

