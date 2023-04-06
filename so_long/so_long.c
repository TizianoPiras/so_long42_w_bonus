/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:22:20 by tpiras            #+#    #+#             */
/*   Updated: 2023/04/04 14:27:29 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	xclose()
// {
// 	exit(0);
// }

int	key_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		move(keycode, vars);
	return (0);
}

int	ft_count(char *s1)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			count++;
		i++;
	}
	count++;
	return (count);
}

int	control_format(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i] != '.')
		i++;
	if (argv[i + 1] != 'b' && argv[i + 2] != 'e'
		&& argv[i + 3] != 'r' && argv[i + 4] != '\0')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		start(&vars, argv[1]);
		if (ft_control(&vars) == 0)
		{
			printf("There is no valid map\nPlease insert a valid map.ber");
			exit (1);
		}
		get_sprite(&vars);
		draw_map(&vars);
		mlx_hook(vars.win, 2, 1L << 0, key_close, &vars);
		mlx_loop_hook(vars.mlx, shootings, &vars);
		mlx_loop(vars.mlx);
	}
	else
	{
		ft_putstr("Error: something goes wrong, please try again!");
		exit(1);
	}
	cleaner(&vars);
}
