/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_libft_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:48:18 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 15:09:32 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = (char)str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	cross(void)
{
	printf("Game Over......");
	exit(0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 0)
		a(mlx);
	else if (keycode == 1)
		s(mlx);
	else if (keycode == 2)
		d(mlx);
	else if (keycode == 13)
		w(mlx);
	else if (keycode == 53)
	{
		printf("Game Over......");
		exit(0);
	}
	return (0);
}

void	check_last(t_mlx *mlx)
{
	mlx->mvt++;
	exit(0);
}
