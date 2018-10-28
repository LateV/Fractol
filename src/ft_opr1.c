/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opr1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 21:31:32 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 21:31:34 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_opr_born(t_fract *fract)
{
	fract->minr = -2.0;
	fract->maxr = 2.0;
	fract->mini = -2.0;
	fract->maxi = 2.0;
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

void	ft_opr_tre(t_fract *fract)
{
	fract->minr = -1.3;
	fract->maxr = 1.2;
	fract->mini = 0.6;
	fract->maxi = 2.7;
	fract->r_fact = (fract->maxr - fract->minr) / (IWI - 1);
	fract->i_fact = (fract->maxi - fract->mini) / (IHI - 1);
	fract->iter = 50;
	fract->defcol = 0x00FF00;
	fract->zoom = 1;
	fract->zo = fract->minr / 10;
	fract->space = 0;
	fract->m_r = 0.268875;
	fract->m_i = 0.008551;
	fract->psih = 0;
	fract->color = 1;
}

void	ft_opr_dnk(t_fract *fract)
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
	fract->m_r = -0.473712;
	fract->m_i = -0.904002;
	fract->psih = 0;
	fract->color = 1;
}

void	ft_opr_ship(t_fract *fract)
{
	fract->minr = -1.4;
	fract->maxr = 1.1;
	fract->mini = -1.3;
	fract->maxi = 1.245;
	fract->r_fact = (fract->maxr - fract->minr) / (IWI - 1);
	fract->i_fact = (fract->maxi - fract->mini) / (IHI - 1);
	fract->iter = 50;
	fract->defcol = 0x00FF00;
	fract->zoom = 1;
	fract->zo = fract->minr / 10;
	fract->space = 0;
	fract->m_r = -0.473712;
	fract->m_i = -0.904002;
	fract->psih = 0;
	fract->color = 1;
}
