/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:48:51 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 14:57:53 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	finding_p(t_gnl *gnl)
{
	int	i;
	int	j;

	i = 0;
	while (++i < gnl->count_line - 1)
	{
		j = 0;
		while (++j < ft_strlen(gnl->map[i]) - 1)
		{
			if (gnl->map[i][j] == 'P')
			{
				gnl->pj = j;
				gnl->pi = i;
			}
		}
	}
}

void	a(t_mlx *mlx)
{
	finding_p(mlx->gnl);
	if (mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj - 1] == '1')
		return ;
	else if (mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj - 1] == '0')
	{
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj - 1] = 'P';
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj] = '0';
		mlx->mvt++;
	}
	else if (mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj - 1] == 'C')
	{
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj - 1] = 'P';
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj] = '0';
		mlx->gnl->c--;
		mlx->mvt++;
	}
	else if (mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj - 1] == 'E'
		&& mlx->gnl->c == 0)
		check_last(mlx);
	mlx->player = mlx_xpm_file_to_image(mlx->init, "./img_bonus/player_a.xpm",
			&mlx->font_w, &mlx->font_h);
	print_wall(mlx, mlx->gnl);
}

void	d(t_mlx *mlx)
{
	finding_p(mlx->gnl);
	if (mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj + 1] == '1')
		return ;
	else if (mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj + 1] == '0')
	{
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj + 1] = 'P';
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj] = '0';
		mlx->mvt++;
	}
	else if (mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj + 1] == 'C')
	{
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj + 1] = 'P';
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj] = '0';
		mlx->gnl->c--;
		mlx->mvt++;
	}
	else if (mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj + 1] == 'E'
		&& mlx->gnl->c == 0)
		check_last(mlx);
	mlx->player = mlx_xpm_file_to_image(mlx->init, "./img_bonus/player_d.xpm",
			&mlx->font_w, &mlx->font_h);
	print_wall(mlx, mlx->gnl);
}

void	s(t_mlx *mlx)
{
	finding_p(mlx->gnl);
	if (mlx->gnl->map[mlx->gnl->pi + 1][mlx->gnl->pj] == '1')
		return ;
	else if (mlx->gnl->map[mlx->gnl->pi + 1][mlx->gnl->pj] == '0')
	{
		mlx->gnl->map[mlx->gnl->pi + 1][mlx->gnl->pj] = 'P';
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj] = '0';
		mlx->mvt++;
	}
	else if (mlx->gnl->map[mlx->gnl->pi + 1][mlx->gnl->pj] == 'C')
	{
		mlx->gnl->map[mlx->gnl->pi + 1][mlx->gnl->pj] = 'P';
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj] = '0';
		mlx->gnl->c--;
		mlx->mvt++;
	}
	else if (mlx->gnl->map[mlx->gnl->pi + 1][mlx->gnl->pj] == 'E'
		&& mlx->gnl->c == 0)
		check_last(mlx);
	mlx->player = mlx_xpm_file_to_image(mlx->init, "./img_bonus/player_s.xpm",
			&mlx->font_w, &mlx->font_h);
	print_wall(mlx, mlx->gnl);
}

void	w(t_mlx *mlx)
{
	finding_p(mlx->gnl);
	if (mlx->gnl->map[mlx->gnl->pi - 1][mlx->gnl->pj] == '1')
		return ;
	else if (mlx->gnl->map[mlx->gnl->pi - 1][mlx->gnl->pj] == '0')
	{
		mlx->gnl->map[mlx->gnl->pi - 1][mlx->gnl->pj] = 'P';
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj] = '0';
		mlx->mvt++;
	}
	else if (mlx->gnl->map[mlx->gnl->pi - 1][mlx->gnl->pj] == 'C')
	{
		mlx->gnl->map[mlx->gnl->pi - 1][mlx->gnl->pj] = 'P';
		mlx->gnl->map[mlx->gnl->pi][mlx->gnl->pj] = '0';
		mlx->gnl->c--;
		mlx->mvt++;
	}
	else if (mlx->gnl->map[mlx->gnl->pi - 1][mlx->gnl->pj] == 'E'
		&& mlx->gnl->c == 0)
		check_last(mlx);
	mlx->player = mlx_xpm_file_to_image(mlx->init, "./img_bonus/player_w.xpm",
			&mlx->font_w, &mlx->font_h);
	print_wall(mlx, mlx->gnl);
}
