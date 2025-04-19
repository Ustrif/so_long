/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:18:12 by raydogmu          #+#    #+#             */
/*   Updated: 2024/10/08 17:51:29 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*x;

	x = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		x[i] = (unsigned char) 0;
		i++;
	}
	return (s);
}
