/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:07:03 by yahokari          #+#    #+#             */
/*   Updated: 2022/09/08 20:26:17 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_BONUS_H
# define FRACT_OL_BONUS_H

# include	"../minilibx-linux/mlx.h"
# include	"../libft/libft.h"
# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<math.h>

# define TRUE 1
# define FALSE 0

# define BLACK 0x000000
# define RED 0xFF0000

# define LOOP 50
# define LOOP_ZOOM 4
# define WIN_WIDTH 500
# define WIN_LENGTH 500

# define SCALE_UP 1.3
# define SCALE_DOWN 0.7
# define MOVE_SCALE 0.05

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ON_KEYDOWN 2
# define ON_MOUSEDOWN 4
# define ON_DESTROY 17

# define ESC_1 53
# define ESC_2 65307
# define LEFT_1 123
# define LEFT_2 65361
# define RIGHT_1 124
# define RIGHT_2 65363
# define DOWN_1 125
# define DOWN_2 65364
# define UP_1 126
# define UP_2 65362
# define C_1 8
# define C_2 99

# define MNDL_HUE 127
# define MNDL_Z_RE 0
# define MNDL_Z_IM 0
# define MNDL_X_LEFT -2
# define MNDL_Y_TOP 2
# define MNDL_X_SIZE 4
# define MNDL_Y_SIZE 4

# define JULIA_HUE 210
# define JULIA_C_RE -0.79
# define JULIA_C_IM 0.15
# define JULIA_X_LEFT -2
# define JULIA_Y_TOP 2
# define JULIA_X_SIZE 4
# define JULIA_Y_SIZE 4

# define BNSP_HUE 35
# define BNSP_Z_RE 0
# define BNSP_Z_IM 0
# define BNSP_X_LEFT -1.6
# define BNSP_Y_TOP 2.5
# define BNSP_X_SIZE 4
# define BNSP_Y_SIZE 4

# define HUE_INCREMENT 10
# define HUE_MAX 359
# define SATURATION_MAX 255
# define VALUE_MAX 255

# define ERROR_MESSAGE "usage: ./fract_ol [mandelbrot, julia, burningship] \
[double(-2 < x < 2)] [double(-2 < x < 2)]\n"

enum {
	MANDELBROT,
	JULIA,
	BURNINGSHIP
};

enum {
	LEFT,
	RIGHT,
	DOWN,
	UP
};

typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

typedef struct s_rgb {
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_img {
	void	*address;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_img		img;
	int			type;
	size_t		loop;
	double		hue;
	double		x_left;
	double		y_top;
	double		x_size;
	double		y_size;
	t_complex	z;
	t_complex	c;
}	t_vars;

typedef t_complex	(*t_set)(t_vars*);

void			check_argument(int argc, char **argv, t_vars *vars);
void			exit_with_guide(void);
void			init_mandelbrot(int argc, t_vars *vars);
void			init_julia(int argc, char **argv, t_vars *vars);
void			init_burningship(int argc, t_vars *vars);
int				close_window(t_vars *vars);
int				handle_key_input(int keycode, t_vars *vars);
int				handle_mouse_input(int button, int x, int y, t_vars *vars);
void			move_direction(int direction, t_vars *vars);
void			change_scale(int x, int y, double magnification, t_vars *vars);
void			change_hue(t_vars *vars);
void			my_pixel_put(t_vars *vars, int x, int y, unsigned int color);
void			display_fractol(t_vars *vars);
size_t			check_divergence(t_vars vars, double border, t_set func);
unsigned int	hsv_to_rgb(double hue, double saturation, double value);
void			color_mandelbrot(t_vars *vars, size_t i, size_t j);
void			color_julia(t_vars *vars, size_t i, size_t j);
void			color_burningship(t_vars *vars, size_t i, size_t j);
t_complex		calculate_mandelbrot(t_vars *vars);

#endif
