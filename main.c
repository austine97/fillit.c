/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:53:35 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/20 13:18:22 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

static int	empty(void)
{
	ft_putstr("error\n");
	return (-1);
}

int			main(int argc, char **argv)
{
	char	buf[BUF_SIZE + 1];
	char	**pdt;
	int		i;
	t_tetri *listtetri;
	t_misc	s;

	s.d = 0;
	i = open(argv[1], O_RDONLY);
	if ((s.b = read(i, buf, BUF_SIZE)) == -1)
		return (empty());
	buf[s.b] = '\0';
	if ((pdt = ft_create_table(buf, s.b)) == 0)
		return (0);
	if (check_valid(argc, argv) == 1)
		return (1);
	listtetri = ft_ret_tet(buf, s.b);
	s.b = ft_find_longest(pdt);
	s.a = ft_find_highest(pdt);
	s.n = size_square(listtetri[0].nbr, s.a, s.b);
	pdt = resolve_recursive(s, listtetri);
	ft_putstr_improved(pdt, s.n + 1);
	close(i);
	return (0);
}
