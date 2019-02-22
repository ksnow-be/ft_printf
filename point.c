/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:53:13 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 16:38:51 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*itoa_check_point(t_mods *mods, size_t point)
{
	char	*res;

	if (point)
		res = ft_itoa_base(point, 16);
	else
	{
		if (mods->precision == -1)
			res = "0";
		else
			res = "";
	}
	return (res);
}

char	*zero_maker_point(t_mods *mods, char *itoa)
{
	char	*zeros;
	char	*res;

	zeros = new_fill_str(mods->precision - ft_strlen(itoa), '0');
	res = ft_strjoin("0x", zeros);
	res = ft_strjoin(res, itoa);
	return (res);
}

char	*space_make_point(t_mods *mods, char *final, char *itoa)
{
	char	*spaces;
	int		i;

	i = 0;
	spaces = new_fill_str(mods->width - ft_strlen(final), ' ');
	if (mods->minus)
		final = ft_strjoin(final, spaces);
	else
	{
		if (mods->zero)
		{
			final = ft_strdup("");
			while (spaces[i])
			{
				spaces[i] = '0';
				i++;
			}
			final = ft_strjoin("0x", spaces);
			final = ft_strjoin(final, itoa);
		}
		else
			final = ft_strjoin(spaces, final);
	}
	return (final);
}

void	point_handle(t_mods *mods, size_t point)
{
	char	*final;
	char	*itoa;

	itoa = itoa_check_point(mods, point);
	final = ft_strjoin("0x", itoa);
	if (mods->precision > ft_strlen(itoa) && mods->precision != -1)
		final = zero_maker_point(mods, itoa);
	if (mods->width > ft_strlen(final))
		final = space_make_point(mods, final, itoa);
	ft_putstr(final);
	g_print_len += ft_strlen(final);
	free(final);
}
