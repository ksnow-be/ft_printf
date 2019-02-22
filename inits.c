/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:52:19 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/02/19 21:28:20 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	init_z(t_mods *mods)
{
	mods->l = 0;
	mods->h = 0;
	mods->up_l = 0;
	mods->j = 0;
	if (mods->z > 0)
		return ;
	mods->z = 1;
}

void	init_j(t_mods *mods)
{
	mods->l = 0;
	mods->h = 0;
	mods->up_l = 0;
	mods->z = 0;
	if (mods->j > 0)
		return ;
	mods->j = 1;
}

void	init_h(t_mods *mods)
{
	mods->l = 0;
	mods->up_l = 0;
	mods->j = 0;
	mods->z = 0;
	if (mods->h > 1)
		return ;
	mods->h = mods->h + 1;
}

void	init_l(t_mods *mods)
{
	mods->h = 0;
	mods->up_l = 0;
	mods->j = 0;
	mods->z = 0;
	if (mods->l > 1)
		return ;
	mods->l = mods->l + 1;
}

void	init_up_l(t_mods *mods)
{
	mods->h = 0;
	mods->l = 0;
	mods->j = 0;
	mods->z = 0;
	if (mods->up_l > 0)
		return ;
	mods->up_l = 1;
}
