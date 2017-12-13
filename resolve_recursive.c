/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/13 23:30:29 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**ft_strcpy_improved(char **dest, char **tab, t_misc S)
{	
	int i;
	int j;

	i = 0;
	while (tab[i])
		i++;
	if ((dest = malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < S.n)
	{
		j = 0;
		while (j < S.n)
			j++;
		if ((dest[i] = malloc(sizeof(char*) * (j + 1))) == NULL)
			return (NULL);
	}
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			dest[i][j] = tab[i][j];
	}
	return (dest);
}

t_misc	ft_find_spot(t_tetri tetriminos, char **tab, t_misc S)
{
	while (test_position(tetriminos, S, tab) == 1 && S.a < S.n)
	{
		S.b++;
		S = find_next_point(S, tab);
	}
	return (S);
}

int		ft_double_test(char **tab, t_misc S, t_tetri *tetriminos)
{
		if (test_position(tetriminos[S.e], S, tab) == 0)
		{
			S.c = S.a;
			S.d = S.b;
			tab = draw_tetriminos(tetriminos[S.e], S, tab);
			S = ft_find_spot(tetriminos[S.e + 1], tab, S);
			if (test_position(tetriminos[S.e + 1], S, tab) == 0 && (S.e + 1) < tetriminos[0].nbr - 1)
			{
				ft_erase(tab, tetriminos[S.e]);
				S.a = S.c;
				S.b = S.d;
				return (0);
			}
			else if (test_position(tetriminos[S.e + 1], S, tab) == 0)
			{
				tab = draw_tetriminos(tetriminos[S.e + 1], S, tab);
				S.e++;
				S.a = S.c;
				S.b = S.d;
				return (0);
			}
		}
		ft_erase(tab, tetriminos[S.e]);
		S.a = S.c;
		S.b = S.d;
		return (1);
}

char	**combination_recursive(t_tetri *tetriminos, t_misc S, char **str)
{
	if (tetriminos[0].nbr == 1)
	{
		draw_tetriminos(tetriminos[0], S,  str);
		return (str);
	}
	if (S.e >= tetriminos[0].nbr)
		return (str);
	if (ft_double_test(str, S, tetriminos) == 0)
	{
		str = draw_tetriminos(tetriminos[S.e], S, str);
		S.e++;
		if (S.e == tetriminos[0].nbr)
			return (str);
		combination_recursive(tetriminos, S, str);
	}
	else
	{
		if (S.e > 0)
			S.e--;
		S = ft_findcoord(str, S, tetriminos[S.e]);
		return (combination_recursive(tetriminos, S, str));
	}
	return (NULL);
}

char	**resolve_recursive(t_misc S, t_tetri *tetriminos)
{
		char	**str;

		S.a = 0;
		S.b = 0;
		S.e = 0;
		str = ft_tab(S.n);
		str = combination_recursive(tetriminos, S, str); 
		if (str != NULL)
			return (str);
		else
		{
			S.n++;
			return (resolve_recursive(S, tetriminos));
		}
}
