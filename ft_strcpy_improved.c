/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_improved.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:11:14 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/19 14:11:33 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_strcpy_improved(char **dest, char **tab, t_misc s)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
		i++;
	if ((dest = malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < s.n)
	{
		j = 0;
		while (j < s.n)
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
