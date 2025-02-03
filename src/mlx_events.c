/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:24:17 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 14:04:31 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_and_exit(t_fractol *f)
{
	mlx_destroy_image(f->mlx_con, f->img.img_ptr);
	mlx_destroy_window(f->mlx_con, f->mlx_win);
	mlx_destroy_display(f->mlx_con);
	free(f->mlx_con);
	exit(EXIT_SUCCESS);
}

int	key_press(int key, t_fractol *f)
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
	f_render(f);
	return (0);
}

int	mouse_moves(int button, int x, int y, t_fractol *f)
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
