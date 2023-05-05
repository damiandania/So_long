#include "../includes/so_long.h"

// int	check_next_move(t_data *data, char key)
// {

// }

// void	player_swap(t_data *data)
// {
// 	int temp_i;
// 	int	temp_j;

// }

void	player_move(t_data *data, char key)
{
	// if (check_next_move(data, key) == 1)

	data->map[data->ppi][data->ppj] = '0';
	if (key == A)
		data->ppj--;
	else if (key == D)
		data->ppj++;
	else if (key == W)
		data->ppi--;
	else if (key == S)
		data->ppi++;
	// player_swap(&data);
	data->map[data->ppi][data->ppj] = 'P';
}

