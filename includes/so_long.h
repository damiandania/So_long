/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:03:35 by ddania-c          #+#    #+#             */
/*   Updated: 2023/04/12 18:22:24 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../libft/libft.h" // biblioteca libft
# include "../minilibx-linux/mlx.h" // biblioteca minilibx
# include <fcntl.h> // para open()
# include <stdlib.h> // para malloc() y free()
# include <unistd.h> // para write() y close()
# include <X11/keysym.h> // para el teclado
# include <X11/X.h> // para el raton

// definir tamaños
# define TILE_SIZE 20 // tamaño de los azulejos
# define WIN_WIDTH 800// ancho de la ventana
# define WIN_HEIGHT 600 // altura de la ventana

// definir colores
# define RED_PIXEL 0xFF0000 // color rojo
# define GREEN_PIXEL 0xFFFF00 // color verde
# define WHITE_PIXEL 0xFFFFFF // color blanco

// definir direccion de imagenes
# define WALL_DIR "../textures/wall.xpm"
# define PLAYER_DIR "../textures/player.xpm"
# define SPACE_DIR "../textures/space.xpm"
# define EXIT_DIR "../textures/exit.xpm"
# define COLLEC_DIR "../textures/collec.xpm"

# define MLX_ERROR 1 // identificador de error

typedef struct s_img
{
	void	*mlx_img;
	char	*DIR;
	int		width;
	int		heigth;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_img	*collec;
	t_img	*exit;
	t_img	*player;
	t_img	*space;
	t_img	*wall;
}	t_data;

int main();

// win_init
void	win_init(t_data *data);

// events
int		close_window();
int		keypress(int keysym, t_data *data);

// limpiat memoria
void destroy_data(t_data *data);

// renderizar las imagenes
void	render_textures(t_data *data);


// typedef struct s_rect
// {
// 	int	x;
// 	int	y;
// 	int width;
// 	int height;
// 	int color;
// }	t_rect;

// int		read_map(char *filename, t_game *game);
// int		validate_map(t_game *game);
// void	init_game(t_game *game);
// void	draw_game(t_game *game);
// int		handle_keypress(int keycode, t_data *data);
// void	move_player(t_game *game, int x, int y);
// void	destroy_game(t_game *game);
// void	exit_game(t_game *game);

#endif

