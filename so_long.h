/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:22:02 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 16:21:22 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "ft_printf/libftprintf.h"

typedef struct gnl_variable
{
	char	**map;
	char	*save;
	char	*buff;
	int		count_map;
	int		count_line;
	int		fd;
	int		e;
	int		p;
	int		c;
	int		pi;
	int		pj;
	int		count;
}t_gnl;

typedef struct mlx_variables
{
	t_gnl	*gnl;
	void	*init;
	void	*win;
	void	*font;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
	int		font_w;
	int		font_h;
	int		x;
	int		y;
	int		cx;
	int		cy;
	int		count;
	int		mvt;
}t_mlx;

void	read_map(char *av, t_gnl *gnl);
char	*get_next_line(int fd, t_gnl *gnl);
void	error_map(int err);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *str);
int		ft_strlen(char const *str);
int		cross(void);
void	make_all(t_mlx *mlx);
void	print_wall(t_mlx *mlx, t_gnl *gnl);
int		key_hook(int keycode, t_mlx *mlx);
void	check_last(t_mlx *mlx);
void	keycounter(t_mlx *mlx);
void	s(t_mlx *mlx);
void	d(t_mlx *mlx);
void	w(t_mlx *mlx);
void	a(t_mlx *mlx);
int		enemy_hook(t_mlx *mlx);
int		check(char *str);

#endif