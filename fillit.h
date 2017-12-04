/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:35:43 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/04 20:31:55 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define BUF_SIZE 600

typedef	struct	s_tetri
{
	char	coord[3];
	int		nbr;
	int		length;
	int		height;
}				t_tetri;

typedef struct s_misc
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;
	int		n;
	char	***triple_tab;
}				t_misc;

int			ft_checks(int t2, int t3, char *b);
int			check_valid(int a, char **c);
int			ft_count_l(char **pdt, int highest);
t_tetri		*ft_ret_tet(char *buf, int ret);
int			ft_find_longest(char **p);
char		**ft_create_table(char *buf, int ret);
int			ft_find_highest(char **pdt);



int			ft_sqrt_improved(int nb);
int			size_square(int nbr_tetriminos, int highest_size, int longest_size);
int			used_points(int highest_size, int n, int nbr_tetriminos);
char		**ft_tab(int n, int used_points);
char		**malloc_copy_tab(char **tab, int n, char **str);
void		find_next_point(int i, int j, char **tab);
int			test_position(t_tetri tetriminos, int i, int j, char **tab);
char		**draw_tetriminos(t_tetri tetriminos, int i, int j, char **tab);
char		**ft_strcpy_improved(char **dest, char **tab);
void		combination_help(t_tetri *tetriminos, char **str, t_misc S);
char		***combination_recursive(t_tetri *tetriminos, t_misc S, int x, char **str);
char		**best_solution(char ***Striple_tab, int n);
char		**resolve_recursive(t_misc S, int n, int used_points, t_tetri *tetriminos);
void		ft_putstr_improved(char **pdt);

#endif
