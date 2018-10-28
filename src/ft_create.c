/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:45:21 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:45:22 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_create1(int i, t_thr *threads, t_fract *fract)
{
	if (fract->who == 1)
		pthread_create(&threads[i].thread_ptr, &threads[i].thread_attr,
			ft_create_pot, &threads[i]);
	if (fract->who == 2)
		pthread_create(&threads[i].thread_ptr, &threads[i].thread_attr,
			ft_create_jul, &threads[i]);
	if (fract->who == 3)
		pthread_create(&threads[i].thread_ptr, &threads[i].thread_attr,
			ft_create_burningship, &threads[i]);
	if (fract->who == 4)
		pthread_create(&threads[i].thread_ptr, &threads[i].thread_attr,
			ft_create_tree, &threads[i]);
	if (fract->who == 5)
		pthread_create(&threads[i].thread_ptr, &threads[i].thread_attr,
			ft_create_dnk, &threads[i]);
	if (fract->who == 6)
		pthread_create(&threads[i].thread_ptr, &threads[i].thread_attr,
			ft_create_ship, &threads[i]);
	if (fract->who == 7)
		pthread_create(&threads[i].thread_ptr, &threads[i].thread_attr,
			ft_create_tricorn, &threads[i]);
	if (fract->who == 8)
		pthread_create(&threads[i].thread_ptr, &threads[i].thread_attr,
			ft_create_mandelbrot4, &threads[i]);
}

void		ft_create(t_fract *fract)
{
	int			i;
	t_thr		threads[THREADS];

	i = 0;
	while (i < THREADS)
	{
		threads[i].fract = fract;
		threads[i].thread_id = i;
		pthread_attr_init(&threads[i].thread_attr);
		if (fract->who == 0)
			ft_create_man_t(fract);
		ft_create1(i, threads, fract);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i++].thread_ptr, NULL);
	}
}
