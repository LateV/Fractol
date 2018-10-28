/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:53:37 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:53:39 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_ship(t_fract *fract, double re, double im)
{
	int		n;
	double	xy;
	double	twoxy;
	double	xi;
	double	yi;

	xi = re;
	yi = im;
	n = 0;
	while (n < (int)fract->iter)
	{
		im = xy + xi;
		re = twoxy + yi;
		xy = ABS(im) * (5 * re * re * re * re -
			10 * im * im * re * re + im * im * im * im);
		twoxy = ABS(re) * (re * re * re * re -
			10 * re * re * im * im + 5 * im * im * im * im);
		if ((re * re * im * im) > 16)
			return (n);
		n++;
	}
	return (0);
}

void		*ft_create_ship(void *x)
{
	t_thr		*thread;
	int			i;
	int			j;
	double		re;
	double		im;

	thread = (t_thr *)x;
	i = IHI / THREADS * thread->thread_id;
	while (i < IHI / THREADS * (thread->thread_id + 1))
	{
		j = -1;
		while (++j < IWI)
		{
			re = ft_map(j, IWI, thread->fract->minr, thread->fract->maxr);
			im = ft_map(i, IHI, thread->fract->mini, thread->fract->maxi);
			ft_putpixel(thread->fract, j, i,
				ft_col(ft_ship(thread->fract, re, im), thread->fract));
		}
		i++;
	}
	return (NULL);
}

void		ft_pr_ship(t_fract *fract)
{
	fract->who = 6;
	ft_windows(fract);
	ft_opr(fract);
	ft_create(fract);
	ft_render(fract);
}
