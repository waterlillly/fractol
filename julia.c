/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:42:50 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/21 13:04:53 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_julia(t_fractol *f, char **av)
{
	if (av[2][0] == 'a')
	{
		f->j_x = ft_atof("-0.162");
		f->j_y = ft_atof("1.04");
	}
	else if (av[2][0] == 'b')
	{
		f->j_x = ft_atof("0.3");
		f->j_y = ft_atof("-0.01");
	}
	else if (av[2][0] == 'c')
	{
		f->j_x = ft_atof("-1.476");
		f->j_y = ft_atof("0");
	}
	else if (av[2][0] == 'd')
	{
		f->j_x = ft_atof("0.28");
		f->j_y = ft_atof("0.008");
	}
	else
		return ;
}

void	julia(t_fractol *f, char **av)
{
	if (av[2] && av[3] && ft_isdouble(av[2]) && ft_isdouble(av[3]))
	{
		f->j_x = ft_atof(av[2]);
		f->j_y = ft_atof(av[3]);
	}
	else if (av[2] && ft_strlen(av[2]) == 1 && ft_isalpha(av[2][0])
		&& (av[2][0] >= 'a' && av[2][0] <= 'd'))
		choose_julia(f, av);
	else
	{
		f->j_x = ft_atof("-0.79");
		f->j_y = ft_atof("1.5");
		ft_printf("Arguments for Julia-set are not valid/do not exist.\n");
		ft_printf("Using these values: -0.79 +1.5\n");
		ft_printf("If you want to explore different sets try"
			"'./fractol julia' and add a letter from a-d at the end! :)\n");
	}
}
