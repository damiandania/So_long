#include "../includes/so_long.h"

void error_check(int id)
{
	if (id == 0)
		ft_printf("error: argument not valid\n");
	if (id == 1)
		ft_printf("error: map not valid\n");
	if (id == 2)
		ft_printf("error: map is not rentangle\n");
	if (id == 3)
		ft_printf("error: %d\n", id);
	if (id == 4)
		ft_printf("error: %d\n", id);
	if (id == 5)
		ft_printf("error: %d\n", id);
	if (id == 6)
		ft_printf("error: %d\n", id);
	if (id == 7)
		ft_printf("error: %d\n", id);
	if (id == 8)
		ft_printf("error: %d\n", id);
}

void	destroy_img(t_data data)
{
	mlx_destroy_image(data.mlx_ptr, data.img.wall);
	mlx_destroy_image(data.mlx_ptr, data.img.exit);
	mlx_destroy_image(data.mlx_ptr, data.img.player);
	mlx_destroy_image(data.mlx_ptr, data.img.collec);
	mlx_destroy_image(data.mlx_ptr, data.img.space);
	mlx_destroy_display(data.mlx_ptr);
}
