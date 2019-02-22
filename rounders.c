/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounders.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:14:18 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/19 20:52:50 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*round_cel(char *cel)
{
	int	i;

	i = ft_atoi(cel);
	if (cel[0] == '-')
		i -= 1;
	else
		i += 1;
	return (ft_itoa(i));
}

char	*make_round(char *cel, char *dot)
{
	int	i;

	i = ft_strlen(dot) - 1;
	if (dot[i] >= 53)
	{
		dot[i] = '\0';
		i--;
		if (dot[i] < 57)
			dot[i] += 1;
		else if (dot[i] == 57)
		{
			while (dot[i] == 57)
			{
				dot[i] = '0';
				i--;
			}
			dot[i] += 1;
			if (i == -1)
				cel = round_cel(cel);
		}
	}
	else
		dot[i] = '\0';
	return (ft_strjoin(ft_strjoin(cel, "."), dot));
}

char	*rounder(char *itoa, t_mods *mods)
{
	char	*cel;
	char	*dot;

	cel = make_split(itoa, "cel");
	dot = make_split(itoa, "dot");
	if (mods->precision == 0)
	{
		itoa = zero_precision_f(mods, itoa, cel, dot);
		return (itoa);
	}
	itoa = make_round(cel, dot);
	return (itoa);
}
