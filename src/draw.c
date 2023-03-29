int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

// dibujar pixeles
// int	render(t_data *data)
// {
// 	if (data.win_ptr == NULL)
// 		return (1);
// 	render_background(&data.img, WHITE_PIXEL);
// 	render_rect(&data.img, (t_rect){WIN_WIDTH - 100, WIN_HEIGHT - 100,
// 			100, 100, GREEN_PIXEL});
// 	render_rect(&data.img, (t_rect){0, 0, 100, 100, RED_PIXEL});

// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);

// 	return (0);
// }

