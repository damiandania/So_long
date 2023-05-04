/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:03:35 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/04 19:23:14 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h" // biblioteca libft
# include "../minilibx-linux/mlx.h" // biblioteca minilibx
# include <fcntl.h> // para open()
# include <stdio.h> // printf
# include <stdlib.h> // para malloc() y free()
# include <unistd.h> // para write() y close()
# include <X11/keysym.h> // para el teclado
# include <X11/X.h> // para el raton
# include "get_next_line.h" // gnl

// definir tamaños
# define IMG_SIZE 20 // tamaño de las imagenes
# define WIN_WIDTH 800// ancho de la ventana
# define WIN_HEIGHT 600 // altura de la ventana

// controles
# define A 97
# define D 100
# define S 115
# define W 119

// definir colores
# define RED_PIXEL 0xFF0000 // color rojo
# define GREEN_PIXEL 0xFFFF00 // color verde
# define WHITE_PIXEL 0xFFFFFF // color blanco

// definir direccion de imagenes
# define WALL_DIR "textures/wall.xpm"
# define PLAYER_DIR "textures/player.xpm"
# define SPACE_DIR "textures/space.xpm"
# define EXIT_DIR "textures/exit.xpm"
# define COLLEC_DIR "textures/collec.xpm"

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		heigth;
	int		line_len;
	void	*collec;
	void	*exit;
	void	*player;
	void	*space;
	void	*wall;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		move_count;
	t_img	img;
	char	**map;
	int		fd;
	int		line_count;
	char	*path;
}	t_data;


// 01_MAP_READ
int		line_counter(char *file_path);
void	map_read(char *file_path, t_data *data);

// 02_DATA_INIT
void	data_init(t_data *data);

// 03_MAP_CHECK


// 04_PLAYER_INIT


// 05_WIN_INIT
void	win_init(t_data *data);

// 06_IMG_INIT
void	img_init(t_data *data);

// 07_RENDER
void	render(t_data *data);

// 08_IMG_LOOP


// 09_DATA_DESTROY
void error_check(int id);


// events
int		close_window();
int		keypress(int keysym, t_data *data);

#endif

