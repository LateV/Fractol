/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:11:38 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:48:24 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_info(t_fract *fract)
{
	mlx_string_put(fract->mlx, fract->win, 900, 970, fract->defcol, "vibondar");
}

void			ft_render(t_fract *fract)
{
	mlx_clear_window(fract->mlx, fract->win);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	ft_info(fract);
}
