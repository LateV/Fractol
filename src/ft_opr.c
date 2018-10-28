/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:47:48 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:47:49 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_opr_jul(t_fract *fract)
{
	fract->minr = -1.0;
	fract->maxr = 1.5;
	fract->mini = -1.2;
	fract->maxi = 1.345;
	fract->r_fact = (fract->maxr - fract->minr) / (IWI - 1);
	fract->i_fact = (fract->maxi - fract->mini) / (IHI - 1);
	fract->iter = 50;
	fract->defcol = 0x00FF00;
	fract->zoom = 1;
	fract->zo = fract->minr / 10;
	fract->space = 0;
	fract->m_r = -0.70176;
	fract->m_i = -0.3842;
	fract->psih = 0;
	fract->color = 1;
}

void	ft_opr_man(t_fract *fract)
{
	fract->minr = -2.0;
	fract->maxr = 0.5;
	fract->mini = -1.25;
	fract->maxi = 1.25;
	fract->r_fact = (fract->maxr - fract->minr) / (IWI - 1);
	fract->i_fact = (fract->maxi - fract->mini) / (IHI - 1);
	fract->iter = 50;
	fract->defcol = 0x00FF00;
	fract->zoom = 1;
	fract->zo = fract->minr / 10;
	fract->space = 0;
	fract->psih = 0;
	fract->color = 1;
}

void	ft_opr_tricorn(t_fract *fract)
{
	fract->minr = -1.5;
	fract->maxr = 1.0;
	fract->mini = -1.25;
	fract->maxi = 1.25;
	fract->r_fact = (fract->maxr - fract->minr) / (IWI - 1);
	fract->i_fact = (fract->maxi - fract->mini) / (IHI - 1);
	fract->iter = 50;
	fract->defcol = 0x00FF00;
	fract->zoom = 1;
	fract->zo = fract->minr / 10;
	fract->space = 0;
	fract->psih = 0;
	fract->color = 1;
}

void	ft_opr_mandelbrot4(t_fract *fract)
{
	fract->minr = -1.25;
	fract->maxr = 1.25;
	fract->mini = -1.5;
	fract->maxi = 1;
	fract->r_fact = (fract->maxr - fract->minr) / (IWI - 1);
	fract->i_fact = (fract->maxi - fract->mini) / (IHI - 1);
	fract->iter = 50;
	fract->defcol = 0x00FF00;
	fract->zoom = 1;
	fract->zo = fract->minr / 10;
	fract->space = 0;
	fract->psih = 0;
	fract->color = 1;
}

void	ft_opr(t_fract *fract)
{
	if (fract->who == 0 || fract->who == 1)
		ft_opr_man(fract);
	if (fract->who == 2)
		ft_opr_jul(fract);
	if (fract->who == 3)
		ft_opr_born(fract);
	if (fract->who == 4)
		ft_opr_tre(fract);
	if (fract->who == 5)
		ft_opr_dnk(fract);
	if (fract->who == 6)
		ft_opr_ship(fract);
	if (fract->who == 7)
		ft_opr_tricorn(fract);
	if (fract->who == 8)
		ft_opr_mandelbrot4(fract);
}
