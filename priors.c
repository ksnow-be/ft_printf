/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:06:18 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 13:21:26 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	o_prior(t_mods *mods, size_t point)
{
	if (point)
	{
		if (mods->sharp == 0 && mods->precision != -1)
			mods->zero = 0;
		else if (mods->sharp == 1 && mods->precision != 1 && mods->zero == 1)
			mods->zero = 1;
	}
}

void	priorities(t_mods *mods, long int num)
{
	if (mods->space)
		if (mods->plus || num < 0)
			mods->space = 0;
	if (mods->zero)
		if (mods->minus || mods->precision >= 0)
			mods->zero = 0;
	if (num == 0 && mods->precision == 0)
	{
		mods->zero = 0;
		mods->count = 0;
	}
}

void	point_prior(t_mods *mods)
{
	if (mods->minus == 1 || mods->precision != -1)
		mods->zero = 0;
}

void	f_prior(t_mods *mods, double f)
{
	if (mods->precision == -1)
		mods->precision = 6;
	if (mods->plus)
		mods->space = 0;
	if (f < 0.0)
	{
		mods->space = 0;
		mods->plus = 0;
	}
	if (mods->minus)
	{
		mods->zero = 0;
		if (mods->space)
			if (f < 0.0)
				mods->space = 0;
	}
}

void	string_prior(t_mods *mods)
{
	if (mods->minus && mods->zero)
		mods->zero = 0;
}
