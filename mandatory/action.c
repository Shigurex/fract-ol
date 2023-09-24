/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:45:35 by yahokari          #+#    #+#             */
/*   Updated: 2022/09/08 19:16:18 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract_ol.h"

void	move_direction(int direction, t_vars *vars)
{
	if (direction == RIGHT)
		vars->x_left += vars->x_size * MOVE_SCALE;
	if (direction == LEFT)
		vars->x_left -= vars->x_size * MOVE_SCALE;
	if (direction == UP)
		vars->y_top += vars->y_size * MOVE_SCALE;
	if (direction == DOWN)
		vars->y_top -= vars->y_size * MOVE_SCALE;
}

void	change_scale(int x, int y, double magnification, t_vars *vars)
{
	if (magnification == SCALE_UP && vars->loop >= LOOP)
		vars->loop += LOOP_ZOOM;
	if (magnification == SCALE_DOWN && vars->loop >= LOOP + LOOP_ZOOM)
		vars->loop -= LOOP_ZOOM;
	vars->x_left += vars->x_size * x / WIN_WIDTH * (1 - 1 / magnification);
	vars->x_size /= magnification;
	vars->y_top -= vars->y_size * y / WIN_LENGTH * (1 - 1 / magnification);
	vars->y_size /= magnification;
}

void	change_hue(t_vars *vars)
{
	vars->hue = ((int)vars->hue + HUE_INCREMENT) % (HUE_MAX + 1);
}
