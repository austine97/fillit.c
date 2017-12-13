/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/13 20:03:23 by ybouzgao         ###   ########.fr       */
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

/*char	**ft_double_test(char **tab, t_misc S, t_tetri *tetriminos)
  {
  char	**str;
  int		i;
  int		j;
  int		ssa;
  int		ssb;

  ssa = S.a;
  ssb = S.b;
  i = ssa;
  j = ssb;
  str = NULL;
  str = ft_strcpy_improved(str, tab, S);
  while (i * j < (S.n - 1) * (S.n - 1))
  {
  S.a = i;
  S.b = j;
  if (test_position(a, S, str) == 0)
  {
  draw_tetriminos(a, S.a, S.b, str);
  i = S.a;
  j = S.b;
  while (S.a * S.b < (S.n - 1) * (S.n - 1))
  {
  find_next_point(S, str);
  if (test_position(b, S, str) == 0)
  {
  if (b.coord[3] == b.nbr - 'A')
  draw_tetriminos(b, S.a, S.b, str);
  S.a = 0;
  S.b = 0;
  return (str);
  }
  S.b++;
  if (S.b >= S.n)
  {
  S.b = 0;
  S.a++;
  }
  }
  }
  j++;
  if (j >= S.n)
  {
  j = 0;
  i++;
  }
  ft_freestr(str);
  str = ft_strcpy_improved(str, tab, S);
  }
  return (tab);

  }*/

char	**ft_double_test(char **tab, t_misc S, t_tetri *tetriminos)
{
	while (S.a < S.n && S.b < S.n)
	{
		while (test_position(tetriminos[S.e], S, tab) == 1)
		{
			S.b++;
			if (S.b >= S.n)
			{
				S.a++;
				S.b = 0;
			}
		}
		if (test_position(tetriminos[S.e], S, tab) == 0)
		{
			draw_tetriminos(tetriminos[S.e], S, tab);
			while (test_position(tetriminos[S.e + 1], S, tab) == 1)
			{
				find_next_point(S, tab);
				S.b++;
				if (S.b >= S.n)
				{
					S.a++;
					S.b = 0;
				}
			}
			if (test_position(tetriminos[S.e + 1], S, tab) == 0)
			{
				S.e++;
				return (combination_recursive(tetriminos, S, tab));
			}
		}
	}
}

char	**combination_recursive(t_tetri *tetriminos, t_misc S, char **str)
{
	S.e = 0;
	if (tetriminos[0].nbr == 1)
	{
		draw_tetriminos(tetriminos[0], 0, 0, str);
		S.e++;
	}




	if (S.e == tetriminos[0].nbr)
		return (str);
	if ()
		return (ft_double_test(tab, S, tetriminos);

				return (NULL);
				}

				char	**resolve_recursive(t_misc S, t_tetri *tetriminos)
				{
				char	**str;

				S.a = 0;
				S.b = 0;
				str = ft_tab(S.n);
				str = combination_recursive(tetriminos, S, str); 
				if (str != NULL)
				return (str);
				else
				{
				S.n++;
				ft_freestr(str);
				return (resolve_recursive(S, tetriminos));
				}
				}
