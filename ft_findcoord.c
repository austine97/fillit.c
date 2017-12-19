/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:08:24 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/19 14:38:33 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static t_misc	ft_findcoordbis(int i, int j, int f, t_misc *s)
{
	j++;
	if (f == 0)
	{
		i = 0;
		j = 1;
	}
	if (j >= s->n)
	{
		j = 0;
		i++;
	}
	s->a = i;
	s->b = j;
	return (*s);
}

t_misc			ft_findcoord(t_misc *s, t_tetri tetrimino)
{
	int i;
	int j;
	int f;

	i = -1;
	f = 0;
	while (++i < s->n)
	{
		j = -1;
		while (++j < s->n)
		{
			if (s->str[i][j] == tetrimino.coord[3])
			{
				f = 1;
				break ;
			}
		}
		if (f == 1)
			break ;
	}
	*s = ft_findcoordbis(i, j, f, s);
	return (*s);
}
