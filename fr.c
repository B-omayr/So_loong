/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:53:19 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 14:15:10 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*fr(t_mlx *ll)
{
	char	*tmp;
	char	*current;

	current = ft_itoa(ll->mvt);
	tmp = current;
	free(current);
	return (tmp);
}
