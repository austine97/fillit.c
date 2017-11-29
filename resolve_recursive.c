/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/29 16:59:30 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt_improved(int nb)
{
	int a;

	a = 0;
	while ((a * a) <= nb)
	{
		if (a * a <= nb && ((a + 1) * (a + 1)) > nb)
			break ;
		a++;
	}
	return (a);
}

int		used_points(int highest_size, int nbr_highest_size, int n, int nbr_tetriminos)
{
	int used_points;

	used_points = n * (highest_size - 1) + nbr_highest_size;
	if ((nbr_tetriminos * 4) > used_points)
		used_points = nbr_tetriminos * 4;
	return (used_points);
}

int		size_square(int nbr_tetriminos, int highest_size, int longuest_size)
{
	int n;

	n = ft_sqrt_improved(nbr_tetriminos * 4);
	if (ft_sqrt(nbr_tetriminos * 4) == 0)
		n++;
	if (n < highest_size)
		n = highest size;
	if (n < longuest_size)
		n = longuest_size;
	return (n);
}

char	**tab(int n, int used_points)
{

	int		i;
	int		j;
	int		k;
	char	**tab;

	i = -1;
	if (tab = (char**)malloc(sizeof(tab) * (n + 1)) == 0)
		return (NULL);
	while (++i < n)
	{
		if (tab[i] = (char**)malloc(sizeof(tab) * (n + 1)) == 0)
			return (NULL);
	}
	i = -1;
	j = -1;
	k = -1;
	while (tab[++i])
	{
		while (++k < used_points && tab[i][++j])
			tab[i][j] = '.';
		if (k >= used_points)
		{
			k--;
			while (++k < (n * n - usedpoints) && tab[i][++j])
				tab[i][j] = 'P';
		}
		j = 0;
	}
	return (tab);
}

int		test_position(t_tetri tetriminos, int i, int j, char **tab)
{
	int		count;
	int		k;
	int		m;
	int		n;

	k = 0;
	m = i;
	n = j;
	count = -1;.
		while (++count <= 3 && tab[m][n])
		{
			if (tab[m][n] == '.')
				count++;
			else
				break ;
			if (k <= 2)
			{
				if (tetriminos->coord[k] == 'R' && tab[m][n])
					n++;
				if (tetriminos->coord[k] == 'D' && tab[m][n])
					m++;
				if (tetriminos->coord[k] == 'Z' && tab[m][n])
				{
					m++;
					n--;
				}
				if (tetriminos->coord[k] == 'X' && tab[m][n])
				{
					m++;
					n++;
				}
				k++;
			}
		}
	if (count == 4)
		return (0);
	else
		return (1);
}

char	**draw_tetriminos(t_tetri tetriminos, int i, int j, char **tab)
{
	int k;
	int m;
	int n;

	m = i;
	n = j;
	k = 0;
	while (k <= 3)
	{
		tab[m][n] = '#';
		if (k <= 2)
		{
			if (tetriminos->coord[k] == 'R' && tab[m][n])
				n++;
			if (tetriminos->coord[k] == 'D' && tab[m][n])
				m++;
			if (tetriminos->coord[k] == 'Z' && tab[m][n])
			{
				m++;
				n--;
			}
			if (tetriminos->coord[k] == 'X' && tab[m][n])
			{
				m++;
				n++;
			}
		}
		k++;
	}
	return (tab);
}

void	find_next_point(int i, int j, char **tab)
{
	while (tab[i][j] != '.' && tab[i][j])
	{
		while (tab[i][j] != '.' && tab[i + 1][j + 1])
			j++;
		if (tab[i][j] != '.')
		{
			i++;
			j = 0;
		}
	} // avance jusqua rencontrer un espace non utiliser
	i--;
	j--;
}

char	**resolve_recursive(char **tab, int n, int used_points, t_tetri *tetriminos)
{
	int i;
	int j;
	int k;
	int x;
	int y;

	x = -1;
	if (used_points <= n * n)
	{
		while (tab[i][j])
		{
			i = 0;
			j = 0;
			k = 0;
			x++;
			find_next_point(i, j, tab); // avance jusqua rencontrer un espace non utiliser 
			while (test_position(tetriminos[x], ++i, ++j, tab) == 1 && tab[i][j] != 'P')
			{
				while (++j < n && tab[i][j])
				{
					if (test_position(tetriminos[x], i, j, tab) == 0)
						break ;
				}
				j = -1;
			}
			if (test_position(tetriminos[x], i, j, tab) == 0)
				tab = draw_tetriminos(tetriminos[x], i, j, tab);
		}
	}
	else
		n++;
	ft_strdel(tab);
	return (resolve_recursive(tab(n, used_points + 1), n, used_point + 1, tetriminos);
			}

			int		main(void)
			{
			ft_putnbr(ft_sqrt_improved(26));
			return (0);
			}

