/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:55:15 by moelkama          #+#    #+#             */
/*   Updated: 2022/07/23 14:18:07 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nbr(int nbr)
{
	int	i;
	int	j;

	i = nbr / 10 + 48;
	j = nbr % 10 + 48;
	write(1, &i, 1);
	write(1, &j, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print_nbr(i);
			write(1, " ", 1);
			ft_print_nbr(j);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
