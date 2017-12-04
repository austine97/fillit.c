/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/04 21:33:40 by ybouzgao         ###   ########.fr       */
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

// F: fonction auxiliaire qui va  poser les tetriminos compris entre 0 et x

void	combination_help(t_tetri *tetriminos, char **str, t_misc S)
{
	int k;
	int z;
	int i;
	int j;

	z = 0;
	k = -1;
	i = S.a;
	j = S.b;
	find_next_point(i, j, str);
	while (++k <= S.d) // boucle allant de 0 a la valeur stocker de x.
	{
		while (test_position(tetriminos[k], ++i, ++j, str) == 1 && str[i][j] != 'P')
		{
			while (++j < S.n && str[i][j])
			{
				if (test_position(tetriminos[k], i, j, str) == 0)
				{
					z = 1;
					break ;
				}
			}
			j = -1;
			if (z == 1)
				break ;
		}
		if (test_position(tetriminos[k], i, j, str) == 0 && S.c++)
			str = draw_tetriminos(tetriminos[k], i, j, str);
		else
			break ;
	}
}

// F: fonction recursive qui va essayer toutes les combinaisons de tetriminos

char	***combination_recursive(t_tetri *tetriminos, t_misc S, int x, char **str)
{
	int 	i;
	int 	j;
	int 	k;
	int	z;
	char	**save; //  un **tab qui va sauvegarde le contenu de str a chaque recursivite

	i = 0;
	j = 0;
	z = 0;
	save = NULL;
	save = ft_strcpy_improved(save, str); // cette fonction copie le contenu d'un **tab dans un autre.
	S.c = 0; // variable qui compte le nombre de tetriminos "place".
	S.d = x; // stock la valeur de x avant le debut de la boucle
	k = tetriminos[0].nbr - x;
	while (x < tetriminos[0].nbr)
	{
		find_next_point(i, j, str);
		while ((test_position(tetriminos[x], i, j, str) == 1) && str[i][j] != 'P')
		{
			while (++j < S.n && str[i][j])
			{
				if (test_position(tetriminos[x], i, j, str) == 0)
				{
					z = 1;
					break ;
				}
			}
			i++;
			j = 0;
			if (z == 1)
				break ;
		}
		i = 0;
		if (test_position(tetriminos[x], i, j, str) == 0 && S.c++)
			str = draw_tetriminos(tetriminos[x], i, j, str);
		else
			break ;
		x++;
	}
	if (k != tetriminos[0].nbr && x == tetriminos[0].nbr) // vrai si on a placer tout les tetriminos entre x et tetri.nbr
	{
		S.a = i;
		S.b = j;
		combination_help(tetriminos, str, S);
	}
	if (S.c == tetriminos[0].nbr) // vrai si toutes les pieces sont placer
		S.triple_tab[++S.e] = malloc_copy_tab(S.triple_tab[S.e], S.n, str);
	if (S.e != 0 && x == tetriminos[0].nbr)
	{
		S.triple_tab[++S.e] = NULL;	
		return (S.triple_tab);
	}
	else if (x == tetriminos[0].nbr) // vrai apres avoir essayer toutes les possibilites sans resultats
		return (NULL);
	else
		return (combination_recursive(tetriminos, S, x + 1, save)); // recursivite 
}

// retroune la solution la plus en haut a gauche parmis toute les solutions entre en parametres 

char	**best_solution(char ***Striple_tab, int n)
{
	int i;
	int j;
	int k;
	int *tab;
	char **str;	

	i = -1;													
	str = NULL;
	tab = NULL;
	while (Striple_tab[++i])
	{	
		j = 0;
		k = 0;
		find_next_point(j , k, Striple_tab[i]);
		tab[i] = (j * n) + k;
	}
	i = -1;
	while (Striple_tab[++i + 1])
	{		
		if (tab[i] > tab[i + 1])
			str = Striple_tab[i];	
	}
	return (str);
}

// recursive qui renvoie la solution optimal.

char	**resolve_recursive(t_misc S, int n, int used_points, t_tetri *tetriminos)
{
	int	x;
	char	**str;

	x = 0;
	S.e = -1;
	S.triple_tab = NULL;
	S.n = n;
	str = ft_tab(n, used_points);
	if (used_points <= n * n)
		S.triple_tab = combination_recursive(tetriminos, S, x, str); // tab prend NULL ou la solution optimal.
	else
		n++; // incrementation du carre si trop petit.

	if (S.triple_tab != NULL)
	{
		str = best_solution(S.triple_tab, n);
		return (str);
	}
	else
		return (resolve_recursive(S, n, used_points + n, tetriminos)); // recursive
}
