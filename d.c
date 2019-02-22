/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:59:20 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 16:56:38 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	zero(t_tmp *s, t_mods *mods)
{
	if (mods->zero)
		if (mods->width > mods->precision && mods->width > mods->count)
			s->tmp_sp = (char *)ft_memset((char *)s->tmp_sp,
					48, ft_strlen(s->tmp_sp));
}

char	*plus(t_tmp *s, t_mods *mods, char *str, long int l)
{
	if (mods->plus && l >= 0)
	{
		if (mods->width > mods->precision && mods->width > mods->count)
		{
			if (mods->minus)
			{
				s->tmp_z = ft_strjoin("+", s->tmp_z);
				*(s->tmp_sp + ft_strlen(s->tmp_sp) - 1) = '\0';
			}
			else
			{
				if (mods->zero)
					*s->tmp_sp = '+';
				else
					*(s->tmp_sp + ft_strlen(s->tmp_sp) - 1) = '+';
			}
		}
		else if (mods->precision >= mods->width
				&& mods->precision > mods->count)
			s->tmp_z = ft_strjoin("+", s->tmp_z);
		else
			str = ft_strjoin("+", str);
	}
	return (str);
}

void	space(t_tmp *s, t_mods *mods)
{
	if (mods->space)
	{
		if (mods->precision > mods->width && mods->precision > mods->count)
			s->tmp_z = ft_strjoin(" ", s->tmp_z);
		else if (mods->width > mods->precision
				&& mods->width > mods->count && mods->minus)
		{
			s->tmp_z = ft_strjoin(" ", s->tmp_z);
			*(s->tmp_sp + ft_strlen(s->tmp_sp) - 1) = '\0';
		}
		else
			*s->tmp_sp = ' ';
	}
}

void	minus(t_tmp *s, t_mods *mods, char *str)
{
	if (mods->zero)
	{
		s->final = ft_strjoin(s->tmp_z, s->tmp_sp);
		s->final = ft_strjoin(s->final, str);
	}
	else
	{
		s->final = ft_strjoin(s->tmp_z, str);
		if (mods->minus && mods->width > mods->count &&
				mods->width > mods->precision)
			s->final = ft_strjoin(s->final, s->tmp_sp);
		else
			s->final = ft_strjoin(s->tmp_sp, s->final);
	}
}

void	handle_precision(char *str, t_mods *mods, long int l)
{
	t_tmp	*s;

	s = (t_tmp *)malloc(sizeof(t_tmp));
	str = pres(s, mods, str);
	str = width(s, mods, str);
	zero(s, mods);
	str = plus(s, mods, str, l);
	space(s, mods);
	minus(s, mods, str);
	ft_putstr(s->final);
	g_print_len += ft_strlen(s->final);
}
