/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:26:34 by moelkama          #+#    #+#             */
/*   Updated: 2022/07/23 14:18:57 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	power(int a, int i)
{
	if (i == 0)
		return (1);
	return (a * power(a, i -1));
}

void	ft_write_number(int nb, int pow, int k)
{
	char	c;

	while (pow > 0)
	{
		c = nb / power(10, pow) + 48;
		nb %= power(10, pow);
		write(1, &c, 1);
		pow--;
	}
	if (k == 1)
		nb++;
	nb += 48;
	write(1, &nb, 1);
}	

void	ft_putnbr(int nb)
{
	int	i;
	int	k;
	int	n;

	k = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			k = 1;
			nb++;
		}
		nb = -nb;
	}
	i = 0;
	n = nb;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	ft_write_number(nb, i, k);
}
