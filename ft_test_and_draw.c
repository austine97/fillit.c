/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_and_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:53:28 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/11 20:45:42 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	find_next_point(int i, int j, char **tab)
{
	if (!tab[i][j])
	{
		i++;
		j = 0;
	}
	while (tab[i][j] && tab[i][j] != '.')
	{
		while (tab[i + 1][j + 1] && tab[i][j] != '.')
			j++;
		if (tab[i][j] != '.')
		{
			i++;
			j = 0;
		}
	} 
}

// fonction qui test si un tetriminos peut etre placer dans le tableau

int		test_position(t_tetri tetriminos, int i, int j, char **tab)
{
	int		count;
	int		k;
	int		m;
	int		n;

	k = 0;
	m = i;
	n = j;
	count = 0;
	while (count <= 3 && tab[m][n])
	{
		if (tab[m][n] == '.')
			count++;
		else
			break ;
		if (k <= 2)
		{
			if (tetriminos.coord[k] == 'R' && tab[m][n])
				n++;
			if (tetriminos.coord[k] == 'D' && tab[m][n])
				m++;
			if (tetriminos.coord[k] == 'L' && tab[m][n])
				n--;
			if (tetriminos.coord[k] == 'Z' && tab[m][n])
			{
				m++;
				n--;
			}
			if (tetriminos.coord[k] == 'X' && tab[m][n])
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

// place le tetriminos dans le tableau **tab.

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
			if (tetriminos.coord[k] == 'R' && tab[m][n])
				n++;
			if (tetriminos.coord[k] == 'D' && tab[m][n])
				m++;
			if (tetriminos.coord[k] == 'L' && tab[m][n])
				n--;
			if (tetriminos.coord[k] == 'Z' && tab[m][n])
			{
				m++;
				n--;
			}
			if (tetriminos.coord[k] == 'X' && tab[m][n])
			{
				m++;
				n++;
			}
		}
		k++;
	}
	return (tab);
}
