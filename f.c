/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:31:35 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 16:34:42 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		check_universe(double f)
{
	if (f != f)
	{
		ft_putstr("nan");
		g_print_len += ft_strlen("nan");
		return (1);
	}
	if (f == 1.0 / 0.0)
	{
		ft_putstr("inf");
		g_print_len += ft_strlen("inf");
		return (1);
	}
	if (f == -1.0 / 0.0)
	{
		ft_putstr("-inf");
		g_print_len += ft_strlen("-inf");
		return (1);
	}
	return (0);
}

char	*make_split(char *itoa, char *arg)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (itoa[i] != '.')
		i++;
	while (itoa[k])
		k++;
	if (!ft_strcmp(arg, "cel"))
		return (ft_strsub(itoa, 0, i));
	else if (!ft_strcmp(arg, "dot"))
		return (ft_strsub(itoa, i + 1, k));
	return ("Printf is boring as shit");
}

char	*itoa_final_f(t_mods *mods, char *itoa)
{
	if (mods->width > ft_strlen(itoa))
		itoa = make_width_f(mods, itoa);
	else if (mods->width <= ft_strlen(itoa) && mods->plus)
		itoa = ft_strjoin("+", itoa);
	else if (mods->width <= ft_strlen(itoa) && mods->space)
		itoa = ft_strjoin(" ", itoa);
	return (itoa);
}

void	f_handle(t_mods *mods, long double f)
{
	char	*itoa;

	if (check_universe(f))
		return ;
	if ((unsigned long int)f > 9223372036854775807 && f > 0.0)
	{
		itoa = ft_itoa_base_xl(f, 10);
		if ((long int)f < -9223372036854775807)
			itoa = ft_strjoin("-", itoa);
	}
	else
		itoa = ft_itoa(f);
	itoa = ft_strjoin(itoa, ".");
	if (f < 0)
	{
		f = -f;
		mods->isneg = 1;
	}
	if (mods->precision != 0 || mods->precision == 0)
		itoa = itoa_f(mods, f);
	itoa = itoa_final_f(mods, itoa);
	ft_putstr(itoa);
	g_print_len += ft_strlen(itoa);
	free(itoa);
}
