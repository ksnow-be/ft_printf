/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:10:30 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 13:33:22 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_itoa_base_x(unsigned int value, int base)
{
	int		len;
	char	*radix;
	char	*result;

	radix = "0123456789abcdef";
	if (value == 0)
		return (ft_strdup("0"));
	len = ft_nbr_len(value, base);
	result = (char*)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	if (!value)
		value *= -1;
	while (len > 0)
	{
		result[len - 1] = radix[value % base];
		value /= base;
		len--;
	}
	return (result);
}

char	*ft_itoa_base_xl(unsigned long long value, int base)
{
	int		len;
	char	*radix;
	char	*result;

	radix = "0123456789abcdef";
	if (value == 0)
		return (ft_strdup("0"));
	len = ft_nbr_len(value, base);
	result = (char*)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	if (!value)
		value *= -1;
	while (len > 0)
	{
		result[len - 1] = radix[value % base];
		value /= base;
		len--;
	}
	return (result);
}

char	*ft_itoa_base(long long value, int base)
{
	int		len;
	char	*radix;
	char	*result;

	radix = "0123456789abcdef";
	if (value == 0)
		return (ft_strdup("0"));
	len = ft_nbr_len(value, base);
	result = (char*)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	if (!value)
		value *= -1;
	while (len > 0)
	{
		result[len - 1] = radix[value % base];
		value /= base;
		len--;
	}
	return (result);
}

char	*itoa_f(t_mods *mods, double f)
{
	long double		dot;
	int				i;
	char			*itoa;
	char			*lil;

	i = 0;
	dot = f - (int)f;
	while (i <= mods->precision)
	{
		dot *= 10;
		lil = ft_itoa_base_xl((unsigned long long int)dot, 10);
		dot = dot - (int)dot;
		itoa = ft_strjoin(itoa, lil);
		if (i == mods->precision)
			itoa = rounder(itoa, mods);
		free(lil);
		i++;
	}
	return (itoa);
}

size_t	ft_nbr_len(size_t nb, int base)
{
	size_t	i;

	i = 0;
	if (!nb)
		nb *= -1;
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}
