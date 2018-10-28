/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:44:37 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:44:38 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_burningship(t_fract *fract, double re, double im)
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
		re = ABS(re);
		im = ABS(im);
		xy = re * re - im * im;
		twoxy = 2 * re * im;
		re = xy + xi;
		im = twoxy + yi;
		if ((re * re + im * im) > 4)
			return (n);
		n++;
	}
	return (0);
}

void	*ft_create_burningship(void *x)
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
				ft_col(ft_burningship(thread->fract, re, im), thread->fract));
		}
		i++;
	}
	return (NULL);
}

void	ft_pr_burningship(t_fract *fract)
{
	fract->who = 3;
	ft_windows(fract);
	ft_opr(fract);
	ft_create(fract);
	ft_render(fract);
}
