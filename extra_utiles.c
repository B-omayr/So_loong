/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:05:47 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 16:06:34 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_last(t_mlx *mlx)
{
	keycounter(mlx);
	exit(0);
}

void	keycounter(t_mlx *mlx)
{
	mlx->mvt++;
	ft_printf("\nkeycounter :%d", mlx->mvt);
}

int	cross(void)
{
	exit(0);
}

int	check(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 4] == '.')
		if (str[len - 3] == 'b')
			if (str[len - 2] == 'e')
				if (str[len - 1] == 'r')
					return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
