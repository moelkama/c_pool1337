/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:15:39 by moelkama          #+#    #+#             */
/*   Updated: 2022/07/30 15:09:53 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int j;
	char	a;

	while(*str)
	{
		j = *str;
		if (*str >= 32 || *str <= 127)
		{
			j += 256; 
			a = j / 16;
			if (a <= 9 )
				a += 48;
			else
				a += 87;
			j %= 16;
			if (j <= 9)
				j += 48;
			else
				j += 87;
			str = j;
			write(1, "\\", 2);
			write(1, &a, 1);
		}
		write(1, &str, 1);
	}
}
int main(void)
{
	int	i = 255;
	ft_putstr_non_printable(i);
}
