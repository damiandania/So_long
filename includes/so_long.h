/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:03:35 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/15 21:35:53 by ddania-c         ###   ########.fr       */
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

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

// definir tamaño
# define IMG_SIZE 40

// controles
# define A 97
# define D 100
# define S 115
# define W 119

// definir colores
# define RED 0xFF0000 // color rojo
# define WHITE 0xFFFF00 // color verde

// definir direccion de imagenes
# define WALL_DIR "textures/wall.xpm"
# define PLAYER_A1 "textures/player_a1.xpm"
# define PLAYER_A2 "textures/player_a2.xpm"
# define PLAYER_W1 "textures/player_w1.xpm"
# define PLAYER_W2 "textures/player_w2.xpm"
# define PLAYER_D1 "textures/player_d1.xpm"
# define PLAYER_D2 "textures/player_d2.xpm"
# define PLAYER_S1 "textures/player_s1.xpm"
# define PLAYER_S2 "textures/player_s2.xpm"
# define SPACE_DIR "textures/space.xpm"
# define EXIT_DIR "textures/exit.xpm"
# define COLLEC_1 "textures/collec_1.xpm"
# define COLLEC_2 "textures/collec_2.xpm"

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		heigth;
	int		line_len;
	void	*collec_1;
	void	*collec_2;
	void	*exit;
	void	*player_a1;
	void	*player_a2;
	void	*player_w1;
	void	*player_w2;
	void	*player_d1;
	void	*player_d2;
	void	*player_s1;
	void	*player_s2;
	void	*space;
	void	*wall;
	int		timer;
}		t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		move_count;
	char	**map;
	int		fd;
	int		i_counter;
	int		j_counter;
	char	*path;
	int		ppi;
	int		ppj;
	int		allow_exit;
	int		c_counter;
	int		p_counter;
	int		e_counter;
	char	direction;
	int		c_doubles;
	int		e_doubles;
	t_img	img;
}		t_data;

//////////////		00_CHECK_EXT		//////////////
void	check_ext(char *path, int argc);
void	check_argc(int argc);
void	check_ext_format(char *path);
void	file_empty(int fd);

//////////////		01_MAP_READ			//////////////
int		line_counter(t_data *data, char *file_path);
void	read_map(char *file_path, t_data *data);
void	map_to_ptr(t_data *data);

//////////////		02_DATA_INIT		//////////////
void	data_init(t_data *data);
void	player_init(t_data *data);

//////////////		03_MAP_CHECK		//////////////
void	check_char(t_data *data);
void	check_walls(t_data *data);
void	check_rectangle(t_data *data);
void	map_check(t_data *data);

//////////////		04_VALID_PATH		//////////////
void	valid_path(t_data *data);
void	find_path(int i, int j, t_data *data, char **map);
void	copy_map(t_data *data, char ***map);
void	find_path_next(int i, int j, t_data *data, char **map);

//////////////		05_IMG_INIT			//////////////
void	img_init_player(t_data *data);
void	img_init(t_data *data);
int		win_width(t_data *data);
void	win_init(t_data *data);

//////////////		06_RENDER			//////////////
void	put_img(t_data *data, int i, int j, int size);
void	animation_1(t_data *data, int i, int j, int size);
void	animation_2(t_data *data, int i, int j, int size);
int		render(t_data *data);
void	img_loop(t_data data);

//////////////		07_EVENTS			//////////////
int		press_exit(t_data *data);
int		keypress(int keysym, t_data *data);

//////////////		08_MOVE				//////////////
int		check_wall(t_data *data, char key);
int		check_exit(t_data *data, char key);
void	player_go(t_data *data, char key);
void	check_collec(t_data *data);
void	player_move(t_data *data, char key);

//////////////		09_ERROR			//////////////
void	exit_soft(t_data *data, char *msg);
void	exit_hard(t_data *data, char *msg);
void	exit_ok(t_data *data, char *msg);
void	destroy_img(t_data *data);
void	free_map(char **map);

#endif
