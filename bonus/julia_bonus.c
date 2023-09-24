/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:02:55 by yahokari          #+#    #+#             */
/*   Updated: 2022/09/08 20:26:50 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract_ol_bonus.h"

static double	check_decimal(const char *str, double value)
{
	size_t	i;

	i = 0;
	if (!str[i])
		return (value);
	else if (str[i] != '.')
		exit_with_guide();
	i++;
	if (!str[i])
		exit_with_guide();
	while ('0' <= str[i] && str[i] <= '9')
	{
		value += (str[i] - '0') * pow(0.1, i);
		i++;
	}
	if (str[i])
		exit_with_guide();
	return (value);
}

static double	ft_atof_within_abs_2(const char *str)
{
	size_t	i;
	int		sign;
	double	value;

	i = 0;
	value = 0;
	sign = 1;
	if (!ft_strcmp("+", str) || !ft_strcmp("-", str) || !ft_strcmp("", str))
		exit_with_guide();
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '0' || str[i] == '1')
	{
		value = str[i] - '0';
		i++;
	}
	else
		exit_with_guide();
	value = check_decimal(&str[i], value);
	return ((double)(sign * value));
}

void	init_julia(int argc, char **argv, t_vars *vars)
{
	if (argc == 2)
	{
		vars->c.re = JULIA_C_RE;
		vars->c.im = JULIA_C_IM;
	}
	else if (argc == 4)
	{
		vars->c.re = ft_atof_within_abs_2(argv[2]);
		vars->c.im = ft_atof_within_abs_2(argv[3]);
	}
	vars->type = JULIA;
	vars->hue = JULIA_HUE;
	vars->x_left = JULIA_X_LEFT;
	vars->y_top = JULIA_Y_TOP;
	vars->x_size = JULIA_X_SIZE;
	vars->y_size = JULIA_Y_SIZE;
}

t_complex	calculate_julia(t_vars *vars)
{
	return (calculate_mandelbrot(vars));
}

void	color_julia(t_vars *vars, size_t i, size_t j)
{
	size_t			loop;
	double			hue;
	double			saturation;
	double			value;
	unsigned int	rgb;

	loop = check_divergence(*vars, 2, calculate_julia);
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
