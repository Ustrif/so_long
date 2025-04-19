/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:42:19 by raydogmu          #+#    #+#             */
/*   Updated: 2025/03/09 10:03:41 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "sources.h"

int	is_map_rectangular(char *filename)
{
	char	**map;
	size_t	colomn_num;
	int		i;
	int		result;

	map = get_map(filename);
	if (map == NULL)
		return (1);
	i = 0;
	result = 0;
	colomn_num = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i + 1] == NULL && ft_strlen(map[i]) == colomn_num - 1)
			break ;
		if (ft_strlen(map[i]) != colomn_num || (map[i + 1] == NULL
				&& ft_strlen(map[i]) != colomn_num - 1))
		{
			result = 1;
			break ;
		}
		i++;
	}
	free_map(map);
	return (result);
}

char	**get_trimmed_map1(char **map, int row_num)
{
	int		i;
	char	**result;

	result = malloc(row_num * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i != row_num - 1)
	{
		result[i] = ft_strtrim(map[i], "\n");
		if (result[i] == NULL)
		{
			free_map(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**get_trimmed_map(char *filename)
{
	char	**map;
	int		row_num;
	char	**result;

	row_num = get_row_num(filename);
	if (row_num < 3)
		return (NULL);
	row_num++;
	map = get_map(filename);
	if (map == NULL)
		return (NULL);
	result = get_trimmed_map1(map, row_num);
	free_map(map);
	return (result);
}

int	check_walls1(char **map, int row_num, int colomn_num)
{
	int	i;

	i = 0;
	while (i != colomn_num)
	{
		if (map[0][i] != '1' || map[row_num - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i != row_num)
	{
		if (map[i][0] != '1' || map[i][colomn_num - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char *filename)
{
	char	**map;
	int		row_num;
	int		colomn_num;

	map = get_trimmed_map(filename);
	if (map == NULL)
		return (1);
	row_num = get_row_num(filename);
	colomn_num = get_colomn_num(filename);
	if (row_num < 3 || colomn_num < 3)
	{
		free_map(map);
		return (1);
	}
	if (check_walls1(map, row_num, colomn_num))
	{
		free_map(map);
		return (1);
	}
	free_map(map);
	return (0);
}
