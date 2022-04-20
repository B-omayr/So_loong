/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:31:09 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 17:53:17 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	finding_enemy(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (++i < mlx->gnl->count_line - 1)
	{
		j = 0;
		while (++j < ft_strlen(mlx->gnl->map[i]))
		{
			if (mlx->gnl->map[i][j] == 'I')
			{
				mlx->ei = i;
				mlx->ej = j;
			}
		}
	}
}

void	mouve_enemy(t_mlx *mlx)
{
	finding_enemy(mlx);
	if (mlx->gnl->map[mlx->ei + 1][mlx->ej] == '0')
	{
		mlx->gnl->map[mlx->ei + 1][mlx->ej] = 'I';
		mlx->gnl->map[mlx->ei][mlx->ej] = '0';
	}
	else if (mlx->gnl->map[mlx->ei - 1][mlx->ej] == 'P')
		check_last(mlx);
	else if (mlx->gnl->map[mlx->ei - 1][mlx->ej] == '1')
	{
		if (mlx->gnl->map[mlx->ei + 1][mlx->ej] != '1')
		{
			mlx->gnl->map[mlx->ei + 1][mlx->ej] = 'I';
			mlx->gnl->map[mlx->ei][mlx->ej] = '0';
		}
	}
	else if (mlx->gnl->map[mlx->ei + 1][mlx->ej] == '1')
	{
		mlx->gnl->map[mlx->ei - 1][mlx->ej] = 'I';
		mlx->gnl->map[mlx->ei][mlx->ej] = '0';
	}
	else if (mlx->gnl->map[mlx->ei + 1][mlx->ej] == 'P')
		check_last(mlx);
}

int	enemy_hook(t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	mlx->count_enemy++;
	if (mlx->count_enemy == 75)
	{
		mouve_enemy(mlx);
		mlx->count_enemy = 0;
	}
	print_wall(mlx, mlx->gnl);
	return (0);
}
