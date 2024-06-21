/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:45:55 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/21 18:47:27 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdouble(char *nbr)
{
	int	x;
	int	d;

	x = 0;
	d = 0;
	if (!nbr)
		return (0);
	if (nbr[x] == '+' || nbr[x] == '-' )
		x++;
	while (nbr[x] && ft_isdigit(nbr[x]))
	{
		if (d >= 1 && nbr[x] == '.')
			return (0);
		else if (d < 1 && nbr[x] == '.')
			d++;
		x++;
	}
	if (nbr[x] == '\0' && nbr[x - 1] != '.')
		return (1);
	return (0);
}
