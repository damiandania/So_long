#include "../includes/so_long.h"

void	put_img(t_data *data, int i, int j, int size)
{
	printf("test\n");

	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.wall,
			size, i * IMG_SIZE);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.space,
			size, i * IMG_SIZE);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.player,
			size, i * IMG_SIZE);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.exit,
			size, i * IMG_SIZE);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.collec,
			size, i * IMG_SIZE);

	printf("1/2, \n");
}

void	render(t_data *data)
{
	int		i;
	int		j;
	int		size;


	i = 0;

	printf("init: \n");
	while (i < data->line_count)
	{
		j = 0;
		size = 0;
		while (data->map[i][j] != '\0')
		{
			put_img(data, i, j, size);
			j++;
			size += IMG_SIZE;
		}
		i++;
	}
	printf("2/2, \n");
}
