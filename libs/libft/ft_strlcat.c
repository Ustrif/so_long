/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:00:37 by raydogmu          #+#    #+#             */
/*   Updated: 2024/10/08 14:04:00 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dest_l;
	unsigned int	src_l;
	unsigned int	i;

	dest_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = 0;
	if (dstsize <= dest_l)
		return (dstsize + src_l);
	while (src[i] && (dest_l + i + 1 < dstsize))
	{
		dst[dest_l + i] = src[i];
		i++;
	}
	dst[dest_l + i] = '\0';
	return (dest_l + src_l);
}
