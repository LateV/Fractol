/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:42:18 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:48:46 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_windows(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (fract->who == 0)
		fract->win = mlx_new_window(fract->mlx, MWI, MHI, "Slow mandelbrot");
	if (fract->who == 1)
		fract->win = mlx_new_window(fract->mlx, MWI, MHI, "Mandelbrot");
	if (fract->who == 2)
		fract->win = mlx_new_window(fract->mlx, MWI, MHI, "Julia");
	if (fract->who == 3)
		fract->win = mlx_new_window(fract->mlx, MWI, MHI, "burningship");
	if (fract->who == 4)
		fract->win = mlx_new_window(fract->mlx, MWI, MHI, "tree");
	if (fract->who == 5)
		fract->win = mlx_new_window(fract->mlx, MWI, MHI, "dnk");
	if (fract->who == 6)
		fract->win = mlx_new_window(fract->mlx, MWI, MHI, "ship");
	if (fract->who == 7)
		fract->win = mlx_new_window(fract->mlx, MWI, MHI, "tricorn");
	if (fract->who == 8)
		fract->win = mlx_new_window(fract->mlx, MWI, MHI, "Mandelbrot4");
	fract->img = mlx_new_image(fract->mlx, MWI, MHI);
	fract->array = (int *)mlx_get_data_addr(fract->img,
		&fract->bpp, &fract->size, &fract->endian);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
