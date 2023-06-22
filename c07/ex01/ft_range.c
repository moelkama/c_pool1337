/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:09:30 by moelkama          #+#    #+#             */
/*   Updated: 2022/08/10 11:24:25 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	size;
	int	i;

	size = max - min;
	if (min < max)
	{
		array = malloc(size * sizeof(int));
		if (!array)
			return (NULL);
		i = 0;
		while (min < max)
			array[i++] = min++;
	}
	else
		array = NULL;
	return (array);
}
