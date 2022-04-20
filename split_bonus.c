/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:46:03 by iomayr            #+#    #+#             */
/*   Updated: 2022/03/08 10:40:36 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	find(const char *s, char c)
{
	int	p;
	int	j;

	p = 1;
	j = 0;
	if (s[j] == '\n')
		return (0);
	while (s && s[++j] != '\0')
	{
		if (s[j] == c)
		{
			if (s[j + 1] == c)
				return (0);
			else if (s[j + 1] == '\0')
				p -= 1;
			p++;
		}
	}
	return (p);
}

static char	*ft_print(const char *s, size_t start, size_t end)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((end - start + 1) * (sizeof(char)));
	while (start < end)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		p;
	int		j;
	int		i;

	i = -1;
	j = 0;
	p = -1;
	if (find(s, c) == 0)
		return (0);
	ptr = malloc(sizeof(char *) * (find(s, c) + 1));
	if (!ptr)
		return (0);
	while (++p <= ft_strlen(s))
	{
		if (s[p] != c && i < 0)
			i = p;
		else if ((s[p] == c || p == ft_strlen(s)) && i >= 0)
		{
			ptr[j++] = ft_print(s, i, p);
			i = -1;
		}
	}
	ptr[j] = 0;
	return (ptr);
}
