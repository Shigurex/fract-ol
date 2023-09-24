/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:14:11 by yahokari          #+#    #+#             */
/*   Updated: 2022/09/08 20:24:24 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract_ol_bonus.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.address);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	handle_key_input(int keycode, t_vars *vars)
{
	if (keycode == ESC_1 || keycode == ESC_2)
		close_window(vars);
	else if (keycode == RIGHT_1 || keycode == RIGHT_2)
		move_direction(RIGHT, vars);
	else if (keycode == LEFT_1 || keycode == LEFT_2)
		move_direction(LEFT, vars);
	else if (keycode == UP_1 || keycode == UP_2)
		move_direction(UP, vars);
	else if (keycode == DOWN_1 || keycode == DOWN_2)
		move_direction(DOWN, vars);
	else if (keycode == C_1 || keycode == C_2)
		change_hue(vars);
	else
		return (1);
	display_fractol(vars);
	return (0);
}

int	handle_mouse_input(int button, int x, int y, t_vars *vars)
{
	if (button == SCROLL_UP)
		change_scale(x, y, SCALE_UP, vars);
	else if (button == SCROLL_DOWN)
		change_scale(x, y, SCALE_DOWN, vars);
	else
		return (1);
	display_fractol(vars);
	return (0);
}
