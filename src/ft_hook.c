/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:45:47 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:45:49 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_hook(t_fract *fract)
{
	mlx_mouse_hook(fract->win, &ft_mouse, fract);
	mlx_hook(fract->win, 6, 1L << 6, ft_move_mouse, fract);
	mlx_hook(fract->win, 2, 5, &ft_key, fract);
	mlx_hook(fract->win, 17, 1L << 17, ft_exit, NULL);
	mlx_loop(fract->mlx);
}
