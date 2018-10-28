/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:44:52 by vibondar          #+#    #+#             */
/*   Updated: 2018/03/16 20:44:54 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# define MHI 1000
# define MWI 1000
# define IHI 1000
# define IWI 1000
# define THREADS 100

typedef struct	s_fract
{
	double		minr;
	double		maxr;
	double		mini;
	double		maxi;
	double		r_fact;
	double		i_fact;
	double		re;
	double		im;
	double		zoom;
	double		zo;
	double		mouser;
	double		mousei;
	int			iter;
	int			defcol;
	void		*mlx;
	void		*mlx1;
	void		*win;
	void		*img;
	int			bpp;
	int			size;
	int			endian;
	int			*array;
	int			who;
	double		m_r;
	double		m_i;
	int			space;
	int			psih;
	int			sec;
	int			color;
}				t_fract;

typedef struct	s_thr
{
	pthread_t		thread_ptr;
	pthread_attr_t	thread_attr;
	int				thread_id;
	t_fract			*fract;
}				t_thr;

int				ft_key(int key, t_fract *fract);
void			ft_windows(t_fract *fract);
int				ft_mouse(int key, int x, int y, t_fract *fract);
void			ft_putpixel(t_fract *fract, int x, int y, int color);
void			ft_render(t_fract *fract);
void			ft_clear(t_fract *fract);
void			ft_create(t_fract *fract);
void			ft_opr(t_fract *fract);
int				ft_col(int col, t_fract *fract);
void			ft_pr_mandel(t_fract *fract);
int				ft_man(t_fract *fract, double re, double im);
void			ft_t_mandel(t_fract *fract);
void			ft_pr_julia(t_fract *fract);
double			ft_map(int x, int width, double from, double to);
void			ft_create(t_fract *fract);
void			*ft_create_pot(void *x);
void			*ft_create_jul(void *x);
void			*ft_create_burningship(void *x);
void			ft_pr_burningship(t_fract *fract);
void			ft_create_man_t(t_fract *fract);
int				ft_move_mouse(int x, int y, t_fract *fract);
void			*ft_create_tree(void *x);
void			ft_pr_tree(t_fract *fract);
void			ft_pr_dnk(t_fract *fract);
void			*ft_create_dnk(void *x);
void			ft_pr_ship(t_fract *fract);
void			*ft_create_ship(void *x);
void			ft_pr_tricorn(t_fract *fract);
void			*ft_create_tricorn(void *x);
void			ft_pr_mandelbrot4(t_fract *fract);
void			*ft_create_mandelbrot4(void *x);
void			ft_whorun(t_fract *fract);
int				ft_exit(void);
void			ft_hook(t_fract *fract);
void			ft_shift(int key, t_fract *fract);
void			ft_itera(int key, t_fract *fract);
void			ft_space(int key, t_fract *fract);
void			ft_opr_dnk(t_fract *fract);
void			ft_opr_tre(t_fract *fract);
void			ft_opr_born(t_fract *fract);
void			ft_opr_ship(t_fract *fract);
void			ft_instr(void);

#endif
