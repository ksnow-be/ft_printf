/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:45:25 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/20 16:29:48 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*jew_stuff(int am, char *dst)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(sizeof(char) * am + 1);
	while (i < am)
	{
		res[i] = dst[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*zero_change(char *final)
{
	int	i;

	i = 0;
	while (final[i])
	{
		if (final[i] == ' ')
			final[i] = '0';
		i++;
	}
	return (final);
}

void	string_handle(t_mods *mods, char *ss)
{
	char	*final;
	char	*prec;
	char	*spaces;

	final = ft_strdup(ss);
	if (mods->precision < ft_strlen(final) && mods->precision != -1)
	{
		prec = jew_stuff(mods->precision, ss);
		final = prec;
	}
	if (mods->width > ft_strlen(final))
	{
		spaces = new_fill_str(mods->width - ft_strlen(final), ' ');
		if (mods->minus == 0)
			final = ft_strjoin(spaces, final);
		else
			final = ft_strjoin(final, spaces);
	}
	if (mods->zero)
		final = zero_change(final);
	ft_putstr(final);
	g_print_len += ft_strlen(final);
	free(final);
}

char	*char_1(t_mods *mods, int c)
{
	int		i;
	char	*spaces;

	spaces = new_fill_str(mods->width - 1, ' ');
	if (mods->minus)
	{
		ft_putchar(c);
		ft_putstr(spaces);
	}
	else
	{
		if (mods->zero)
		{
			i = 0;
			while (spaces[i])
			{
				spaces[i] = '0';
				i++;
			}
		}
		ft_putstr(spaces);
		ft_putchar(c);
	}
	return (spaces);
}

void	char_handle(t_mods *mods, int c)
{
	char	*spaces;
	int		i;

	spaces = ft_strdup("");
	if (mods->width > 1)
		spaces = char_1(mods, c);
	if (mods->width < 2)
	{
		if (mods->zero)
		{
			i = 0;
			while (spaces[i])
			{
				spaces[i] = '0';
				i++;
			}
			ft_putstr(spaces);
			ft_putchar(c);
		}
		else
			ft_putchar(c);
	}
	g_print_len += ft_strlen(spaces) + 1;
}
