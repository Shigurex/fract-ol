/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:58:09 by yahokari          #+#    #+#             */
/*   Updated: 2022/09/08 20:26:35 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract_ol_bonus.h"

void	init_mandelbrot(int argc, t_vars *vars)
{
	if (argc != 2)
		exit_with_guide();
	vars->type = MANDELBROT;
	vars->hue = MNDL_HUE;
	vars->x_left = MNDL_X_LEFT;
	vars->y_top = MNDL_Y_TOP;
	vars->x_size = MNDL_X_SIZE;
	vars->y_size = MNDL_Y_SIZE;
	vars->z.re = MNDL_Z_RE;
	vars->z.im = MNDL_Z_IM;
}

t_complex	calculate_mandelbrot(t_vars *vars)
{
	double	tmp_z_re;
	double	tmp_z_im;

	tmp_z_re = vars->z.re;
	tmp_z_im = vars->z.im;
	vars->z.re = pow(tmp_z_re, 2) - pow(tmp_z_im, 2) + vars->c.re;
	vars->z.im = 2 * tmp_z_re * tmp_z_im + vars->c.im;
	return (vars->z);
}

void	color_mandelbrot(t_vars *vars, size_t i, size_t j)
{
	size_t			loop;
	double			hue;
	double			saturation;
	double			value;
	unsigned int	rgb;

	loop = check_divergence(*vars, 2, calculate_mandelbrot);
	if (loop == vars->loop)
		my_pixel_put(vars, i, j, BLACK);
	else
	{
		hue = vars->hue;
		saturation = (double)(vars->loop - loop) / vars->loop * SATURATION_MAX;
		value = (double)loop / vars->loop * VALUE_MAX;
		rgb = hsv_to_rgb(hue, saturation, value);
		my_pixel_put(vars, i, j, rgb);
	}
}
