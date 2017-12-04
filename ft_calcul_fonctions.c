/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_fonctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:20:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/04 21:33:53 by ybouzgao         ###   ########.fr       */
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

int		size_square(int nbr_tetriminos, int highest_size, int longest_size)
{
	int n;

	n = ft_sqrt_improved(nbr_tetriminos * 4);
	if (ft_sqrt(nbr_tetriminos * 4) == 0)
		n++;
	if (n < highest_size)
		n = highest_size;
	if (n < longest_size)
		n = longest_size;
	return (n);
}

int		used_points(int highest_size, int n, int nbr_tetriminos)
{
	int used_points;

	used_points = n * highest_size;
	if ((nbr_tetriminos * 4) > used_points)
		used_points = nbr_tetriminos * 4;
	return (used_points);
}

char	**ft_tab(int n, int used_points)
{

	int		i;
	int		j;
	int		k;
	char	**tab;

	i = -1;
	if ((tab = malloc(sizeof(tab) * (n + 1))) == 0)
		return (NULL);
	while (++i < n)
	{
		if ((tab[i] = malloc(sizeof(tab) * (n + 1))) == 0)
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
			while (++k < (n * n) && tab[i][++j])
				tab[i][j] = 'P';
		}
		j = -1;
		ft_putstr(tab[i]);
		ft_putchar('\n');
	}
	return (tab);
}

char	**malloc_copy_tab(char **tab, int n, char **str)
{
	int i;
	int j;

	if ((tab = malloc(sizeof(tab) * (n + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		if ((tab[i] = malloc(sizeof(tab) * (n + 1))) == NULL)
			return (NULL);
	}
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			tab[i][j] = str[i][j];
	}
	return (tab);
}
