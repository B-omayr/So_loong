/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utiles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:06:35 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 15:10:06 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_print(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_lenght(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;

	i = ft_lenght(n);
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	if (n < 0)
		ptr[0] = '-';
	else if (n == 0)
		ptr[0] = '0';
	while (n != 0)
	{
		--i;
		ptr[i] = ft_print(n % 10) + '0';
		n = n / 10;
	}
	return (ptr);
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
