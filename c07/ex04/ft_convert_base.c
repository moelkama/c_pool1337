/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:14:23 by moelkama          #+#    #+#             */
/*   Updated: 2023/02/02 17:34:19 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check(char *str, int len);
char	*ft_write_number(long nb, char *base, int len);
char	*ft_putnbr_base(int nbr, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_return_nbr(char *str, char *base, int k)
{
	int	i;
	int	j;
	int	pow;
	int	nbr;

	nbr = 0;
	i = 0;
	while (ft_find(base, str[i]) != -1)
		i++;
	i--;
	pow = 1;
	while (i >= 0)
	{
		j = ft_find(base, str[i]);
		nbr += j * pow;
		pow *= ft_strlen(base);
		i--;
	}
	if (k % 2 != 0)
		return (-nbr);
	return (nbr);
}

int	ft_atoi_base(char *str, char *base)
{
	int	k;
	int	nbr;

	if (ft_check(base, ft_strlen(base)))
	{
		while (*str == 32 || (*str <= 13 && *str >= 9))
			str++;
		k = 0;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				k++;
			str++;
		}
		nbr = ft_return_nbr(str, base, k);
		return (nbr);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!ft_check(base_from, ft_strlen(base_from))
		|| !ft_check(base_to, ft_strlen(base_to)))
		return (NULL);
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
}
#include <stdio.h>
int	main(int c, char **v)
{
	printf("%s\n", ft_convert_base(v[1], v[2], v[3]));
}
