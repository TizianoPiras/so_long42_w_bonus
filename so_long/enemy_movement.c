/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:32:41 by tpiras            #+#    #+#             */
/*   Updated: 2023/03/31 14:56:24 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shootings(t_vars *vars)
{
	if (vars->loop_on == NO && vars->collectable == 0)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 -230, vars->height
			/ 2, 0x00FF0000, "GOOD JOB, AND REMEMBER: DON'T PANIC!");
		return (0);
	}
	else
	{
		if (vars->lives > 0)
			x_move(vars);
		if (vars->lives == 0)
			animation(vars);
		if (vars->collectable == 0)
			door_animation(vars);
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}

int	x_move(t_vars *vars)
{
	if (vars->proiettile.x_x != 0)
	{
		vars->proiettile.x_x--;
		if (vars->map[vars->proiettile.x_y][vars->proiettile.x_x] == '0')
			vars->map[vars->proiettile.x_y][vars->proiettile.x_x] = 'X';
		if (vars->map[vars->proiettile.x_y][vars->proiettile.x_x] == '1')
			vars->map[vars->proiettile.x_y]
			[ft_strlen(vars->map[vars->proiettile.x_x]) - 2] = 'X';
		vars->map[vars->proiettile.x_y][vars->proiettile.x_x + 1] = '0';
		if (vars->map[vars->proiettile.x_y][vars->proiettile.x_x] == 'P')
		{
			vars->lives--;
			vars->map[vars->proiettile.x_y][vars->proiettile.x_x] = 'P';
		}
	}
	return (0);
}
