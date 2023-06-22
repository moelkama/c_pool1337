/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:24:12 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/06 13:30:17 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	n = nb;
	while (nb > 1)
		n *= --nb;
	return (n);
}
