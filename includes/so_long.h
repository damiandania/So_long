/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:03:35 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/22 18:30:04 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../libft/libft.h" // biblioteca libft
# include "../minilibx-linux/mlx.h" // biblioteca minilibx
# include <fcntl.h> // para open()
# include <stdlib.h> // para malloc() y free()
# include <stdio.h> // para perror()
# include <unistd.h> // para write() y close()
# include <X11/keysym.h> // para el teclado
# include <X11/X.h> // para el raton

# define TILE_SIZE 20 // tamaño de los azulejos
# define WIN_WIDTH 800// ancho de la ventana
# define WIN_HEIGHT 600 // altura de la ventana

# define RED_PIXEL 0xFF0000 // color rojo
# define GREEN_PIXEL 0xFFFF00 // color verde
# define WHITE_PIXEL 0xFFFFFF // color blanco

# define MLX_ERROR 1 // identificador de error

typedef struct s_point
{
	int x;
	int y;
}			t_point;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

// typedef struct s_image
// {
// 	void	*img_ptr;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_image;

// typedef struct	s_game
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	int		width;
// 	int		height;
// 	int		moves;
// 	t_image	texture_wall;
// 	t_image	texture_ground;
// 	t_image	texture_exit;
// 	t_image	texture_player;
// 	t_point	player_pos;
// 	t_point	exit_pos;
// 	char	**map;
// }			t_game;

// int		read_map(char *filename, t_game *game);
// int		validate_map(t_game *game);
// void	init_game(t_game *game);
// void	draw_game(t_game *game);
// int		handle_keypress(int keycode, t_data *data);
// void	move_player(t_game *game, int x, int y);
// void	destroy_game(t_game *game);
// void	exit_game(t_game *game);

#endif

