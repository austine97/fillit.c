/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:16:09 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/19 16:20:47 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_misc	find_next_point(t_misc s)
{
	if (s.str[s.a][s.b] == 'e')
	{
		s.a++;
		s.b = 0;
	}
	while (s.str[s.a][s.b] != 'e' && s.str[s.a][s.b] != '.')
	{
		while (s.str[s.a + 1][s.b + 1] != 'e' && s.str[s.a][s.b] != '.')
			s.b++;
		if (s.str[s.a][s.b] != '.')
		{
			s.a++;
			s.b = 0;
		}
	}
	return (s);
}
