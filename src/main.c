#include "../includes/so_long.h"

// verificador de BE o LE
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		// BE
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		//LE
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

// dibujar los rectangulos
int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

// dibujar el fondo
int	render_background(t_img *img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_HEIGHT)
	{
		y = 0;
		while (y < WIN_WIDTH)
			img_pix_put(img, y++, x, color);
		x++;
	}
	return (0);
}

// cierre de la ventana
int	close_window()
{
	exit (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

// dibujar pixales
int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	render_rect(&data->img, (t_rect){WIN_WIDTH - 100, WIN_HEIGHT - 100,
			100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

// main
int main(void)
{
	t_data	data;

	// creacion de la ventana
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	// dibujar imagen
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
					&data.img.line_len, &data.img.endian);

	// configurar el hook
	mlx_loop_hook(data.mlx_ptr, &render, &data);

	// cierre de la ventana
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, NULL);

	// crear el loop
	mlx_loop(data.mlx_ptr);

	// para salir del loop si no hay ventana
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
