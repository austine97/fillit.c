/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:35:43 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/11/29 20:49:29 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

typedef	struct	s_tetri
{
	char	coord[3];
	int		length;
	int		height;
}				t_tetri;

typedef struct s_list
{
	int a;
	int b;
	int c;
	int d;
}				t_list;

#endif
