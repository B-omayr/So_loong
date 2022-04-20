/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:49:43 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 16:58:47 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_if_it_complete(t_mlx *mlx, t_gnl *gnl, int i, int j)
{
	if (gnl->map[i][j] == 'E' && gnl->c != 0)
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->exit, mlx->x, mlx->y);
	else if (gnl->map[i][j] == 'E' && gnl->c == 0)
	{
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->f_exit, mlx->x, mlx->y);
	}
}

void	put_img_bonus_wind(t_mlx *mlx, t_gnl *gnl, int i, int j)
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
		check_if_it_complete(mlx, gnl, i, j);
	else if (gnl->map[i][j] == 'I')
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->enemy, mlx->x, mlx->y);
	mlx->x += 100;
	mlx->cx += 100;
}

void	make_all(t_mlx *mlx)
{
	mlx->font = mlx_xpm_file_to_image(mlx->init, "./img_bonus/font.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->wall = mlx_xpm_file_to_image(mlx->init, "./img_bonus/wall.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->collectible = mlx_xpm_file_to_image(mlx->init, "./img_bonus/coll.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->player = mlx_xpm_file_to_image(mlx->init, "./img_bonus/player_a.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->enemy = mlx_xpm_file_to_image(mlx->init, "./img_bonus/enemy.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->exit = mlx_xpm_file_to_image(mlx->init, "./img_bonus/close_door.xpm",
			&mlx->font_w, &mlx->font_h);
	mlx->f_exit = mlx_xpm_file_to_image(mlx->init, "./img_bonus/open_door.xpm",
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
			put_img_bonus_wind(mlx, gnl, i, j);
		mlx->x = 0;
		mlx->y += 100;
		mlx->cx = 0;
		mlx->cy += 100;
	}
	if (mlx->gnl->c == 0)
		mlx_string_put(mlx->init, mlx->win, 700, 42, 0x00002b8,
			"You're Stole aLL My Bitcoin . Give it back to me");
	mlx_string_put(mlx->init, mlx->win, 25, 42, 0x00002b8, "Moves  :");
	mlx_string_put(mlx->init, mlx->win, 125, 42, 0x00002b8, fr(mlx));
}
