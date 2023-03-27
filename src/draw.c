int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
