/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:15:55 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/17 16:15:57 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_instr(void)
{
	ft_putstr("INSTRUCTIONS: \n");
	ft_putstr("         R - reset\n");
	ft_putstr("         C - change of fractal`s color\n");
	ft_putstr("         arrows - movement\n");
	ft_putstr("         - and + - number of iteration\n");
	ft_putstr("         F - change fractal\n");
	ft_putstr("         P - psyhodelic mode\n");
	ft_putstr("         esc - exit\n");
	ft_putstr("         space - stop/move the Julia`s set\n");
	ft_putstr("         mouse wheel - zoom\n");
}
