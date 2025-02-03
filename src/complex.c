/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:37:12 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/21 17:47:23 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_map	map_values(double nl, double nh, double ol, double oh)
{
	t_map	map;

	map.nl = nl;
	map.nh = nh;
	map.ol = ol;
	map.oh = oh;
	return (map);
}

double	scale(double i, t_map map)
{
	double	result;

	result = (map.nh - map.nl) * (i - map.ol) / (map.oh - map.ol) + map.nl;
	return (result);
}

t_complex	add_complex(t_complex res, t_complex c)
{
	t_complex	result;

	result.x = res.x + c.x;
	result.y = res.y + c.y;
	return (result);
}

t_complex	complexify(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
