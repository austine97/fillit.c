/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/29 13:38:13 by ybouzgao         ###   ########.fr       */
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
	k = 0;
	while (tab[++i])
	{
		while (k < used_points && tab[i][++j])
		{
			tab[i][j] = '.';
			k++;
		}
		j = 0;
	}
	return (tab);
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
		while (tab[i][j] == '.')
		{
			i = 0;
			j = 0;
			k = 0;
			x++;
			while (tab[i][j] != '.' && tab[i + 1][j + 1])
				j++;
			if (tab[i][j] != '.')
			{
				i++;
				j = 0;
			}
			y = 0;
			while (k != 3 && tab[i][j] == '.') /*poser le premier tetriminos*/
			{
				tab[i][j] = '#';
				y++;
				if (tetriminos[x]->coord[k] == 'R' && tab[i][j])
					j++;
				if (tetriminos[x]->coord[k] == 'L' && tab[i][j])
					j--;
				if (tetriminos[x]->coord[k] == 'D' && tab[i][j])
					i++;
				k++;
			}
			if (y != 4)
				
			
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

