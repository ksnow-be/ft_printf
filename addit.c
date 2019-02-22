/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:53:28 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/19 21:31:14 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		num_counter(long int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int		my_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int		count_num(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*new_fill_str(size_t size, char c)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	ft_memset(str, c, size);
	return (str);
}

int		biggest_num(int w, int p, int n)
{
	if (p >= w && p >= n)
		return (p);
	if (w >= p && w >= n)
		return (w);
	return (n);
}
