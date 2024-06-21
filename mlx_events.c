/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:24:17 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/21 13:39:27 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_and_exit(t_fractol *f)
{
	mlx_destroy_image(f->mlx_con, f->img.img_ptr);
	mlx_destroy_window(f->mlx_con, f->mlx_win);
	mlx_destroy_display(f->mlx_con);
	free(f->mlx_con);
	exit(EXIT_SUCCESS);
}

int key_press(int key, t_fractol *f)
{
	if (key == XK_Escape)
		close_and_exit(f);
	if (key == XK_Left)
		f->x_move -= (0.5 * f->zoom);
	else if (key == XK_Right)
		f->x_move += (0.5 * f->zoom);
	else if (key == XK_Up)
		f->y_move += (0.5 * f->zoom);
	else if (key == XK_Down)
		f->y_move -= (0.5 * f->zoom);
	else if (key == XK_plus)
		f->def_iterations += 25;
	else if (key == XK_minus)
		f->def_iterations -= 25;
	f_render(f);
	return (0);
}

int mouse_moves(int button, int x, int y, t_fractol *f)
{
	if (button == Button5)
	{
		f->zoom *= 1.1;
		f->x_move -= (x - WIDTH / 2) * (f->zoom / (WIDTH / 2));
		f->y_move += (y - HEIGHT / 2) * (f->zoom / (HEIGHT / 2));
	}
	else if (button == Button4)
	{
		f->zoom /= 1.1;
		f->x_move += (x - WIDTH / 2) * (f->zoom / (WIDTH / 2));
		f->y_move -= (y - HEIGHT / 2) * (f->zoom / (HEIGHT / 2));
	}
	f_render(f);
	return (0);
}


int	julia_mapping(int x, int y, t_fractol *f)
{
	if (ft_strcmp(f->name, "julia"))
	{
		f->j_x = (scale(x, map_values(-2, +2, 0, WIDTH)) * f->zoom) + f->x_move;
		f->j_y = (scale(y, map_values(+2, -2, 0, HEIGHT)) * f->zoom) + f->y_move;
		f_render(f);
	}
	return (0);
}
