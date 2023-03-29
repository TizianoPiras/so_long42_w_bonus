/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:12:34 by tpiras            #+#    #+#             */
/*   Updated: 2023/03/29 15:10:15 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_matrix(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i] != NULL)
	{
		j = -1;
		while (vars->map[i][++j] != '\0')
		{
			printf("%c",vars->map[i][j]);
		}
		printf("\n");
	}
}

t_vars	start(t_vars *vars, char *path)
{
	vars->mlx = mlx_init();
	vars->flag = 0;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->proiettile.X_x = 0;
	vars->proiettile.X_y = 0;
	vars->proiettile.enemy_loop = 0;
	vars->collectable = 5;
	vars->loop_on = YES;
	vars->lives = 1;
	vars->death.d_stance = 0;
	vars->death_loop = 0;
	vars->door.door_stance = 0;
	vars->door.door_loop = 0;
	char *s = (char*) malloc (sizeof(char) * 1000000);
	vars->fd = open(path, O_RDONLY);
	if (vars->fd == -1)
		exit(1);
	read(vars->fd, s, 1000000);
    vars->map = ft_split(s, '\n');
	print_matrix(vars);
	vars->i = ft_count(s);
    vars->height = vars->i * 64;
	vars->width = ft_strlen(vars->map[0]) * 64;
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "tpiras so_long");
	//printf("death loop: %d, lives: %d\n", vars->death_loop, vars->lives);
    return (*vars);
}

int	get_sprite(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->bg = mlx_xpm_file_to_image(vars->mlx, "./assets/Tile_of_BG_stars_1.xpm" , &x, &y);
	vars->perimeter = mlx_xpm_file_to_image(vars->mlx, "./assets/Player/Death_05.xpm", &x, &y);
	vars->player = mlx_xpm_file_to_image(vars->mlx, "./assets/Player/Cuore_d'oro_FS.xpm", &x, &y);
	vars->proiettile.enemy_img = mlx_xpm_file_to_image(vars->mlx, "./assets/Enemy/projectiles_FS.xpm", &x, &y);
	vars->crew_1 = mlx_xpm_file_to_image(vars->mlx, "./assets/Collectables/Marvin_FS.xpm", &x, &y);
	vars->door.door_img = mlx_xpm_file_to_image(vars->mlx, "./assets/frame_0_door_Tavola disegno 11679567764.xpm", &x, &y);
	// vars->shield.shield_00 = mlx_xpm_file_to_image(vars->mlx, "./assets/shield_00.xpm", &x, &y);
	// vars->shield.shield_01 = mlx_xpm_file_to_image(vars->mlx, "./assets/shield_01.xpm", &x, &y);
	// vars->shield.shield_02 = mlx_xpm_file_to_image(vars->mlx, "./assets/shield_02.xpm", &x, &y);
	// vars->shield.shield_03 = mlx_xpm_file_to_image(vars->mlx, "./assets/shield_03.xpm", &x, &y);
	if (!vars->bg || !vars->perimeter || !vars->player || !vars->proiettile.enemy_img || !vars->crew_1)
		exit (1);
	return (1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	cleaner(t_vars *vars)
{
	int	x;

	x = 0;
	while (x <= vars->i)
	{
		free(vars->map[x]);
		x++;
	}
	free(vars->map);
}
