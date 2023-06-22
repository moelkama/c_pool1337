/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:41:23 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/07 18:20:23 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	ft_find_diff(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*swp;
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			k = ft_find_diff(argv[i], argv[j]);
			if (argv[j][k] < argv[i][k])
			{
				swp = argv[i];
				argv[i] = argv[j];
				argv[j] = swp;
			}
			j++;
		}
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
