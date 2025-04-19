/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:30:52 by raydogmu          #+#    #+#             */
/*   Updated: 2024/11/02 05:11:19 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*start;
	const char	*str;

	if (dst == NULL && src == NULL)
		return (0);
	start = (char *) dst;
	str = (const char *) src;
	if (start < str)
	{
		while (n)
		{
			*start++ = *str++;
			n--;
		}
	}
	else
	{
		start += n;
		str += n;
		while (n--)
			*(--start) = *(--str);
	}
	return (dst);
}
