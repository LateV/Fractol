/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:45:29 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:47:21 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_reset(int key, t_fract *fract)
{
	if (key == 15)
		ft_opr(fract);
	ft_clear(fract);
	ft_create(fract);
	ft_render(fract);
}

void			ft_color(int key, t_fract *fract)
{
	if (key == 8)
	{
		if (fract->color == 4)
			fract->color = 1;
		else
			fract->color += 1;
	}
	ft_clear(fract);
	ft_create(fract);
	ft_render(fract);
}

void			ft_psih(int key, t_fract *fract)
{
	if (key == 35 && fract->who != 8 && fract->who != 6)
	{
		if (fract->psih == 1)
			fract->psih = 0;
		else
			fract->psih = 1;
		ft_clear(fract);
		ft_create(fract);
		ft_render(fract);
	}
}

void			ft_fractal(int key, t_fract *fract)
{
	int		color1;
	int		space1;
	int		psih1;

	if (key == 3)
	{
		if (fract->who == 8)
			fract->who = 1;
		else
			fract->who += 1;
	}
	space1 = fract->space;
	if (fract->who != 8 && fract->who != 6)
		psih1 = fract->psih;
	else
		psih1 = 0;
	color1 = fract->color;
	ft_opr(fract);
	fract->space = space1;
	fract->psih = psih1;
	fract->color = color1;
	ft_clear(fract);
	ft_create(fract);
	ft_render(fract);
	ft_hook(fract);
}

int				ft_key(int key, t_fract *fract)
{
	if (key == 53)
		exit(0);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_shift(key, fract);
	if (key == 24 || key == 27 || key == 69 || key == 78)
		ft_itera(key, fract);
	if (key == 15)
		ft_reset(key, fract);
	if (key == 49)
		ft_space(key, fract);
	if (key == 35)
		ft_psih(key, fract);
	if (key == 8)
		ft_color(key, fract);
	if (key == 3)
		ft_fractal(key, fract);
	return (0);
}
