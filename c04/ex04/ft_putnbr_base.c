/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:34:58 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/04 14:01:08 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(char *base, int len)
{
	int	i;
	int	j;

	if (base[0] == '\0' || len == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base [j] == base[i])
				return (0);
			j++;
		}
		if (base [i] <= 32 || base[i] == 127
			|| base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

void	ft_write_number(long nb, char *base, int len)
{
	long	n;
	long	pow;

	n = nb;
	pow = 1;
	while (n / len != 0)
	{
		pow *= len ;
		n /= len;
	}
	while (pow >= 1)
	{
		ft_putchar(base[nb / pow]);
		nb %= pow;
		pow /= len;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	nb;

	len = 0;
	while (base[len])
		len++;
	if (ft_check(base, len))
	{
		nb = nbr;
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		ft_write_number(nb, base, len);
	}
}
