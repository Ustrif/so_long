/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:42:08 by raydogmu          #+#    #+#             */
/*   Updated: 2025/03/09 09:53:33 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "sources.h"

int	count_total_c(char **map)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

void	get_start_coordinate(char **map, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*start_x = i;
				*start_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	free_init_struct(t_map *m)
{
	int	i;

	if (!m)
		return ;
	if (m->visited)
	{
		i = 0;
		while (i < m->row)
		{
			free(m->visited[i]);
			i++;
		}
		free(m->visited);
	}
	if (m->map)
		free_map(m->map);
	free(m);
}

int	check_way1(t_map *st, char *filename)
{
	char	**map;
	int		start_x;
	int		start_y;

	map = get_trimmed_map(filename);
	if (map == NULL)
		return (1);
	st->visited = init_map(st->row, st->col);
	if (st->visited == NULL)
	{
		free_map(map);
		return (1);
	}
	st->map = map;
	get_start_coordinate(map, &start_x, &start_y);
	dfs(st, start_x, start_y);
	if (st->found_e && count_total_c(map) == st->found_c)
		return (0);
	return (1);
}

int	check_way(char *filename)
{
	t_map	*st_map;
	int		result;

	st_map = (t_map *)malloc(sizeof(t_map));
	if (st_map == NULL)
		return (1);
	st_map->found_c = 0;
	st_map->found_e = 0;
	st_map->row = get_row_num(filename);
	st_map->col = get_colomn_num(filename);
	result = check_way1(st_map, filename);
	free_init_struct(st_map);
	return (result);
}
