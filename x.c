/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 21:10:00 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 16:41:28 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*itoa_check_x(t_mods *mods, void *point)
{
	char	*res;

	if (mods->precision != -1 || mods->minus == 1)
		mods->zero = 0;
	if (point)
		res = ft_itoa_base_xl((unsigned long long int)point, 16);
	else
	{
		if (mods->precision == -1)
			res = "0";
		else
			res = "";
	}
	return (res);
}

char	*zero_maker_x(t_mods *mods, char *itoa, void *point)
{
	char	*res;
	char	*zeros;

	zeros = new_fill_str(mods->precision - ft_strlen(itoa), '0');
	if (mods->sharp && point)
	{
		res = ft_strjoin("0x", zeros);
		res = ft_strjoin(res, itoa);
	}
	else
		res = ft_strjoin(zeros, itoa);
	return (res);
}

char	*spaces_make_x(t_mods *mods, char *final, void *point, char *itoa)
{
	char	*spaces;

	spaces = new_fill_str(mods->width - ft_strlen(final), ' ');
	if (mods->minus)
		final = ft_strjoin(final, spaces);
	else
	{
		if (mods->zero)
		{
			spaces = new_fill_str(ft_strlen(spaces), '0');
			if (mods->sharp && point)
				final = ft_strjoin("0x", spaces);
			else
				final = ft_strdup(spaces);
			final = ft_strjoin(final, itoa);
		}
		else
			final = ft_strjoin(spaces, final);
	}
	return (final);
}

void	xx_handle(t_mods *mods, void *point)
{
	char	*final;
	char	*itoa;
	int		i;

	i = 0;
	itoa = itoa_check_x(mods, point);
	final = ft_strjoin("", itoa);
	if (mods->sharp && point)
		final = ft_strjoin("0x", itoa);
	if (mods->precision > ft_strlen(itoa) && mods->precision != -1)
		final = zero_maker_x(mods, itoa, point);
	if (mods->width > ft_strlen(final))
		final = spaces_make_x(mods, final, point, itoa);
	if (mods->type == 'X')
		final = ft_toupper(final);
	ft_putstr(final);
	g_print_len += ft_strlen(final);
	free(final);
}
