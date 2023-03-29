/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:32:41 by tpiras            #+#    #+#             */
/*   Updated: 2023/03/29 15:02:58 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shootings(t_vars *vars)
{
	if (vars->loop_on == NO)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 -230, vars->height / 2,
		 0x00FF0000, "GOOD JOB, AND REMEMBER: DON'T PANIC!");
		return (0);
	}
	// if (vars->proiettile.enemy_loop < 2000)
	// {
	// 	vars->proiettile.enemy_loop++;
	// 	return (0);
	// }
	vars->proiettile.enemy_loop = 0;
	if (vars->lives > 0)
		X_move(vars);
	if (vars->lives == 0)
		animation(vars);
	if (vars->collectable == 0)
		door_animation(vars);
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}

int		X_move(t_vars *vars)
{
	if (vars->proiettile.X_x != 0)
	{
		vars->proiettile.X_x--;
		if (vars->map[vars->proiettile.X_y][vars->proiettile.X_x] == '0')
			vars->map[vars->proiettile.X_y][vars->proiettile.X_x] = 'X';
		if (vars->map[vars->proiettile.X_y][vars->proiettile.X_x] == '1')
		    vars->map[vars->proiettile.X_y][vars->proiettile.X_x + 28] = 'X';
		vars->map[vars->proiettile.X_y][vars->proiettile.X_x + 1] = '0';
		if (vars->map[vars->proiettile.X_y][vars->proiettile.X_x] == 'P')
		{
			vars->lives--;
			vars->map[vars->proiettile.X_y][vars->proiettile.X_x] = 'P';
		}
	}
	return (0);
}
