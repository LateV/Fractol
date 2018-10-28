/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:50:31 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/17 16:17:28 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_usage(void)
{
	ft_putstr("usage:  ./fractol [name fractal] ");
	ft_putstr("[name fractal]\nnames:   mandelbrot\n");
	ft_putstr("         julia\n");
	ft_putstr("         burningship\n");
	ft_putstr("         tree\n");
	ft_putstr("         dnk\n");
	ft_putstr("         ship\n");
	ft_putstr("         mandelbrot_t\n");
	ft_putstr("         mandelbrot4\n");
}

void		ft_run(char *av1, t_fract *fract1)
{
	if (ft_strcmp(av1, "mandelbrot") == 0)
		ft_pr_mandel(fract1);
	else if (ft_strcmp(av1, "mandelbrot_t") == 0)
		ft_t_mandel(fract1);
	else if (ft_strcmp(av1, "julia") == 0)
		ft_pr_julia(fract1);
	else if (ft_strcmp(av1, "burningship") == 0)
		ft_pr_burningship(fract1);
	else if (ft_strcmp(av1, "tree") == 0)
		ft_pr_tree(fract1);
	else if (ft_strcmp(av1, "dnk") == 0)
		ft_pr_dnk(fract1);
	else if (ft_strcmp(av1, "ship") == 0)
		ft_pr_ship(fract1);
	else if (ft_strcmp(av1, "tricorn") == 0)
		ft_pr_tricorn(fract1);
	else if (ft_strcmp(av1, "mandelbrot4") == 0)
		ft_pr_mandelbrot4(fract1);
	else
	{
		ft_usage();
		exit(0);
	}
}

int			ft_iswho(char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0 ||
		ft_strcmp(av, "mandelbrot_t") == 0 ||
		ft_strcmp(av, "burningship") == 0 ||
		ft_strcmp(av, "julia") == 0 ||
		ft_strcmp(av, "ship") == 0 ||
		ft_strcmp(av, "dnk") == 0 ||
		ft_strcmp(av, "tricorn") == 0 ||
		ft_strcmp(av, "mandelbrot4") == 0 ||
		ft_strcmp(av, "tree") == 0)
		return (1);
	else
		return (0);
}

int			ft_multiple(char *av1, char *av2, t_fract *fract1, t_fract *fract2)
{
	int fo;

	fo = 0;
	if (ft_iswho(av1) == 1)
	{
		if (ft_iswho(av2) == 1)
		{
			fo = fork();
			if (!fo)
			{
				ft_run(av1, fract1);
				ft_hook(fract1);
			}
			ft_run(av2, fract2);
			ft_instr();
			ft_hook(fract2);
			return (2);
		}
		ft_run(av1, fract1);
		ft_instr();
		ft_hook(fract1);
		return (1);
	}
	ft_usage();
	return (0);
}

int			main(int ac, char **av)
{
	t_fract		mandel;
	t_fract		julia;

	if (ac == 1)
		ft_usage();
	else if (ac == 3)
		ft_multiple(av[1], av[2], &mandel, &julia);
	else if (ac == 2)
	{
		ft_run(av[1], &mandel);
		ft_instr();
		ft_hook(&mandel);
	}
	else
	{
		ft_putstr("Number of parameters is incorrect\n");
		ft_usage();
	}
	return (0);
}
