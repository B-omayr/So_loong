/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:13:22 by iomayr            #+#    #+#             */
/*   Updated: 2021/12/14 16:44:22 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pvoid(unsigned long int n)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		if (n < 10)
			len += ft_putchar(n + 48);
		else
			len += ft_putchar(n + 87);
	}
	else
	{
		len += ft_pvoid(n / 16);
		len += ft_pvoid(n % 16);
	}
	return (len);
}

int	ft_ppvoid(unsigned long int n)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_pvoid(n);
	return (len);
}
