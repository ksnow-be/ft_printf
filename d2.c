/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:01:02 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/19 21:12:26 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*pres(t_tmp *s, t_mods *mods, char *str)
{
	if (mods->precision > mods->count)
		s->tmp_z = new_fill_str(mods->precision - mods->count, '0');
	else
		s->tmp_z = ft_strdup("");
	if (*str == '-')
	{
		s->tmp_z = ft_strjoin("-", s->tmp_z);
		if (mods->width > mods->precision)
			mods->width--;
		str++;
	}
	return (str);
}

char	*width(t_tmp *s, t_mods *mods, char *str)
{
	if (mods->width > mods->precision && mods->width > mods->count)
	{
		if (mods->precision > mods->count)
			s->tmp_sp = new_fill_str(mods->width - mods->precision, ' ');
		else
			s->tmp_sp = new_fill_str(mods->width - mods->count, ' ');
		if (*str == '-')
		{
			if (mods->width > mods->precision)
				*(s->tmp_sp + ft_strlen(s->tmp_sp) - 1) = '-';
			else
				s->tmp_sp = ft_strjoin(s->tmp_sp, "-");
			str++;
		}
	}
	else
		s->tmp_sp = ft_strdup("");
	return (str);
}
