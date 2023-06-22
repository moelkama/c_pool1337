/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:57:33 by moelkama          #+#    #+#             */
/*   Updated: 2022/07/21 10:54:05 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nbr(int i, int j, int k)
{
	i += 48;
	j += 48;
	k += 48;
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i != 55)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 9)
	{
		j = i +1;
		while (j <= 9)
		{
			k = j +1;
			while (k <= 9)
			{
				ft_print_nbr(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
