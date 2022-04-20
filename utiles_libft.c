/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:47:55 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 15:09:20 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (--i >= 0)
	{
		if ((char)str[i] == (char)c)
			return ((char *)&str[i]);
	}
	return (NULL);
}

int	ft_strncmp(char *str, char *ptr, int len)
{
	int	i;

	i = 0;
	while (i < len && (str[i] || ptr[i]))
	{
		if (str[i] != ptr[i])
			return (str[i] - ptr[i]);
		i++;
	}
	return (1);
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
		exit(0);
	return (0);
}
