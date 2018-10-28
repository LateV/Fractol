/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:46:31 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:46:33 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(int x, int width, double from, double to)
{
	double	d_x;

	d_x = (to - from) / width;
	return (from + (x * d_x));
}
