#include "../includes/so_long.h"


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		(error_check(0));
		return (0);
	}
	// if (check_extension(argv[1]) == FAILURE)
	// 	error_msg(ERRBER, &data);
	map_read(argv[1], &data);
	//map_init(&data);

	// // map_check(&data);
	// // player_init(&data);
	printf("main 0\n");

	win_init(&data);
	printf("main 1\n");
	img_init(&data);
	printf("main 2\n");
	// render(&data);
	printf("main 3\n");
	// img_loop(data);
	// img_destroy(data);
	// free(data.mlx_ptr);
	// if (data.map.map)
	// 	ft_free(data.map.map);
	// }
	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop(data.mlx_ptr);

	printf("main 4\n");

	return (0);
}
