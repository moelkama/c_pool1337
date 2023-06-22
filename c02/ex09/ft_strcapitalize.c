/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:39:30 by moelkama          #+#    #+#             */
/*   Updated: 2022/07/28 13:15:50 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	else if (c <= 'z' && c >= 'a')
		return (2);
	else if (c <= '9' && c >= '0')
		return (3);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check(str[i]) == 2 && check(str[i - 1]) == 0)
			str[i] -= 32;
		else if (check(str[i]) == 1 && check(str[i - 1]) != 0)
			str[i] += 32;
        i++;
	}
	return (str);
}
