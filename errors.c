/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:16:52 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 14:26:39 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_printf("You have a complete wall inside of your map");
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
