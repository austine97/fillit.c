/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:53:35 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/04 21:06:26 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**pdt;
	int		n;
	int		used_point;
	t_tetri *listtetri;
	t_misc	S;

	S.a = 0;
	S.b = 0;
	S.c = 0;
	S.d = 0;
	S.e = -1;
	S.triple_tab = NULL;
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if ((pdt = ft_create_table(buf, ret)) == 0)
		return (0);
	check_valid(argc, argv);
	listtetri = ft_ret_tet(buf, ret);
	ret = ft_find_longest(pdt);
	fd = ft_find_highest(pdt);
	n = size_square(listtetri[0].nbr, fd, ret);
	used_point = used_points(fd, n, ret);
	pdt = resolve_recursive(S , n, used_point, listtetri);
	ft_putstr_improved(pdt);
	return (0);
}
