/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:06:16 by tpiras            #+#    #+#             */
/*   Updated: 2023/03/31 14:41:03 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_image(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->death.d_stance == 1)
		vars->player = mlx_xpm_file_to_image
			(vars->mlx, "./assets/Player/Death_00.xpm", &x, &y);
	if (vars->death.d_stance == 2)
		vars->player = mlx_xpm_file_to_image
			(vars->mlx, "./assets/Player/Death_01.xpm", &x, &y);
	if (vars->death.d_stance == 3)
		vars->player = mlx_xpm_file_to_image
			(vars->mlx, "./assets/Player/Death_02.xpm", &x, &y);
	if (vars->death.d_stance == 4)
		vars->player = mlx_xpm_file_to_image
			(vars->mlx, "./assets/Player/Death_03.xpm", &x, &y);
	if (vars->death.d_stance == 5)
		vars->player = mlx_xpm_file_to_image
			(vars->mlx, "./assets/Player/Death_04.xpm", &x, &y);
	if (vars->death.d_stance == 6)
		vars->player = mlx_xpm_file_to_image
			(vars->mlx, "./assets/Player/Death_05.xpm", &x, &y);
	if (vars->death.d_stance == 7)
		mlx_destroy_image(vars->mlx, vars->player);
}

int	animation(t_vars *vars)
{
	while (vars->death_loop < 2000)
	{
		vars->death_loop++;
	}
	if (vars->death_loop == 2000)
	{
		vars->death.d_stance++;
		change_image(vars);
		vars->death_loop = 0;
	}
	return (0);
}
