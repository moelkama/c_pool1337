/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:09:07 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/01 16:18:37 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (to_find[0] == '\0')
		return (str);
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] == to_find[i])
			i++;
		if (to_find[i] == '\0')
			return (str);
		str++;
	}
	return (0);
}
