/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:12:20 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/21 17:44:15 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	if ((ac == 2 && ft_strcmp(av[1], "mandelbrot"))
		|| (ac >= 2 && ac <= 4 && ft_strcmp(av[1], "julia")))
	{
		f.name = av[1];
		if (ft_strcmp(f.name, "julia"))
			julia(&f, av);
		init_fractol(&f);
		f_render(&f);
		mlx_loop(f.mlx_con);
	}
	else
	{
		ft_putstr_fd("\033[91mError: Please use valid arguments!\n"
			"\t./fractol mandelbrot\n"
			"\t./fractol julia <number1> <number2>\n"
			"\t./fractol julia <letter from a-d>\n\e[0m", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
