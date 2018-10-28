/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:47:39 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:47:40 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate1(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applysma(t_fract *fract, double mousere, double mouseim, double zoom)
{
	double interpolation;

	interpolation = 1.0 / zoom;
	fract->maxr = interpolate1(mousere, fract->maxr, interpolation);
	fract->maxi = interpolate1(mouseim, fract->maxi, interpolation);
	fract->minr = interpolate1(mousere, fract->minr, interpolation);
	fract->mini = interpolate1(mouseim, fract->mini, interpolation);
}

int		ft_move_mouse(int x, int y, t_fract *fract)
{
	double re;
	double im;

	if ((x > 0 && x < IWI && y > 0 && y < IHI &&
		fract->space == 1) && (fract->who == 2 || fract->who == 6))
	{
		re = (double)x / (IWI / (fract->maxr - fract->minr)) + fract->minr;
		im = (double)y / (IHI / (fract->maxi - fract->mini)) + fract->mini;
		fract->m_r = re;
		fract->m_i = im;
	}
	if (fract->who == 2 || fract->who == 6)
	{
		applysma(fract, fract->mouser, fract->mousei, 1);
		ft_clear(fract);
		ft_create(fract);
		ft_render(fract);
	}
	return (0);
}
