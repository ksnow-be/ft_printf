/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:52:38 by sbruen            #+#    #+#             */
/*   Updated: 2019/02/20 16:17:49 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	init_list(t_mods *mods)
{
	mods->minus = 0;
	mods->plus = 0;
	mods->space = 0;
	mods->sharp = 0;
	mods->zero = 0;
	mods->width = 0;
	mods->precision = -1;
	mods->h = 0;
	mods->l = 0;
	mods->up_l = 0;
	mods->j = 0;
	mods->z = 0;
	mods->count = 0;
	mods->type = 0;
	mods->isneg = 0;
}

void	init_else(t_mods *mods)
{
	mods->precision = 0;
	mods->count = 1;
	mods->plus = 0;
	mods->space = 0;
}

char	*no_zero_skip(char *p, t_mods *mods)
{
	mods->precision = 0;
	return (p);
}

char	*handle_else(char *p, t_mods *mods)
{
	char	*str;

	str = ft_strdup("");
	if (*p)
	{
		str[0] = *p;
		handle_precision(str, mods, 0);
		p++;
	}
	return (p);
}

int		ft_printf(char *p, ...)
{
	va_list	aptr;
	t_mods	*mods;

	mods = (t_mods *)malloc(sizeof(t_mods));
	va_start(aptr, p);
	g_print_len = 0;
	while (*p)
	{
		if (*p == '%')
		{
			init_list(mods);
			p++;
			p = parser(mods, p, aptr);
		}
		else
			print_syms(p);
		if (!*p)
			break ;
		if (*p == '%')
			continue ;
		p++;
	}
	va_end(aptr);
	return (g_print_len);
}
