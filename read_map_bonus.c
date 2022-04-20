/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:47:42 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 14:50:14 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_character(t_gnl *gnl)
{
	int	i;
	int	j;

	i = 0;
	while (++i < gnl->count_line - 1)
	{
		j = 0;
		while (++j < ft_strlen(gnl->map[i]))
		{
			if (gnl->map[i][j] == 'E')
				gnl->e++;
			else if (gnl->map[i][j] == 'P')
				gnl->p++;
			else if (gnl->map[i][j] == 'C')
				gnl->c++;
			else if (gnl->map[i][j] == 'I')
				gnl->i++;
			else if (gnl->map[i][j] != '1' && gnl->map[i][j] != '0')
				if (gnl->map[i][j] != 'C' && gnl->map[i][j] != 'E')
					if (gnl->map[i][j] != 'P' && gnl->map[i][j] != 'I')
						error_map(6);
		}
	}
	if (gnl->p != 1 || gnl->c < 1 || gnl->e < 1 || gnl->i != 1)
		error_map(7);
}

void	check_elements_map(t_gnl *gnl)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	while (++i < gnl->count_line - 1)
	{
		j = -1;
		count = 0;
		while (++j < ft_strlen(gnl->map[i]))
			if (gnl->map[i][j] == '1')
				count++;
		if (count == j)
			error_map(5);
	}
	gnl->e = 0;
	gnl->c = 0;
	gnl->p = 0;
	gnl->i = 0;
	check_character(gnl);
}

void	check_map(t_gnl *gnl)
{
	int	j;
	int	i;

	i = -1;
	j = gnl->count_line - 1;
	while (++i < ft_strlen(gnl->map[0]))
		if (gnl->map[0][i] != '1' || gnl->map[j][i] != '1')
			error_map(4);
	i = 0;
	j = ft_strlen(gnl->map[0]) - 1;
	while (++i < gnl->count_line)
		if (gnl->map[i][0] != '1' || gnl->map[i][j] != '1')
			error_map(4);
	check_elements_map(gnl);
}

char	*get_next_line(int fd, t_gnl *gnl)
{
	char	str[1000000];
	char	buff[1];
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while (read(fd, buff, 1) == 1)
	{
		str[i] = buff[0];
		if (str[i + 1] == '\n')
			break ;
		i++;
	}
	str[i] = '\0';
	gnl->buff = ft_strdup(str);
	if (gnl->buff)
		gnl->count_map = ft_strlen(gnl->buff);
	return (gnl->buff);
}

void	read_map(char *av, t_gnl *gnl)
{
	int	i;

	gnl->fd = open(av, O_RDONLY);
	gnl->save = get_next_line(gnl->fd, gnl);
	if (gnl->save == NULL)
		error_map(9);
	gnl->map = ft_split(gnl->save, '\n');
	if (gnl->map == NULL)
		error_map(3);
	i = 0;
	while (gnl->map[i])
		i++;
	gnl->count_line = i;
	if (gnl->count_line == 0)
		error_map(2);
	if (gnl->count_map / gnl->count_line == i)
		error_map(0);
	while (--i > 0)
	{
		if (ft_strlen(gnl->map[i]) != ft_strlen(gnl->map[i - 1]))
			error_map(1);
	}
	check_map(gnl);
}
