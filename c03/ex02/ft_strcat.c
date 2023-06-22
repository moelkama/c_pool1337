/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:30:26 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/01 17:15:50 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char	*add;

	add = str;
	while (*str)
		str++;
	return (str - add);
}

char	*ft_strcat(char *dest, char *src)
{
	int	l;
	int	i;

	l = ft_strlen(dest);
	i = 0;
	while (src[i])
		dest[l++] = src[i++];
	dest [l] = '\0';
	return (dest);
}
