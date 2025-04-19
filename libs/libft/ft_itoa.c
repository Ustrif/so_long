/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:28:53 by raydogmu          #+#    #+#             */
/*   Updated: 2024/10/21 16:26:37 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	len(int n)
{
	int		i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	while (1)
	{
		i++;
		if (n / 10 == 0)
			break ;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		n_bas;

	n_bas = len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(n_bas + 1);
	if (result == NULL)
		return (NULL);
	i = n_bas - 1;
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (i > -1)
	{
		result[i--] = n % 10 + '0';
		if (n / 10 == 0)
			break ;
		n = n / 10;
	}
	result[n_bas] = '\0';
	return (result);
}
