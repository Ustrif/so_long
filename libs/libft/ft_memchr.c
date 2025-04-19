/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:54:31 by raydogmu          #+#    #+#             */
/*   Updated: 2024/10/08 18:36:09 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*di;
	size_t			x;

	di = (unsigned char *) s;
	x = 0;
	while (x < n)
	{
		if (di[x] == (unsigned char) c)
			return (di + x);
		x++;
	}
	return (NULL);
}
