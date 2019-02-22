/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:43:00 by sbruen            #+#    #+#             */
/*   Updated: 2019/02/20 15:39:53 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

long int			conversion(long int num, t_mods *mods)
{
	if (mods->h == 1)
		return ((short int)num);
	else if (mods->h == 2)
		return ((char)num);
	else if (mods->l == 1)
		return ((long int)num);
	else if (mods->l == 2)
		return ((long long int)num);
	else if (mods->up_l)
		return ((long double)num);
	else if (mods->z)
		return ((size_t)num);
	else if (mods->j)
		return ((intmax_t)num);
	return ((int)num);
}

long int			conversion_o(long int num, t_mods *mods)
{
	if (mods->l == 2)
		return ((unsigned long long int)num);
	else if (mods->l == 1)
		return ((unsigned long int)num);
	else if (mods->h == 2)
		return ((unsigned char)num);
	else if (mods->h == 1)
		return ((unsigned short int)num);
	else if (mods->l == 0)
		return ((unsigned int)num);
	else if (mods->up_l == 1)
		return ((long double)num);
	else if (mods->z == 1)
		return ((size_t)num);
	else if (mods->j == 1)
		return ((uintmax_t)num);
	return ((unsigned int)num);
}

void				printer(t_mods *mods, va_list ap)
{
	long int	l;
	char		*str;

	if (mods->type == 'd' || mods->type == 'i' || mods->type == 'D')
	{
		l = va_arg(ap, long int);
		l = conversion(l, mods);
		mods->count = count_num(l);
		priorities(mods, l);
		if (l == 0 && mods->precision == 0)
			str = ft_strdup("");
		else
			str = ft_itoa(l);
		handle_precision(str, mods, l);
	}
	else if (mods->type == 's' || mods->type == 'S')
		string_starter(ap, mods);
	else if (mods->type == 'c' || mods->type == 'f')
		fc_starter(ap, mods);
	else if (mods->type == 'p' || mods->type == 'o')
		po_starter(ap, mods);
	else if (mods->type == 'x' || mods->type == 'X' ||
			mods->type == 'u' || mods->type == 'U')
		xu_starter(ap, mods);
}
