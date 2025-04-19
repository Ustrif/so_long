/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:42:04 by raydogmu          #+#    #+#             */
/*   Updated: 2025/03/09 09:54:38 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"
#include "../libs/libft/libft.h"

void	dfs(t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || x >= m->row || y >= m->col
		|| m->map[x][y] == '1' || m->visited[x][y])
		return ;
	m->visited[x][y] = 1;
	if (m->map[x][y] == 'C')
		m->found_c++;
	if (m->map[x][y] == 'E')
	{
		m->found_e = 1;
		return ;
	}
	dfs(m, x + 1, y);
	dfs(m, x - 1, y);
	dfs(m, x, y + 1);
	dfs(m, x, y - 1);
}

void	get_exit_coordinate(char **map, int *start_x, int *start_y)
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

int	name_check(char	*filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (filename[len - 1] == 'r' && filename[len - 2] == 'e'
		&& filename[len - 3] == 'b' && filename[len - 4] == '.')
		return (1);
	return (0);
}

int	main_checker(char *filename)
{
	if (!name_check(filename))
		return (1);
	if (file_check(filename))
		return (1);
	if (is_map_has_valid_chars(filename))
		return (1);
	if (is_map_rectangular(filename))
		return (1);
	if (check_walls(filename))
		return (1);
	if (check_way(filename))
		return (1);
	return (0);
}
