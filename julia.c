/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:42:50 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/21 23:04:33 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_julia(t_fractol *f, char **av)
{
	if (av[2][0] == 'a')
	{
		f->j_x = ft_atod("-0.162");
		f->j_y = ft_atod("1.04");
	}
	else if (av[2][0] == 'b')
	{
		f->j_x = ft_atod("0.3");
		f->j_y = ft_atod("-0.01");
	}
	else if (av[2][0] == 'c')
	{
		f->j_x = ft_atod("-1.476");
		f->j_y = ft_atod("0");
	}
	else if (av[2][0] == 'd')
	{
		f->j_x = ft_atod("0.28");
		f->j_y = ft_atod("0.008");
	}
	else
		return ;
}

int	valid_julia(char **av)
{
	double	x;
	double	y;

	x = ft_atod(av[2]);
	y = ft_atod(av[3]);
	if (x > -2 && x < 2 && y > -2 && y < 2)
		return (1);
	return (0);
}

void	julia(t_fractol *f, char **av)
{
	if (av[2] && av[3] && ft_strlen(av[2]) <= 10 && ft_strlen(av[3]) <= 10
		&& ft_isdouble(av[2]) && ft_isdouble(av[3]) && valid_julia(av))
	{
		f->j_x = ft_atod(av[2]);
		f->j_y = ft_atod(av[3]);
	}
	else if (!av[3] && av[2] && ft_strlen(av[2]) == 1 && ft_isalpha(av[2][0])
		&& (av[2][0] >= 'a' && av[2][0] <= 'd'))
		choose_julia(f, av);
	else
	{
		f->j_x = ft_atod("-0.79");
		f->j_y = ft_atod("1.5");
		ft_printf("Arguments for Julia-set are not valid/do not exist.\n");
		ft_printf("Using these values: -0.79 +1.5\n");
		ft_printf("If you want to explore different sets try"
			"'./fractol julia' and add a letter from a-d at the end! :)\n");
	}
}
