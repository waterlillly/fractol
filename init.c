/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:44:48 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/21 17:35:24 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_exit(char *s, t_fractol *f)
{
	ft_putstr_fd(s, STDERR_FILENO);
	if (f->mlx_con)
		free(f->mlx_con);
	exit(EXIT_FAILURE);
}

void	init_data(t_fractol *f)
{
	f->esc_value = 4;
	f->def_iterations = 424;
	f->x_move = 0.0;
	f->y_move = 0.0;
	f->zoom = 1.0;
}

void	init_events(t_fractol *f)
{
	mlx_hook(f->mlx_win, KeyPress, KeyPressMask, key_press, f);
	//mlx_hook(f->mlx_win, ButtonPress, ButtonPressMask, mouse_moves, f);
	mlx_mouse_hook(f->mlx_win, mouse_moves, f);
	mlx_hook(f->mlx_win, DestroyNotify, StructureNotifyMask, close_and_exit, f);
	//mlx_hook(f->mlx_win, MotionNotify, PointerMotionMask, julia_mapping, f);
}

void    init_fractol(t_fractol *f)
{
	f->mlx_con = mlx_init();
	if (!f->mlx_con)
		error_exit("Error: mlx_con\n", NULL);
	f->mlx_win = mlx_new_window(f->mlx_con, WIDTH, HEIGHT, f->name);
	if (!f->mlx_win)
	{
		mlx_destroy_display(f->mlx_con);
		error_exit("Error: mlx_new_window\n", f);
	}
	f->img.img_ptr = mlx_new_image(f->mlx_con, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
	{
		mlx_destroy_window(f->mlx_con, f->mlx_win);
		mlx_destroy_display(f->mlx_con);
		error_exit("Error: mlx_new_image\n", f);
	}
	f->img.pxl_ptr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
		&f->img.len, &f->img.endian);
	init_events(f);
	init_data(f);
}

