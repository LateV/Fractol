/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_keyboard1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 21:25:09 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 21:25:10 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_shift(int key, t_fract *fract)
{
	if (key == 123)
	{
		fract->minr -= fract->zo;
		fract->maxr -= fract->zo;
	}
	if (key == 124)
	{
		fract->minr += fract->zo;
		fract->maxr += fract->zo;
	}
	if (key == 125)
	{
		fract->mini += fract->zo;
		fract->maxi += fract->zo;
	}
	if (key == 126)
	{
		fract->mini -= fract->zo;
		fract->maxi -= fract->zo;
	}
	ft_clear(fract);
	ft_create(fract);
	ft_render(fract);
}

void			ft_itera(int key, t_fract *fract)
{
	if (key == 24 || key == 69)
		fract->iter += 5;
	if (key == 27 || key == 78)
		fract->iter -= 5;
	ft_clear(fract);
	ft_create(fract);
	ft_render(fract);
}

void			ft_space(int key, t_fract *fract)
{
	if (key == 49)
	{
		if (fract->space == 1)
			fract->space = 0;
		else
			fract->space = 1;
	}
}
