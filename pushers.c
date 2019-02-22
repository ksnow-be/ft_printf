/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:57:09 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/19 21:42:26 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	po_starter(va_list ap, t_mods *mods)
{
	size_t	point;

	if (mods->type == 'p')
	{
		point = va_arg(ap, size_t);
		point_prior(mods);
		point_handle(mods, point);
	}
	else if (mods->type == 'o')
	{
		point = va_arg(ap, size_t);
		point = conversion_o(point, mods);
		o_prior(mods, point);
		o_handle(mods, point);
	}
}

void	xu_starter(va_list ap, t_mods *mods)
{
	unsigned long long int	k;

	if (mods->type == 'x' || mods->type == 'X')
	{
		k = va_arg(ap, unsigned long long int);
		k = conversion_o(k, mods);
		xx_handle(mods, (void*)k);
	}
	else if (mods->type == 'u' || mods->type == 'U')
	{
		k = va_arg(ap, unsigned long long int);
		if (mods->type == 'U')
			mods->l = 1;
		k = conversion_o(k, mods);
		u_handle(mods, k);
	}
}

void	string_starter(va_list ap, t_mods *mods)
{
	char	*ss;

	if (mods->type == 's' || mods->type == 'S')
	{
		ss = va_arg(ap, char*);
		if (!ss)
			ss = "(null)";
		string_prior(mods);
		string_handle(mods, ss);
	}
}

void	fc_starter(va_list ap, t_mods *mods)
{
	double	f;
	int		c;

	if (mods->type == 'c')
	{
		c = va_arg(ap, int);
		if (!c)
			c = (int)NULL;
		string_prior(mods);
		char_handle(mods, c);
	}
	else if (mods->type == 'f')
	{
		f = va_arg(ap, double);
		if (mods->up_l)
			f = (long double)f;
		f_prior(mods, f);
		f_handle(mods, f);
	}
}

char	*new_strcpy(char *dst, char *src)
{
	char	*ptr;

	ptr = src;
	while (*src)
		*dst++ = *src++;
	return (ptr);
}
