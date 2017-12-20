/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:10:13 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/20 13:45:12 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int	ft_is_there_h(char *line)
{
	int i;
	int	flag;

	i = 0;
	flag = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

static int	ft_find_highest_nbr(int nbr, t_tetri *tetriminos)
{
	char	**line;
	int		j;
	int		k;
	int		highest;

	nbr--;
	highest = 0;
	while (tetriminos[++nbr])
	{
		k = 0;
		j = 0;
		line = ft_strsplit(tetriminos[nbr], '\n');
		while (line[j] && ft_is_there_h(line[j]) == 0)
			j++;
		while (line[j] && ft_is_there_h(line[j]) == 1)
		{
			k++;
			j++;
		}
		if (k >= highest)
			highest = k;
	}
	return (highest);
}

int			ft_optimization(t_tetri *tetriminos, t_misc s)
{
	if (ft_find_highest_nbr(s.e, tetriminos) > s.n - s.a)
		return (1);
	else
		return (0);
}
