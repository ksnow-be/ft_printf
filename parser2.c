/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:50:09 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 13:57:34 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		pars_width(char *str, t_mods *mods)
{
	int	i;

	mods->width = ft_atoi(str);
	i = num_counter(mods->width);
	return (i);
}

int		pars_precision(char *str, t_mods *mods)
{
	int	i;

	mods->precision = ft_atoi(str);
	i = num_counter(mods->precision);
	return (i);
}

char	*zero_skip(char *p, t_mods *mods)
{
	while (*p == '0')
		p++;
	return (p += pars_precision(p, mods));
}

char	*print_else(char *p)
{
	while (*p != '%' && *p)
	{
		ft_putchar(*p);
		p++;
		g_print_len++;
	}
	return (p);
}

void	print_syms(char *p)
{
	ft_putchar(*p);
	g_print_len++;
}
