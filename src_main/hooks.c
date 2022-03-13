/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:48:48 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/13 21:18:03 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_win(vars);
	else if (keycode == 69)
		vars->img.max_iter = vars->img.max_iter + 2;
	else if (keycode == 78)
		vars->img.max_iter = vars->img.max_iter - 2;
	else if (keycode == 49)
		vars->img.is_fixed = !vars->img.is_fixed;
	else if (keycode == 46)
		vars->img.fractol.m_koef = init_complex(1.0, 2.0);
	else if (keycode == 4)
		vars->img.is_help = !vars->img.is_help;
	kbrd_color_check(vars, keycode);
	render_func(vars);
	return (0);
}

void	kbrd_color_check(t_vars *vars, int keycode)
{
	if (vars->img.pq2 + vars->img.pq1 < 255 && vars->img.pq2 < 121)
	{
		if (keycode == 14)
			vars->img.pq2 = vars->img.pq2 + 1;
		if (keycode == 2)
			vars->img.pq1 = vars->img.pq1 + 1;
		if (vars->img.pq2 > vars->img.pq1)
			vars->img.pq1 = vars->img.pq2;
	}
	if (keycode == 12 && vars->img.pq2 > 10)
		vars->img.pq2 = vars->img.pq2 - 1;
	if (keycode == 0 && vars->img.pq1 > 10)
		vars->img.pq1 = vars->img.pq1 - 1;
	if (vars->img.pq1 < vars->img.pq2)
		vars->img.pq2 = vars->img.pq1;
}

int	mouse_move(int x, int y, t_vars *vars)
{
	if (!vars->img.is_fixed)
	{
		vars->img.fractol.c_koef.re
			= vars->img.ld_corner.re + (vars->img.x_step * (x));
		vars->img.fractol.c_koef.im
			= -(vars->img.ld_corner.im + (vars->img.y_step * (y)));
		vars->img.fractol.m_koef.re
			= vars->img.ld_corner.re + (vars->img.x_step * (x));
		vars->img.fractol.m_koef.im
			= -(vars->img.ld_corner.im + (vars->img.y_step * (y)));
		render_func(vars);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	vars->img.mouse_x = x;
	vars->img.mouse_y = y;
	vars->img.zoom = 0.9;
	if (keycode == 4)
		win_rescale(&vars->img);
	else if (keycode == 5)
	{
		vars->img.zoom = 1 / vars->img.zoom;
		win_rescale(&vars->img);
	}
	render_func(vars);
	return (0);
}
