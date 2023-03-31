/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:04:44 by tpiras            #+#    #+#             */
/*   Updated: 2023/03/31 15:02:20 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define YES 1
# define NO 0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include "../mlx/mlx_openGL/mlx.h"
# include "../mlx/mlx_openGL/mlx_png.h"
# include "./libft/libft.h"

//death animation
typedef struct death_animation
{
	int		d_stance;
	int		d_frame;
}	t_explosion;

//door animation
typedef struct door_animation
{
	int		door_stance;
	int		door_frame;
	int		door_loop;
	void	*door_img;
}	t_door;

//structure with enemies and crews
typedef struct enemy_movement
{
	int		x_x;
	int		x_y;
	int		enemy_loop;
	void	*enemy_img;
}	t_enemy;

//structure with all elements
typedef struct s_vars
{
	int			lives;
	void		*crew_1;
	void		*crew_2;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		*s;
	int			fd;
	char		*pd;
	int			i;
	char		**map;
	int			map_x;
	int			map_y;
	void		*perimeter;
	void		*bg;
	int			collectable;
	void		*exit;
	void		*player;
	int			player_loop;
	int			death_loop;
	int			player_x;
	int			player_y;
	int			flag;
	int			x;
	int			y;
	int			loop_on;
	int			moves;
	t_enemy		proiettile;
	t_explosion	death;
	t_door		door;
}	t_vars;

//map checker
int		ft_count(char *s1);
int		checking_edges(t_vars *vars);
int		checking_middles(t_vars *vars);
int		checking_stucture(t_vars *vars);
int		checking_elements(t_vars *vars);
int		ft_control(t_vars *vars);
void	ft_putstr(char *s);
void	cleaner(t_vars *vars);

//graphics of the map
t_vars	start(t_vars *vars, char *path);
void	start_vars(t_vars *vars);
int		get_sprite(t_vars *vars);
void	draw_map(t_vars *vars);
void	draw_1_0(t_vars *vars, int x, int y);
void	draw_p_x(t_vars *vars, int x, int y);
void	draw_e_c(t_vars *vars, int x, int y);
void	display_moves(t_vars *vars);
int		key_close(int keycode, t_vars *vars);

//animation functions
int		animation(t_vars *vars);
void	change_image(t_vars *vars);
int		door_animation(t_vars *vars);
void	open_door(t_vars *vars);

//movements
int		move(int keycode, t_vars *vars);
int		move_w(t_vars *vars);
int		move_s(t_vars *vars);
int		move_d(t_vars *vars);
int		move_a(t_vars *vars);
int		shootings(t_vars *vars);
int		x_move(t_vars *vars);

#endif