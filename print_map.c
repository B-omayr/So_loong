/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:16:38 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 14:42:54 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_wind(t_mlx *mlx, t_gnl *gnl, int i, int j)
{
	mlx_put_image_to_window(mlx->init, mlx->win,
		mlx->font, mlx->x, mlx->y);
	if (gnl->map[i][j] == '1')
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->wall, mlx->x, mlx->y);
	else if (gnl->map[i][j] == 'P')
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->player, mlx->x, mlx->y);
	else if (gnl->map[i][j] == 'C')
	{
		mlx->cx += 12;
		mlx->cy += 12;
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->collectible, mlx->cx, mlx->cy);
		mlx->cx -= 12;
		mlx->cy -= 12;
	}
	else if (gnl->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->exit, mlx->x, mlx->y);
	mlx->x += 100;
	mlx->cx += 100;
}

void	make_all(t_mlx *mlx)
{
	mlx->font = mlx_xpm_file_to_image(mlx->init, "./img/font.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->wall = mlx_xpm_file_to_image(mlx->init, "./img/wall.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->exit = mlx_xpm_file_to_image(mlx->init, "./img/exit.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->collectible = mlx_xpm_file_to_image(mlx->init, "./img/collectible.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->player = mlx_xpm_file_to_image(mlx->init, "./img/player.xpm",
			&mlx->font_w, &mlx->font_h);
}

void	print_wall(t_mlx *mlx, t_gnl *gnl)
{
	int	i;
	int	j;

	mlx_clear_window(mlx->init, mlx->win);
	mlx->x = 0;
	mlx->y = 0;
	mlx->cx = 0;
	mlx->cy = 0;
	i = -1;
	while (++i < gnl->count_line)
	{
		j = -1;
		while (++j < ft_strlen(gnl->map[0]))
		{
			put_img_wind(mlx, gnl, i, j);
		}
		mlx->x = 0;
		mlx->y += 100;
		mlx->cx = 0;
		mlx->cy += 100;
	}
}
