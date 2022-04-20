/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Hexaa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:53:13 by iomayr            #+#    #+#             */
/*   Updated: 2021/12/15 09:43:31 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hexaadicimal(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		if (n < 10)
			len += ft_putchar(n + 48);
		else
			len += ft_putchar(n + 55);
	}
	else
	{
		len += ft_hexaadicimal(n / 16);
		len += ft_hexaadicimal(n % 16);
	}
	return (len);
}
