/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/19 19:10:09 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_misc			ft_double_test(t_misc s, t_tetri *tetriminos)
{
	s.c = s.a;
	s.d = s.b;
	if (test_position(tetriminos[s.e], s) == 0)
	{
		s.str = draw_tetriminos(tetriminos[s.e], s);
		s = ft_find_spot_start(tetriminos[s.e + 1], s);
		if (test_position(tetriminos[s.e + 1], s) == 0 &&
				(s.e + 1) < tetriminos[0].nbr - 1)
		{
			s.p = 0;
			return (s);
		}
		else if (test_position(tetriminos[s.e + 1], s) == 0)
		{
			s.str = draw_tetriminos(tetriminos[s.e + 1], s);
			s.p = 0;
			return (s);
		}
	}
	s.p = 1;
	return (s);
}

static char		**combination_recursivebis(t_tetri *tetriminos, t_misc *s)
{
	*s = ft_findcoord(s, tetriminos[s->e]);
	ft_erase(s->str, tetriminos[s->e]);
	*s = ft_find_spot(tetriminos[s->e], *s);
	while (s->e > 0 && s->a >= s->n)
	{
		s->e--;
		*s = ft_findcoord(s, tetriminos[s->e]);
		ft_erase(s->str, tetriminos[s->e]);
		*s = ft_find_spot(tetriminos[s->e], *s);
	}
	if (s->e == 0 && s->a >= s->n)
		return (NULL);
	return (s->str);
}

char			**combination_recursive(t_tetri *tetriminos, t_misc *s)
{
	if (tetriminos[0].nbr == 1)
	{
		draw_tetriminos(tetriminos[0], *s);
		return (s->str);
	}
	if (s->e >= tetriminos[0].nbr - 1)
		return (s->str);
	*s = ft_double_test(*s, tetriminos);
	if (s->p == 0)
	{
		s->e++;
		if (s->e >= tetriminos[0].nbr - 1)
			return (s->str);
		return (s->str);
	}
	else
	{
		if ((s->str = combination_recursivebis(tetriminos, s)) == NULL)
			return (NULL);
		return (combination_recursive(tetriminos, s));
	}
	return (NULL);
}

static t_misc	extra_condition(t_misc s)
{
	if (s.b >= s.n)
	{
		s.b = 0;
		s.a++;
	}
	return (s);
}

char			**resolve_recursive(t_misc s, t_tetri *tetriminos)
{
	s = initialize_s(s);
	while (s.e < tetriminos[0].nbr - 1)
	{
		s = extra_condition(s);
		if (s.a >= s.n)
		{
			s.n++;
			return (resolve_recursive(s, tetriminos));
		}
		s.str = combination_recursive(tetriminos, &s);
		if (s.str == NULL)
		{
			s.n++;
			return (resolve_recursive(s, tetriminos));
		}
		else
		{
			if (s.str && s.e >= tetriminos[0].nbr - 1)
				return (s.str);
			s.str = combination_recursive(tetriminos, &s);
		}
	}
	return (s.str);
}
