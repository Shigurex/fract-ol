/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:15:16 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/29 22:08:35 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract_ol.h"

void	init_setup(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_LENGTH, "fract-ol");
	vars->loop = LOOP;
	mlx_hook(vars->win, ON_DESTROY, 1L << 0, close_window, vars);
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, handle_key_input, vars);
	mlx_hook(vars->win, ON_MOUSEDOWN, 1L << 0, handle_mouse_input, vars);
	vars->img.address = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_LENGTH);
	vars->img.data = mlx_get_data_addr(vars->img.address, \
		&vars->img.bpp, &vars->img.size_l, &vars->img.endian);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	check_argument(argc, argv, &vars);
	init_setup(&vars);
	display_fractol(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
