/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:10:32 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:47:14 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void		applyzoom(t_fract *fract, double mousere,
	double mouseim, double zoom)
{
	double interpolation;

	interpolation = 1.0 / zoom;
	fract->maxr = interpolate(mousere, fract->maxr, interpolation);
	fract->maxi = interpolate(mouseim, fract->maxi, interpolation);
	fract->minr = interpolate(mousere, fract->minr, interpolation);
	fract->mini = interpolate(mouseim, fract->mini, interpolation);
}

int			ft_mouse(int key, int x, int y, t_fract *fract)
{
	fract->mouser = (double)x / (IWI / (fract->maxr - fract->minr)) +
	fract->minr;
	fract->mousei = (double)y / (IHI / (fract->maxi - fract->mini)) +
	fract->mini;
	fract->zoom = 1.00;
	if (key == 4)
		fract->zoom = 1.05;
	if (key == 5)
		fract->zoom = 0.95;
	applyzoom(fract, fract->mouser, fract->mousei, fract->zoom);
	if (key == 4 || key == 5)
		fract->zo = ABS(fract->maxr - fract->minr) / 20;
	fract->r_fact = (fract->maxr - fract->minr) / (IWI - 1);
	fract->i_fact = (fract->maxi - fract->mini) / (IHI - 1);
	ft_clear(fract);
	ft_create(fract);
	ft_render(fract);
	return (0);
}
