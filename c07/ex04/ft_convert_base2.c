/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:18:43 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/10 12:03:57 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		if (base [i] == 32 || (base[i] <= 13 && base[i] >= 9)
			|| base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int	ft_power(int a, int pow)
{
	if (pow == 0)
		return (1);
	return (a * ft_power(a, pow - 1));
}

int	ft_nbrlen(long nb, int len)
{
	int	i;

	i = 1;
	while (nb / len != 0)
	{
		nb /= len;
		i++;
	}
	return (i);
}

char	*ft_write_number(long nb, char *base, int len, int k)
{
	long	pow;
	char	*str;
	int		size;
	int		i;

	size = ft_nbrlen(nb, len);
	pow = ft_power(len, size - 1);
	if (k == 1)
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	if (k == 1)
		str[i++] = '-';
	while (i < size)
	{
		str[i] = base[nb / pow];
		nb %= pow;
		pow /= len;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		len;
	int		k;

	len = 0;
	while (base[len])
		len++;
	k = 0;
	if (ft_check(base, len))
	{
		nb = nbr;
		if (nb < 0)
		{
			k = 1;
			nb = -nb;
		}
		return (ft_write_number(nb, base, len, k));
	}
	return (NULL);
}
