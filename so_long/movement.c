/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:41:56 by tpiras            #+#    #+#             */
/*   Updated: 2023/03/29 14:23:58 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 126)
		move_w(vars);
	if (keycode == 1 || keycode == 125)
		move_s(vars);
	if (keycode == 0 || keycode == 123)
		move_a(vars);
	if (keycode == 2 || keycode == 124)
		move_d(vars);
	return (1);
}

int	move_w(t_vars *vars)
{
	vars->player_y -= 1;
	if (vars->map[vars->player_y][vars->player_x] == '1')
		return (0);
	if (vars->map[vars->player_y][vars->player_x] == 'X')
	{   
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->lives--;
	}
	if (vars->map[vars->player_y][vars->player_x] == 'C')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->collectable -= 1;
	}
	if (vars->map[vars->player_y][vars->player_x] == '0')
		vars->map[vars->player_y][vars->player_x] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'E')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->loop_on = NO;
	}
	vars->map[vars->player_y + 1][vars->player_x] = '0';
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}

int	move_s(t_vars *vars)
{
	vars->player_y += 1;
	if (vars->map[vars->player_y][vars->player_x] == '1')
		return (0);
	if (vars->map[vars->player_y][vars->player_x] == 'X')
	{   
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->lives--;
	}
	if (vars->map[vars->player_y][vars->player_x] == 'C')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->collectable -= 1;
	}
	if (vars->map[vars->player_y][vars->player_x] == '0')
		vars->map[vars->player_y][vars->player_x] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'E')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->loop_on = NO;
	}
	vars->map[vars->player_y - 1][vars->player_x] = '0';
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}

int	move_a(t_vars *vars)
{
	vars->player_x -= 1;
	if (vars->map[vars->player_y][vars->player_x] == '1')
		return (0);
	if (vars->map[vars->player_y][vars->player_x] == 'X')
	{   
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->lives--;
	}
	if (vars->map[vars->player_y][vars->player_x] == 'C')
	{   
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->collectable -= 1;
	}
	if (vars->map[vars->player_y][vars->player_x] == '0')
		vars->map[vars->player_y][vars->player_x] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'E')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->loop_on = NO;
	}
	vars->map[vars->player_y][vars->player_x + 1] = '0';
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}

int	move_d(t_vars *vars)
{
	vars->player_x += 1;
	if (vars->map[vars->player_y][vars->player_x] == '1')
		return (0);
	if (vars->map[vars->player_y][vars->player_x] == 'X')
	{   
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->lives--;
	}
	if (vars->map[vars->player_y][vars->player_x] == 'C')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->collectable -= 1;
	}
	if (vars->map[vars->player_y][vars->player_x] == '0')
		vars->map[vars->player_y][vars->player_x] = 'P';
	vars->map[vars->player_y][vars->player_x - 1] = '0';
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}