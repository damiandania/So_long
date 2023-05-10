#include "../includes/so_long.h"

int	check_wall(t_data *data, char key)
{
	if ((key == A && data->map[data->ppi][data->ppj - 1] != '1') ||
			(key == D && data->map[data->ppi][data->ppj + 1] != '1') ||
			(key == W && data->map[data->ppi - 1][data->ppj] != '1') ||
			(key == S && data->map[data->ppi + 1][data->ppj] != '1'))
		return (1);
	else
		return	(0);
}

int	check_exit(t_data *data, char key)
{
	if ((key == A && data->map[data->ppi][data->ppj - 1] == 'E') ||
			(key == D && data->map[data->ppi][data->ppj + 1] == 'E') ||
			(key == W && data->map[data->ppi - 1][data->ppj] == 'E') ||
			(key == S && data->map[data->ppi + 1][data->ppj] == 'E'))
	{
		if (data->n_collec == 0)
		{
			printf("\n~ Game completed ~\n");
			printf("~ Total steps: %d ~\n", ++data->move_count);
			exit (0);
		}
		else
			return (0);
	}
	return (1);
}

void	check_collec(t_data *data, char key)
{
	if ((key == A && data->map[data->ppi][data->ppj - 1] == 'C') ||
			(key == D && data->map[data->ppi][data->ppj + 1] == 'C') ||
			(key == W && data->map[data->ppi - 1][data->ppj] == 'C') ||
			(key == S && data->map[data->ppi + 1][data->ppj] == 'C'))
		data->n_collec--;
}

void	player_move(t_data *data, char key)
{
	if ((check_wall(data, key) == 1) && (check_exit(data, key) == 1))
	{
		check_collec(data, key);
		data->map[data->ppi][data->ppj] = '0';
		if (key == A)
			data->ppj--;
		else if (key == D)
			data->ppj++;
		else if (key == W)
			data->ppi--;
		else if (key == S)
			data->ppi++;
		data->map[data->ppi][data->ppj] = 'P';
		printf("Step counter: %d\n", ++data->move_count);
	}
}

