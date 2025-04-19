/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:42:16 by raydogmu          #+#    #+#             */
/*   Updated: 2025/03/09 09:52:46 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "sources.h"

int	is_map_has_valid_chars1(char **map, int *p, int *c, int *ex)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				*ex = *ex + 1;
			else if (map[i][j] == 'C')
				*c = *c + 1;
			else if (map[i][j] == 'P')
				*p = *p + 1;
			else if (!(map[i][j] == '1' || map[i][j] == '0'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_map_has_valid_chars(char *filename)
{
	char	**map;
	int		result;
	int		p;
	int		c;
	int		ex;

	p = 0;
	c = 0;
	ex = 0;
	map = get_trimmed_map(filename);
	if (map == NULL)
		return (1);
	result = is_map_has_valid_chars1(map, &p, &c, &ex);
	free_map(map);
	if (result == 0 && p == 1 && c != 0 && ex == 1)
		return (0);
	return (1);
}

int	**init_map1(int row, int col)
{
	int	i;
	int	j;
	int	**map;

	map = (int **)malloc(row * sizeof(int *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
		map[i] = (int *)malloc(col * sizeof(int));
		if (map[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(map[j]);
				j++;
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int	**init_map(int row, int col)
{
	int	**map;
	int	i;
	int	j;

	map = init_map1(row, col);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
