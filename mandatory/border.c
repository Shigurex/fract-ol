/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:05:06 by yahokari          #+#    #+#             */
/*   Updated: 2022/09/02 19:19:34 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract_ol.h"

static double	complex_abs(t_complex complex)
{
	double	abs;

	abs = sqrt(pow(complex.re, 2) + pow(complex.im, 2));
	return (abs);
}

static int	is_over_border(t_complex complex, double border)
{
	double	value;

	value = complex_abs(complex);
	if (value > border)
		return (TRUE);
	return (FALSE);
}

size_t	check_divergence(t_vars vars, double border, t_set func)
{
	size_t		count;
	t_complex	complex;

	count = 0;
	while (count < (size_t)vars.loop)
	{
		complex = func(&vars);
		if (is_over_border(complex, border))
			break ;
		count++;
	}
	return (count);
}
