/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:04:44 by tpiras            #+#    #+#             */
/*   Updated: 2023/03/29 15:08:10 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#define YES	1
#define	NO	0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include "/Users/tpiras/Desktop/so_long/minilibx_mms/minilibx_opengl_20191021/mlx.h"
# include "/Users/tpiras/Desktop/so_long/minilibx_mms/minilibx_opengl_20191021/mlx_png.h"
# include "/Users/tpiras/Desktop/so_long/so_long/libft/libft.h"

//shield_live
// typedef struct s_shields
// {
// 	void	*shield_00;
// 	void	*shield_01;
// 	void	*shield_02;
// 	void	*shield_03;
// }	t_shields;

//death animation
typedef struct death_animation
{
	int		d_stance;
	int		d_frame;
}	explosion;

//door animation
typedef struct door_animation
{
	int		door_stance;
	int		door_frame;
	int		door_loop;
	void	*door_img;
}	o_door;

//structure with enemies and crews
typedef struct enemy_movement
{
	int		X_x;
	int		X_y;
	int		enemy_loop;
	void	*enemy_img;
}	enemy;

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
	enemy		proiettile;
	explosion	death;
	o_door		door;
	// t_shields	shield;
}	t_vars;

//map checker
int		ft_count(char *s1);
int		checking_edges(t_vars *vars);
int		checking_middles(t_vars *vars);
int		checking_stucture(t_vars *vars);
int		checking_elements(t_vars *vars);
int		ft_control(t_vars *vars);

//graphics of the map
t_vars	start(t_vars *vars, char *path);
int		get_sprite(t_vars *vars);
void	draw_map(t_vars *vars);
void	draw_1_0(t_vars *vars, int x, int y);
void	draw_P_X(t_vars *vars, int x, int y);
void	draw_E_C(t_vars *vars, int x, int y);
// void	draw_shields(t_vars *vars, int x, int y);

//animation functions
int		animation(t_vars *vars);
void	change_image(t_vars *vars);
int		door_animation(t_vars *vars);
void	open_door(t_vars *vars);

//movements
// int		player_w(t_vars *vars);
// int		player_s(t_vars *vars);
// int		player_a(t_vars *vars);
// int		player_d(t_vars *vars);
int		move(int keycode, t_vars *vars);
int		move_w(t_vars *vars);
int		move_s(t_vars *vars);
int		move_d(t_vars *vars);
int		move_a(t_vars *vars);
int		shootings(t_vars *vars);
int		X_move(t_vars *vars);

#endif