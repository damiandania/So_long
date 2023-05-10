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

	printf("---map_check: \n");
	map_check(&data);
	printf("OK\n");

	printf("----win_init: ");
	win_init(&data);
	printf("OK\n");

	printf("-----img_init: ");
	img_init(&data);
	printf("OK\n");

	printf("------render: ");
	render(&data);
	printf("OK\n");

	printf("-------loop: OK\n");
	img_loop(data);

	return (0);
}
