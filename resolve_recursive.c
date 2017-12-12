/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/12 22:07:41 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**ft_strcpy_improved(char **dest, char **tab)
{	
	int i;
	int j;

	i = 0;
	while (tab[i])
		i++;
	if ((dest = malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j])
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
// F: fonction recursive qui va essayer toutes les combinaisons de tetriminos

char	**combination_recursive(t_tetri *tetriminos, t_misc S, char **str)
{
	int 	i;
	int 	x;
	int 	flag;
	int 	ssa;
	int 	ssb;
	char	**save;

	i = 0;
	save = NULL;
	save = ft_strcpy_improved(save, str);
	ssa = S.a;
	ssb = S.b;
	if ((test_position(tetriminos[0], S.a, S.b, str)) == 1)
			return (NULL);
	while (i < tetriminos[0].nbr)
	{
		x = 0;
		flag = 0;
		while (S.a * S.b < S.n * S.n)
		{
			find_next_point(S.a, S.b, str);
			if (test_position(tetriminos[i], S.a, S.b, str) == 0)
			{
				draw_tetriminos(tetriminos[i], S.a, S.b, str);
				i++;
				break ;
			}
			else
				x++;
			if (x >= S.n * S.n)
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 1)
			break ;
	}
	if (i == tetriminos[0].nbr)
		return (str);
	else
	{
		while (test_position(tetriminos[0], ssa, ssb, str) == 1 && ssb < S.n)
		{
			while (test_position(tetriminos[0], ssa, ssb, str) == 1 && ssa < S.n)
				ssa++;
			ssb++;
		}
		S.a = ssa;
		S.b = ssb;
		return (combination_recursive(tetriminos, S, save));
	}
}

char	**resolve_recursive(t_misc S,  t_tetri *tetriminos)
{
	char	**str;

	S.a = 0;
	S.b = 0;
	str = ft_tab(S.n);
	str = combination_recursive(tetriminos, S, str); // tab prend NULL ou la solution optimal.
	if (str != NULL)
		return (str);
	else
	{
		S.n++;
		return (resolve_recursive(S, tetriminos));
	}
}
