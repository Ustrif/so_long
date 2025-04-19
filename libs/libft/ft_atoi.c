/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:28:44 by raydogmu          #+#    #+#             */
/*   Updated: 2024/10/14 12:30:28 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	say;
	int	l;

	say = 0;
	l = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			l = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		say = (say * 10) + *str - '0';
		str++;
	}
	return (l * say);
}
