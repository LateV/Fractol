/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:45:02 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:45:03 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_psyho(t_fract *fract, int iter)
{
	int color;

	if (iter == 0)
		iter = 1;
	color = (int)iter * 2147483647 / (fract->iter * iter * 0.2);
	return (color);
}

static double		ft_procent(double iter, double min_iter, double max_iter)
{
	if (iter == min_iter)
		return (0.0);
	if (iter == max_iter)
		return (1.0);
	return ((iter - max_iter) / (max_iter - min_iter));
}

static int			ft_rgb(int c1, int c2, int n, t_fract *fract)
{
	double	d_r;
	double	d_g;
	double	d_b;
	double	proc;
	int		color;

	color = 0;
	proc = ft_procent(n, 0, fract->iter);
	d_r = (double)(((c1 >> 16) & 0xFF) - ((c2 >> 16) & 0xFF)) * proc;
	d_g = (double)(((c1 >> 8) & 0xFF) - ((c2 >> 8) & 0xFF)) * proc;
	d_b = (double)(((c1) & 0xFF) - ((c2) & 0xFF)) * proc;
	color += (int)((c1 & 0xFF) + (d_b));
	color += (int)(((c1 >> 8) & 0xFF) + (d_g)) << 8;
	color += (int)(((c1 >> 16) & 0xFF) + (d_r)) << 16;
	return (color);
}

int					ft_col1(int col, t_fract *fract)
{
	if (fract->color == 3)
	{
		if (col == 0)
			return (ft_rgb(0x0000FF, 0x00FF00, col, fract));
		else
			return (ft_rgb(0x00FF00, 0x0000FF, col, fract));
	}
	else
	{
		if (col == 0)
			return (ft_rgb(0x6D95B8, 0xFF0000, col, fract));
		else
			return (ft_rgb(0xFF0000, 0x6D95B8, col, fract));
	}
}

int					ft_col(int col, t_fract *fract)
{
	if (fract->psih == 1)
		return (ft_psyho(fract, col));
	else if (fract->color == 1)
	{
		if (col == 0)
			return (ft_rgb(0xCC33FF, 0xFFFF00, col, fract));
		else
			return (ft_rgb(0xFFFF00, 0xCC33FF, col, fract));
	}
	else if (fract->color == 2)
	{
		if (col == 0)
			return (ft_rgb(0x00FF00, 0x0000FF, col, fract));
		else
			return (ft_rgb(0x0000FF, 0x00FF00, col, fract));
	}
	else
		return (ft_col1(col, fract));
}
