/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:24:21 by yahokari          #+#    #+#             */
/*   Updated: 2022/09/08 20:23:57 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract_ol_bonus.h"

void	exit_with_guide(void)
{
	ft_putstr_fd(ERROR_MESSAGE, 2);
	exit(1);
}

void	check_argument(int argc, char **argv, t_vars *vars)
{
	if (argc != 2 && argc != 4)
		exit_with_guide();
	if (!ft_strcmp(argv[1], "mandelbrot"))
		init_mandelbrot(argc, vars);
	else if (!ft_strcmp(argv[1], "julia"))
		init_julia(argc, argv, vars);
	else if (!ft_strcmp(argv[1], "burningship"))
		init_burningship(argc, vars);
	else
		exit_with_guide();
}
