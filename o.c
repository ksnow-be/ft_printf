/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:01:59 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 16:37:52 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*itoa_check_o(t_mods *mods, size_t point)
{
	char	*res;

	if (point)
		res = ft_itoa_base_xl(point, 8);
	else
	{
		if (mods->precision == -1)
			res = "0";
		else
			res = "";
		if (mods->precision == -1)
			mods->sharp = 0;
	}
	return (res);
}

char	*zero_maker_o(char *itoa, t_mods *mods)
{
	char	*zeros;
	char	*res;

	zeros = new_fill_str(mods->precision - ft_strlen(itoa), '0');
	res = ft_strjoin(zeros, itoa);
	mods->sharp = 0;
	return (res);
}

char	*space_maker_o(char *final, t_mods *mods)
{
	char	*spaces;
	char	*res;
	int		i;

	i = 0;
	spaces = new_fill_str(mods->width - ft_strlen(final), ' ');
	if (mods->minus)
		res = ft_strjoin(final, spaces);
	else
	{
		if (mods->zero && mods->precision == -1)
		{
			while (spaces[i])
			{
				spaces[i] = '0';
				i++;
			}
		}
		res = ft_strjoin(spaces, final);
	}
	return (res);
}

void	o_handle(t_mods *mods, size_t point)
{
	char	*final;
	char	*itoa;

	itoa = itoa_check_o(mods, point);
	final = ft_strjoin("", itoa);
	if (mods->precision > ft_strlen(itoa) && mods->precision != -1)
		final = zero_maker_o(itoa, mods);
	if (mods->sharp)
		final = ft_strjoin("0", itoa);
	if (mods->width > ft_strlen(final))
		final = space_maker_o(final, mods);
	ft_putstr(final);
	g_print_len += ft_strlen(final);
	free(final);
}
