/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:29:22 by sbruen            #+#    #+#             */
/*   Updated: 2019/02/20 16:18:03 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include "libft/libft.h"

size_t			g_print_len;

typedef struct	s_mods
{
	int			minus;
	int			plus;
	int			space;
	int			sharp;
	int			zero;
	int			width;
	int			precision;
	int			h;
	int			j;
	int			z;
	int			l;
	int			up_l;
	int			count;
	int			isneg;
	char		type;
}				t_mods;

typedef struct	s_tmp
{
	char		*tmp_sp;
	char		*tmp_z;
	char		*final;
}				t_tmp;

int				ft_printf(char *p, ...);
int				num_counter(long int num);
int				pars_width(char *str, t_mods *mods);
int				pars_precision(char *str, t_mods *mods);
int				my_strchr(char *s, char c);
int				pars_simple(char *p, t_mods *mods);
int				count_num(long int n);
int				biggest_num(int w, int p, int n);
int				check_universe(double f);

long int		conversion(long int num, t_mods *mods);
long int		conversion_o(long int num, t_mods *mods);

size_t			ft_nbr_len(size_t nb, int base);

void			init_list(t_mods *mods);
void			pars_length(char *str, t_mods *mods);
void			print_syms(char *p);
void			pars_flags(char *str, t_mods *mods);
void			pars_length(char *str, t_mods *mods);
void			priorities(t_mods *mods, long int num);
void			init_else(t_mods *mods);
void			init_z(t_mods *mods);
void			init_j(t_mods *mods);
void			init_h(t_mods *mods);
void			init_l(t_mods *mods);
void			init_up_l(t_mods *mods);
void			po_starter(va_list ap, t_mods *mods);
void			xu_starter(va_list ap, t_mods *mods);
void			string_starter(va_list ap, t_mods *mods);
void			fc_starter(va_list ap, t_mods *mods);
void			printer(t_mods *mods, va_list ap);
void			zero(t_tmp *s, t_mods *mods);
void			space(t_tmp *s, t_mods *mods);
void			minus(t_tmp *s, t_mods *mods, char *str);
void			handle_precision(char *str, t_mods *mods, long int l);
void			xx_handle(t_mods *mods, void *point);
void			u_handle(t_mods *mods, unsigned long long int point);
void			o_prior(t_mods *mods, size_t point);
void			o_handle(t_mods *mods, size_t point);
void			string_handle(t_mods *mods, char *ss);
void			char_handle(t_mods *mods, int c);
void			point_handle(t_mods *mods, size_t point);
void			f_handle(t_mods *mods, long double f);
void			f_prior(t_mods *mods, double f);
void			ft_putnbr(int nb);

char			*handle_else(char *p, t_mods *mods);
char			*print_else(char *p);
char			*pars_else(char *p, t_mods *mods);
char			*parser(t_mods *mods, char *p, va_list ap);
char			*no_zero_skip(char *p, t_mods *mods);
char			*zero_skip(char *p, t_mods *mods);
char			*pres(t_tmp *s, t_mods *mods, char *str);
char			*width(t_tmp *s, t_mods *mods, char *str);
char			*ft_itoa_base_x(unsigned int value, int base);
char			*ft_itoa_base_xl(unsigned long long value, int base);
char			*itoa_f(t_mods *mods, double f);
char			*ft_itoa_base(long long value, int base);
char			*plus(t_tmp *s, t_mods *mods, char *str, long int l);
char			*new_fill_str(size_t size, char c);
char			*new_strcpy(char *dst, char *src);
char			*itoa_check_x(t_mods *mods, void *point);
char			*zero_maker_x(t_mods *mods, char *itoa, void *point);
char			*spaces_make_x(t_mods *mods, char *final,
		void *point, char *itoa);
char			*itoa_check_u(t_mods *mods, unsigned long long int point);
char			*zero_maker_u(t_mods *mods, char *itoa);
char			*space_maker_u(t_mods *mods, char *final);
char			*itoa_check_o(t_mods *mods, size_t point);
char			*zero_maker_o(char *itoa, t_mods *mods);
char			*space_maker_o(char *final, t_mods *mods);
char			*jew_stuff(int am, char *dst);
char			*zero_change(char *final);
char			*char_1(t_mods *mods, int c);
char			*itoa_check_point(t_mods *mods, size_t point);
char			*zero_maker_point(t_mods *mods, char *itoa);
char			*space_make_point(t_mods *mods, char *final, char *itoa);
char			*itoa_fresh(char *itoa);
char			*width_minus_f(char *itoa, t_mods *mods, char *spaces);
char			*make_width_f(t_mods *mods, char *itoa);
char			*itoa_final_f(t_mods *mods, char *itoa);
char			*round_cel(char *cel);
char			*make_round(char *cel, char *dot);
char			*rounder(char *itoa, t_mods *mods);
char			*zero_precision_f(t_mods *mods, char *itoa,
		char *cel, char *dot);
char			*zero_handle_f(t_mods *mods, char *itoa);
char			*make_split(char *itoa, char *arg);

void			string_prior(t_mods *mods);
void			point_prior(t_mods *mods);

#endif
