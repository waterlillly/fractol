/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:42:38 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/21 14:00:37 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_pixel(int x, int y, t_fractol *f, int color)
{
	(f->img.pxl_ptr[(y * f->img.len) + (x * (f->img.bpp / 8))]) = color;
}

void	brot_or_juli(t_complex *c, t_complex *z, t_fractol *f)
{
	if (ft_strcmp(f->name, "julia"))
	{
		c->x = f->j_x;
		c->y = f->j_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	f_pixel(int x, int y, t_fractol *f)
{
	int			i;
	int			color;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = (scale(x, map_values(-2, +2, 0, WIDTH)) * f->zoom) + f->x_move;
	z.y = (scale(y, map_values(+2, -2, 0, HEIGHT)) * f->zoom) + f->y_move;
	brot_or_juli(&c, &z, f);
	while (i < f->def_iterations)
	{
		z = add_complex(complexify(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > f->esc_value)
		{
			color = (int)scale(i, map_values(0x3EB489, 0xFF3300, 0, f->def_iterations));
			create_pixel(x, y, f, color);
			return ;
		}
		i++;
	}
	create_pixel(x, y, f, WHITE);
}

int	f_render(t_fractol *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			f_pixel(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_con, f->mlx_win, f->img.img_ptr, 0, 0);
	return (0);
}
