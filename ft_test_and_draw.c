/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_and_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:53:28 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/19 17:08:53 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_misc	test_positionbis(t_tetri tetriminos, t_misc s, int k)
{
	if (tetriminos.coord[k] == 'P' && s.str[s.a][s.b])
	{
		s.b = s.b - 2;
		s.a++;
	}
	if (tetriminos.coord[k] == 'R' && s.str[s.a][s.b])
		s.b++;
	if (tetriminos.coord[k] == 'D' && s.str[s.a][s.b])
		s.a++;
	if (tetriminos.coord[k] == 'L' && s.str[s.a][s.b])
		s.b--;
	if (tetriminos.coord[k] == 'Z' && s.str[s.a][s.b])
	{
		s.a++;
		s.b--;
	}
	if (tetriminos.coord[k] == 'X' && s.str[s.a][s.b])
	{
		s.a++;
		s.b++;
	}
	return (s);
}

int		test_position(t_tetri tetriminos, t_misc s)
{
	int		count;
	int		k;

	k = -1;
	count = 0;
	while (s.str[s.a][s.b] && count <= 3)
	{
		if (s.str[s.a][s.b] == '.')
			count++;
		else
			break ;
		if (++k <= 2)
			s = test_positionbis(tetriminos, s, k);
		if (s.a < 0 || s.b < 0)
			return (1);
	}
	if (count == 4)
		return (0);
	else
		return (1);
}

t_misc	draw_tetriminosbis(t_tetri tetriminos, t_misc s, int k)
{
	if (tetriminos.coord[k] == 'P' && s.str[s.a][s.b])
	{
		s.b = s.b - 2;
		s.a++;
	}
	if (tetriminos.coord[k] == 'R' && s.str[s.a][s.b])
		s.b++;
	if (tetriminos.coord[k] == 'D' && s.str[s.a][s.b])
		s.a++;
	if (tetriminos.coord[k] == 'L' && s.str[s.a][s.b])
		s.b--;
	if (tetriminos.coord[k] == 'Z' && s.str[s.a][s.b])
	{
		s.a++;
		s.b--;
	}
	if (tetriminos.coord[k] == 'X' && s.str[s.a][s.b])
	{
		s.a++;
		s.b++;
	}
	return (s);
}

char	**draw_tetriminos(t_tetri tetriminos, t_misc s)
{
	int k;

	k = 0;
	while (k <= 3)
	{
		s.str[s.a][s.b] = tetriminos.coord[3];
		if (k <= 2)
			s = draw_tetriminosbis(tetriminos, s, k);
		k++;
	}
	return (s.str);
}
