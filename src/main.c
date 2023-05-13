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
	mlx_loop_hook(data.mlx_ptr, &render, &data);

	printf("\nhola\n");
	return (0);
}
