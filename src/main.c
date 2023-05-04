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
	printf("-map_read: ");
	map_read(argv[1], &data);
	printf("OK\n");

	printf("--data_init: ");
	data_init(&data);
	printf("OK\n");

	// // map_check(&data);
	// // player_init(&data);
	// printf("--- map_read: OK\n");

	printf("---win_init: ");
	win_init(&data);
	printf("OK\n");

	printf("----img_init: ");
	img_init(&data);
	printf("OK\n");

	printf("-----render: ");
	render(&data);
	printf("OK\n");

	// img_loop(data);
	// img_destroy(data);
	// free(data.mlx_ptr);
	// if (data.map.map)
	// 	ft_free(data.map.map);
	// }
	// mlx_loop_hook(data.mlx_ptr, &render_img, &data);
	printf("------loop: ");
	mlx_loop(data.mlx_ptr);
	printf("OK\n");

	return (0);
}
