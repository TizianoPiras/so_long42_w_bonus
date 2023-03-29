/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:00 by tpiras            #+#    #+#             */
/*   Updated: 2023/03/29 14:55:37 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_vars *vars)
 {
 	int		x;
 	int		y;
 	y = -1;

 	if (!vars->map)
 		return ;
 	while (vars->map[++y] != NULL)
 	{
 		x = -1;
 		while (vars->map[y][++x] != '\0')
 		{
			if (vars->collectable == 0)
				vars->map[7][1] = 'E';
 			if (vars->map[y][x] == '1' || vars->map[y][x] == '0')
 				draw_1_0(vars, x, y);
			else if (vars->map[y][x] == 'P' || vars->map[y][x] == 'X' || vars->map[y][x] == 'Z' || vars->map[y][x] == 'V' ||
			vars->map[y][x] == 'A' || vars->map[y][x] == 'S')
 				draw_P_X(vars, x, y);
 			else if (vars->map[y][x] == 'C' || vars->map[y][x] == 'E')
 				draw_E_C(vars, x, y);
			// if (vars->lives >= 0)
			// {
			// 	vars->map[0][0] = 'L'; 
			// 	draw_shields(vars, x, y);
			// }
 		}
 	}
 }

void	draw_1_0(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perimeter, x * 64, y * 64);
	}
	else if (vars->map[y][x] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
	}
}

void	draw_P_X(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player, x * 64, y * 64);
		vars->player_y = y;
    	vars->player_x = x;
	}
	if (vars->map[y][x] == 'X')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->proiettile.enemy_img, x * 64, y * 64);
		vars->proiettile.X_y = y;
		vars->proiettile.X_x = x;
	}
}

void	draw_E_C(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->crew_1, x * 64, y * 64);
	}
	if (vars->map[y][x] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		if (vars->collectable == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->door.door_img, x * 64, y * 64);
	}
}

// void	draw_shields(t_vars *vars, int x, int y)
// {
// 	if (vars->map[y][x] == 'L')
// 	{
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
// 		if (vars->lives == 4)
// 			mlx_put_image_to_window(vars->mlx, vars->win, vars->shield.shield_03, x * 64, y * 64);
// 		if (vars->lives == 3)
// 			mlx_put_image_to_window(vars->mlx, vars->win, vars->shield.shield_02, x * 64, y * 64);
// 		if (vars->lives == 2)
// 			mlx_put_image_to_window(vars->mlx, vars->win, vars->shield.shield_01, x * 64, y * 64);
// 		if (vars->lives == 1)
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->shield.shield_00, x * 64, y * 64);
// 	}
// }