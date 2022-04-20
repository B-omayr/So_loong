/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:51:14 by iomayr            #+#    #+#             */
/*   Updated: 2021/12/14 17:17:09 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hexadicimal(unsigned int c)
{
	int	len;

	len = 0;
	if (c < 16)
	{
		if (c < 10)
			len += ft_putchar(c + 48);
		else
			len += ft_putchar(c + 87);
	}
	else
	{
		len += ft_hexadicimal(c / 16);
		len += ft_hexadicimal(c % 16);
	}
	return (len);
}
