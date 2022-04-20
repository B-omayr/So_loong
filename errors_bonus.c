/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:50:06 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 14:26:18 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_map(int err)
{
	ft_printf("!!!Oups eroor\n");
	if (err == 0)
		ft_printf("your map is rectangular");
	else if (err == 1)
		ft_printf("check the lenght of lines");
	else if (err == 2)
		ft_printf("your map is empty");
	else if (err == 3)
		ft_printf("you have a line break in your map");
	else if (err == 4)
		ft_printf("you should check you walls");
	else if (err == 5)
		ft_printf("You have a complete wall inside of you map");
	else if (err == 6)
		ft_printf("Invalid char");
	else if (err == 7)
		ft_printf("you should count your char");
	else if (err == 8)
		ft_printf("invalid arguments");
	else if (err == 9)
		ft_printf("check the name file of your map");
	exit(0);
}
