/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:39:13 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/08 17:13:08 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *tab)
{
	while (*tab)
		write(1, tab++, 1);
}

void	ft_print_comma(char *tab)
{
	int	i;

	i = 0;
	while (tab[i + 1] && tab[i] + 1 == tab[i + 1])
		i++;
	if (tab[i] != '9')
		write(1, ", ", 2);
}

void	ft_combn(char *tab, int k, int n)
{
	if (k != 0)
		tab[k] = tab[k - 1] + 1;
	while (tab[k] <= '9')
	{
		if (n - 1 == k)
		{
			ft_putstr(tab);
			ft_print_comma(tab);
		}
		else
			ft_combn(tab, k + 1, n);
		tab[k]++;
	}
}

void	ft_print_combn(int n)
{
	char	tab[10];

	tab[0] = '0';
	if (n < 10 && n > 0)
	{
		tab[n] = '\0';
		ft_combn(tab, 0, n);
	}
}
