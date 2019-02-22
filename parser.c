/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:44:06 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 16:16:47 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*pars_else(char *p, t_mods *mods)
{
	priorities(mods, 1);
	init_else(mods);
	p = handle_else(p, mods);
	p = print_else(p);
	return (p);
}

char	*parser(t_mods *mods, char *p, va_list ap)
{
	while (*p)
	{
		if (pars_simple(p, mods))
			p++;
		else if (ft_isdigit(*p))
			p += pars_width(p, mods);
		else if (*p == '.')
		{
			p++;
			p = ft_isdigit(*p) ? (zero_skip(p, mods)) : (no_zero_skip(p, mods));
		}
		else if (my_strchr("diuUoxXfFeEgGaAcsSpn", *p))
		{
			mods->type = *p;
			printer(mods, ap);
			break ;
		}
		else
		{
			p = pars_else(p, mods);
			break ;
		}
	}
	return (p);
}

int		pars_simple(char *p, t_mods *mods)
{
	if (my_strchr("-+ #", *p))
	{
		pars_flags(p, mods);
		return (1);
	}
	else if (*p == '0')
	{
		mods->zero = 1;
		return (1);
	}
	else if (*p == 'h' || *p == 'l' || *p == 'L' || *p == 'z' || *p == 'j')
	{
		pars_length(p, mods);
		return (1);
	}
	return (0);
}

void	pars_flags(char *str, t_mods *mods)
{
	if (*str == '-')
		mods->minus = 1;
	else if (*str == '+')
		mods->plus = 1;
	else if (*str == ' ')
		mods->space = 1;
	else if (*str == '#')
		mods->sharp = 1;
	else if (*str == '0')
		mods->zero = 1;
}

void	pars_length(char *str, t_mods *mods)
{
	if (*str == 'z')
		init_z(mods);
	if (*str == 'j')
		init_j(mods);
	if (*str == 'h')
		init_h(mods);
	if (*str == 'l')
		init_l(mods);
	if (*str == 'L')
		init_up_l(mods);
}
