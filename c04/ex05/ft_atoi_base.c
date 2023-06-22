/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:11:08 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/03 11:58:27 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) == 1 || str[0] == '\0')
		return (0);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		if (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
			return (0);
		else if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	k;

	if (ft_check(base))
	{
		while (*str == ' ' || (*str <= 13 && *str >= 9))
			str++;
		k = 0;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				k++;
			str++;
		}
        return (ft_return_nbr(str, base, k));
	}
	return (0);
}
