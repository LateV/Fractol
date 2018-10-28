/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:49:09 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:49:10 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_julia(t_fract *fract, double re, double im)
{
	int		n;
	double	xy;
	double	twoxy;
	double	xi;
	double	yi;

	xi = fract->m_r;
	yi = fract->m_i;
	n = 0;
	while (n < (int)fract->iter)
	{
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

void		*ft_create_jul(void *x)
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
				ft_col(ft_julia(thread->fract, re, im), thread->fract));
		}
		i++;
	}
	return (NULL);
}

void		ft_pr_julia(t_fract *fract)
{
	fract->who = 2;
	ft_windows(fract);
	ft_opr(fract);
	ft_create(fract);
	ft_render(fract);
}
