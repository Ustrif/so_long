/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:38:18 by raydogmu          #+#    #+#             */
/*   Updated: 2024/10/14 13:17:11 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*si;
	unsigned char	*di;

	if (dst == NULL && src == NULL)
		return (0);
	x = 0;
	si = (unsigned char *) src;
	di = (unsigned char *) dst;
	while (x < n)
	{
		di[x] = si[x];
		x++;
	}
	return (dst);
}
