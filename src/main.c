#include "../includes/so_long.h"

int main(void /*int ac, char *av[]*/)
{
	t_data	data;

	// inicializamos data
	// data = (t_data *)malloc(sizeof(t_data));
	// if (data == 0)
	// 	destroy_data(data);
	// data->collec = 0;
	// data->exit = 0;
	// data->img = 0;
	// data->mlx_ptr = 0;
	// data->player = 0;
	// data->space = 0;
	// data->wall = 0;
	// data->win_ptr = 0;

	// data = data_init(av[1]);
	win_init(&data);

	// cargar las texturas
	render_textures(&data);

	return (0);
}
