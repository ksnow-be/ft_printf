/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:36:52 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 16:41:14 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*itoa_check_u(t_mods *mods, unsigned long long int point)
{
	char	*res;

	if (mods->sharp != 0 || mods->precision != -1)
		mods->zero = 0;
	if (point)
		res = ft_itoa_base_xl(point, 10);
	else
	{
		if (mods->precision == -1)
			res = "0";
		else
			res = "";
	}
	return (res);
}

char	*zero_maker_u(t_mods *mods, char *itoa)
{
	char	*zeros;
	char	*res;

	zeros = new_fill_str(mods->precision - ft_strlen(itoa), '0');
	res = ft_strjoin(zeros, itoa);
	mods->sharp = 0;
	return (res);
}

char	*space_maker_u(t_mods *mods, char *final)
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
			while (spaces[i])
			{
				spaces[i] = '0';
				i++;
			}
		}
		final = ft_strjoin(spaces, final);
	}
	return (final);
}

void	u_handle(t_mods *mods, unsigned long long int point)
{
	char	*final;
	char	*itoa;

	itoa = itoa_check_u(mods, point);
	final = ft_strjoin("", itoa);
	if (mods->precision > ft_strlen(itoa) && mods->precision != -1)
		final = zero_maker_u(mods, itoa);
	if (mods->width > ft_strlen(final))
		final = space_maker_u(mods, final);
	ft_putstr(final);
	g_print_len += ft_strlen(final);
	free(final);
}
