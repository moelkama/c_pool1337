/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:47:06 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/06 13:28:30 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	n = nb;
	while (power > 1)
	{
		n *= nb;
		power--;
	}
	return (n);
}
