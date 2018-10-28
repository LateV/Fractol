/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:11:06 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:48:03 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_clear(t_fract *fract)
{
	int	i;

	i = -1;
	while (++i < MWI * MHI)
		fract->array[i] = 0x0;
}

void			ft_putpixel(t_fract *fract, int x, int y, int color)
{
	int	width;

	if (x < 0 || x > MWI || y < 0 || y > MHI)
		return ;
	width = fract->size / (fract->bpp / 8);
	fract->array[y * width + x] = color;
}
