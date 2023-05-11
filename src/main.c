#include "../includes/so_long.h"


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("argument not valid .ber file", 2);
		return (2);
	}
	// if (check_extension(argv[1]) == FAILURE)
	// 	error_msg(ERRBER, &data);
	map_read(argv[1], &data);
	data_init(&data);
	map_check(&data);
	win_init(&data);
	img_init(&data);
	render(&data);
	img_loop(data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	free(data.mlx_ptr);
	if (data.map)
		data_free(data.map);
	return (0);
}
