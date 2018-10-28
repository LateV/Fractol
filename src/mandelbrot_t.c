/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:53:15 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:53:16 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_create_man_t(t_fract *fract)
{
	int i;
	int j;

	i = 0;
	while (i < IHI)
	{
		fract->re = fract->minr + i * fract->r_fact;
		j = 0;
		while (j < IWI)
		{
			fract->im = fract->mini + j * fract->i_fact;
			ft_putpixel(fract, i, j,
				ft_col(ft_man(fract, fract->re, fract->im), fract));
			j++;
		}
		i++;
	}
}

void		ft_t_mandel(t_fract *fract)
{
	fract->who = 0;
	ft_windows(fract);
	ft_opr(fract);
	ft_create_man_t(fract);
	ft_render(fract);
}
