/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:15:31 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 16:36:01 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*zero_precision_f(t_mods *mods, char *itoa, char *cel, char *dot)
{
	int	c;

	if (mods->isneg)
	{
		if (dot[0] >= 53)
		{
			c = ft_atoi(cel);
			c -= 1;
			cel = ft_itoa(c);
		}
	}
	else
	{
		if (dot[0] >= 53)
		{
			c = ft_atoi(cel);
			c += 1;
			cel = ft_itoa(c);
		}
	}
	itoa = ft_strdup(cel);
	return (itoa);
}

char	*itoa_fresh(char *itoa)
{
	char	*res;
	int		i;

	i = 1;
	if (itoa[0] != '-')
		return (itoa);
	res = (char*)malloc(sizeof(char) * (ft_strlen(itoa) - 1));
	while (itoa[i])
	{
		res[i - 1] = itoa[i];
		i++;
	}
	return (res);
}

char	*zero_handle_f(t_mods *mods, char *itoa)
{
	char	*zeros;
	char	*res;

	zeros = new_fill_str(mods->width - ft_strlen(itoa), '0');
	if (mods->isneg)
	{
		res = ft_strjoin(zeros, itoa);
		res[0] = '-';
	}
	if (mods->plus)
	{
		res = ft_strjoin(zeros, itoa);
		res[0] = '+';
	}
	return (res);
}

char	*width_minus_f(char *itoa, t_mods *mods, char *spaces)
{
	if (mods->isneg)
		itoa = ft_strjoin("-", itoa);
	if (mods->plus)
		itoa = ft_strjoin("+", itoa);
	if (mods->space)
		itoa = ft_strjoin(" ", itoa);
	if (mods->isneg || mods->plus)
		spaces = new_fill_str(ft_strlen(spaces) - 1, ' ');
	else
		spaces = new_fill_str(ft_strlen(spaces), ' ');
	itoa = ft_strjoin(itoa, spaces);
	return (itoa);
}

char	*make_width_f(t_mods *mods, char *itoa)
{
	char	*spaces;
	int		i;

	itoa = itoa_fresh(itoa);
	if (mods->zero)
		return (itoa = zero_handle_f(mods, itoa));
	spaces = new_fill_str(mods->width - ft_strlen(itoa), ' ');
	if (mods->minus == 0)
	{
		i = ft_strlen(spaces) - 1;
		if (mods->isneg)
			spaces[i] = '-';
		if (mods->plus)
			spaces[i] = '+';
		itoa = ft_strjoin(spaces, itoa);
	}
	else
		itoa = width_minus_f(itoa, mods, spaces);
	return (itoa);
}
