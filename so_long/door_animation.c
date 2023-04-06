/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:06:16 by tpiras            #+#    #+#             */
/*   Updated: 2023/04/06 13:51:25 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_door(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->door.door_stance == 2)
		vars->door.door_img = mlx_xpm_file_to_image
			(vars->mlx, "./assets/frame_1_door.xpm", &x, &y);
	if (vars->door.door_stance == 4)
		vars->door.door_img = mlx_xpm_file_to_image
			(vars->mlx, "./assets/frame_2_door.xpm", &x, &y);
	if (vars->door.door_stance == 8)
		vars->door.door_img = mlx_xpm_file_to_image
			(vars->mlx, "./assets/frame_3_door.xpm", &x, &y);
	if (vars->door.door_stance == 16)
		vars->door.door_img = mlx_xpm_file_to_image
			(vars->mlx, "./assets/frame_4_door.xpm", &x, &y);
	if (vars->door.door_stance == 32)
		vars->door.door_img = mlx_xpm_file_to_image
			(vars->mlx, "./assets/frame_5_door.xpm", &x, &y);
	if (vars->door.door_stance == 64)
		vars->door.door_img = mlx_xpm_file_to_image
			(vars->mlx, "./assets/frame_6_door.xpm", &x, &y);
}

int	door_animation(t_vars *vars)
{
	while (vars->door.door_loop < 2000)
	{
		vars->door.door_loop++;
	}
	if (vars->door.door_loop == 2000)
	{
		vars->door.door_stance++;
		open_door(vars);
		vars->door.door_loop = 0;
	}
	return (0);
}
