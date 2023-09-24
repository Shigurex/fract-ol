/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:18:16 by yahokari          #+#    #+#             */
/*   Updated: 2022/09/08 20:27:20 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract_ol.h"

void	my_pixel_put(t_vars *vars, int x, int y, unsigned int color)
{
	void	*dst;

	dst = vars->img.data + (y * vars->img.size_l + x * (vars->img.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	input_rgb(t_rgb *rgb, int red, int green, int blue)
{
	rgb->red = red;
	rgb->green = green;
	rgb->blue = blue;
}

unsigned int	hsv_to_rgb(double hue, double saturation, double value)
{
	t_rgb	rgb;
	int		max;
	int		min;

	max = (int)value;
	min = max - (int)(saturation / SATURATION_MAX * max);
	if (0 <= hue && hue < 60)
		input_rgb(&rgb, max, (hue / 60) * (max - min) + min, min);
	else if (60 <= hue && hue < 120)
		input_rgb(&rgb, (120 - hue) / 60 * (max - min) + min, max, min);
	else if (120 <= hue && hue < 180)
		input_rgb(&rgb, min, max, (hue - 120) / 60 * (max - min) + min);
	else if (180 <= hue && hue < 240)
		input_rgb(&rgb, min, (240 - hue) / 60 * (max - min) + min, max);
	else if (240 <= hue && hue < 300)
		input_rgb(&rgb, (hue - 240) / 60 * (max - min) + min, min, max);
	else if (300 <= hue && hue < 360)
		input_rgb(&rgb, max, min, (360 - hue) / 60 * (max - min) + min);
	return (0x010000 * rgb.red + 0x000100 * rgb.green + 0x000001 * rgb.blue);
}

static void	color_fractol(t_vars *vars, size_t i, size_t j)
{
	if (vars->type == MANDELBROT)
		color_mandelbrot(vars, i, j);
	else if (vars->type == JULIA)
		color_julia(vars, i, j);
	else if (vars->type == BURNINGSHIP)
		color_burningship(vars, i, j);
}

void	display_fractol(t_vars *vars)
{
	size_t		i;
	size_t		j;
	t_complex	*variable;

	if ((*vars).type == MANDELBROT || (*vars).type == BURNINGSHIP)
		variable = &vars->c;
	else if ((*vars).type == JULIA)
		variable = &vars->z;
	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_LENGTH)
		{
			variable->re = vars->x_left + (double)i / WIN_WIDTH * vars->x_size;
			variable->im = vars->y_top - (double)j / WIN_LENGTH * vars->y_size;
			color_fractol(vars, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.address, 0, 0);
}
