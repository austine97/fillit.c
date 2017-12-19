/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_spot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:29:16 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/19 17:32:55 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_misc		ft_find_spot_start(t_tetri tetriminos, t_misc s)
{
	s.a = 0;
	s.b = 0;
	while (test_position(tetriminos, s) == 1 && s.str[s.a][s.b] != 'e')
	{
		s.b++;
		s = find_next_point(s);
	}
	return (s);
}

t_misc		ft_find_spot(t_tetri tetriminos, t_misc s)
{
	while (test_position(tetriminos, s) == 1 && s.str[s.a][s.b] != 'e')
	{
		s.b++;
		s = find_next_point(s);
	}
	return (s);
}
