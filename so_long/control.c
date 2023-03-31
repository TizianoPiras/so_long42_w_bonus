/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:06:09 by tpiras            #+#    #+#             */
/*   Updated: 2023/03/31 14:37:11 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checking_edges(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->map[0][y])
	{
		if ((vars->map[0][y] != '1') || (vars->map[vars->i - 1][y] != '1'))
			return (0);
		y++;
	}
	return (1);
}

int	checking_middles(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->i)
	{
		if ((vars->map[i][0] != '1') || (vars->map[i]
		[ft_strlen(vars->map[i]) - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int	checking_stucture(t_vars *vars)
{
	int	x;
	int	ret;
	int	max;

	x = 1;
	max = ft_strlen(vars->map[0]);
	while (vars->map[x])
	{
		ret = ft_strlen(vars->map[x]);
		if (ret != max)
			return (0);
		x++;
	}
	if (max == x)
		return (0);
	return (1);
}

int	checking_elements(t_vars *vars)
{
	int	i;
	int	player;
	int	food;
	int	exit;

	i = 0;
	player = 0;
	food = 0;
	exit = 0;
	while (vars->s[i])
	{
		if (vars->s[i] == 'P')
			player += 1;
		else if (vars->s[i] == 'C')
			food += 1;
		else if (vars->s[i] == 'E')
			exit += 1;
		i++;
	}
	vars->collectable = food;
	if (player != 1 || food == 0 || exit != 1)
		return (0);
	return (1);
}

int	ft_control(t_vars *vars)
{
	if (!vars->map)
		return (0);
	if (checking_edges(vars) == 0)
		return (0);
	if (checking_stucture(vars) == 0)
		return (0);
	if (checking_middles(vars) == 0)
		return (0);
	if (checking_elements(vars) == 0)
		return (0);
	return (1);
}
