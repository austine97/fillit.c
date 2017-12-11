/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_fonctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:20:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/11 20:57:16 by ybouzgao         ###   ########.fr       */
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
	ft_putnbr(highest_size);
	ft_putchar('\n');
	ft_putnbr(used_points);
	ft_putchar('\n');
	ft_putnbr(nbr_tetriminos);
	ft_putchar('\n');
	return (used_points);
}
char	*ft_tab_improved(int n, int used_points)
{
	int i;
	int j;
	int k;
	char	*buf;

	i =  1;
	j = 0;
	k = 1;
	buf = ft_strnew(n * n + n + 3);
	while (i < n * n + n + 1)
	{
		if (i != 0 && i % (n + j) == 0)
		{
			buf[i - 1] = '\n';
			k++;
		}
		else if (i < used_points + k)
			buf[i - 1] = '.';
		else
			buf[i - 1] = 'P';
		j = 1;
		i++;
	}
	return (buf);
}

char **ft_tab(int n, int used_points)
{ 	
	char *buf;
	char **tab;

	buf = ft_tab_improved(n, used_points);
	tab = ft_strsplit(buf, '\n');
	return (tab);
}

char	**malloc_copy_tab(int n, char **str)
{
	int		i;
	int		j;
	char	**tab;

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
