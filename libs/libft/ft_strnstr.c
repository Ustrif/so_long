/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:15:10 by raydogmu          #+#    #+#             */
/*   Updated: 2024/10/12 13:02:58 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	y;

	i = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (haystack[i] && (size_t) i < len)
	{
		y = 0;
		while (needle[y] != '\0' && (haystack[i + y] == needle[y])
			&& (size_t) i + y < len)
		{
			y++;
		}
		if (needle[y] == '\0')
			return ((char *) &haystack[i]);
		i++;
	}
	return (NULL);
}
