/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:28:51 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/10 11:38:45 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len_size(int size, char **strs, char *sep)
{
	int	str_size;
	int	i;
	int	j;

	str_size = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		str_size += j;
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	if (size > 0)
		str_size += (size - 1) * i;
	return (str_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		size_str;
	int		index;
	int		i;
	int		j;

	size_str = ft_len_size(size, strs, sep);
	str = (char *)malloc((size_str + 1) * sizeof(char));
	if (!str)
		return (0);
	index = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[index++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			str[index++] = sep[j++];
		i++;
	}
	if (size > 0)
		str[index] = '\0';
	return (str);
}
