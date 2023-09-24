/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:14:11 by yahokari          #+#    #+#             */
/*   Updated: 2022/09/13 00:05:31 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract_ol.h"

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
	else if (keycode == J_1)
		change_scale(WIN_WIDTH / 2, WIN_LENGTH / 2, SCALE_UP, vars);
	else if (keycode == K_1)
		change_scale(WIN_WIDTH / 2, WIN_LENGTH / 2, SCALE_DOWN, vars);
	else if (keycode == Q_1)
		vars->c.re += 0.01;
	else if (keycode == W_1)
		vars->c.re -= 0.01;
	else if (keycode == E_1)
		vars->c.im += 0.01;
	else if (keycode == R_1)
		vars->c.im -= 0.01;
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
