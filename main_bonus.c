/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:47:09 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 14:27:55 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_gnl	gnl;
	t_mlx	mlx;
	int		x;
	int		y;

	if (ac != 2)
		error_map(8);
	if (check(av[1]) == EXIT_FAILURE)
		error_map(9);
	read_map(av[1], &gnl);
	x = ft_strlen(gnl.map[0]) * 100;
	y = gnl.count_line * 100;
	mlx.gnl = &gnl;
	mlx.mvt = 0;
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, x, y, "So_long");
	make_all(&mlx);
	print_wall(&mlx, &gnl);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop_hook(mlx.init, enemy_hook, &mlx);
	mlx_hook(mlx.win, 17, (1L << 17), cross, &mlx);
	mlx_loop(mlx.init);
}
