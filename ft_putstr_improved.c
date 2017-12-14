/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_improved.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:41:52 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/14 18:30:23 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putstre(char const *c, int n)
{
	int i;

	i = 0;
	while(c[i] && i < n)
	{
		if (c[i] != 'e' && i < n)
			ft_putchar(c[i]);
		i++;
	}
}

void	ft_putstr_improved(char **pdt, int n)
{
	int i;

	i = -1;
	while (pdt[++i] && i < n)
	{
		ft_putstre(pdt[i], n);
		ft_putchar('\n');
	}
}
