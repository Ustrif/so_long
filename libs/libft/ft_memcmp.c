/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:48:10 by raydogmu          #+#    #+#             */
/*   Updated: 2024/10/19 16:14:10 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1x;
	unsigned char	*s2x;

	i = 0;
	s1x = (unsigned char *) s1;
	s2x = (unsigned char *) s2;
	while (i < n)
	{
		if (s1x[i] != s2x[i])
			return (s1x[i] - s2x[i]);
		i++;
	}
	return (0);
}
