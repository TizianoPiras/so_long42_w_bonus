/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:00 by tpiras            #+#    #+#             */
/*   Updated: 2023/04/06 13:30:55 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	if (!vars->map)
		return ;
	while (vars->map[++y] != NULL)
	{
		x = -1;
		while (vars->map[y][++x] != '\0')
		{
			if (vars->map[y][x] == '1' || vars->map[y][x] == '0')
				draw_1_0(vars, x, y);
			else if (vars->map[y][x] == 'P' || vars->map[y][x] == 'X')
				draw_p_x(vars, x, y);
			else if (vars->map[y][x] == 'C' || vars->map[y][x] == 'E')
				draw_e_c(vars, x, y);
		}
		display_moves(vars);
	}
}

void	draw_1_0(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->perimeter, x * 64, y * 64);
	}
	else if (vars->map[y][x] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
	}
}

void	draw_p_x(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->player, x * 64, y * 64);
		vars->player_y = y;
		vars->player_x = x;
	}
	if (vars->map[y][x] == 'X')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->proiettile.enemy_img, x * 64, y * 64);
		vars->proiettile.x_y = y;
		vars->proiettile.x_x = x;
	}
}

void	draw_e_c(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->crew_1, x * 64, y * 64);
	}
	if (vars->map[y][x] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		if (vars->collectable > 0)
			mlx_put_image_to_window
				(vars->mlx, vars->win, vars->perimeter, x * 64, y * 64);
		if (vars->collectable == 0)
			mlx_put_image_to_window
				(vars->mlx, vars->win, vars->door.door_img, x * 64, y * 64);
	}
}

void	display_moves(t_vars *vars)
{
	char	*s_moves;
	char	*c_left;

	s_moves = ft_itoa(vars->moves);
	c_left = ft_itoa(vars->collectable);
	mlx_string_put(vars->mlx, vars->win, vars->width / 2 -250, vars->height -44,
		0x0000FF00, "MOVES: ");
	mlx_string_put(vars->mlx, vars->win, vars->width / 2 -190, vars->height -44,
		0x0000FF00, s_moves);
	mlx_string_put(vars->mlx, vars->win, vars->width / 2 -130, vars->height -44,
		0x0000FF00, "COLLECTABLE LEFT: ");
	mlx_string_put(vars->mlx, vars->win, vars->width / 2 + 40, vars->height -44,
		0x0000FF00, c_left);
	free(s_moves);
	free(c_left);
}
