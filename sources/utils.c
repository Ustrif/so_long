/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:42:24 by raydogmu          #+#    #+#             */
/*   Updated: 2025/03/09 09:51:09 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../libs/get_next_line/get_next_line.h"
#include "../libs/libft/libft.h"

int	file_check(char *filename)
{
	int		fd;
	char	buffer;
	int		readed;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	else
	{
		readed = read(fd, &buffer, 1);
		close(fd);
		if (!(readed > 0))
			return (1);
	}
	return (0);
}

int	get_row_num(char *filename)
{
	int			fd;
	static int	result = -2;
	char		*line;

	if (result != -2)
		return (result);
	result = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
			result++;
		else
			break ;
		free(line);
	}
	close(fd);
	return (result);
}

int	get_colomn_num(char *filename)
{
	int		fd;
	int		result;
	char	*line;

	result = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	close(fd);
	if (line == NULL)
		return (-1);
	result = ft_strlen(line);
	free(line);
	return (result - 1);
}

char	**get_map1(char *filename, int fd)
{
	int		i;
	int		row_num;
	char	**result;

	row_num = get_row_num(filename);
	if (row_num < 3)
		return (NULL);
	i = 0;
	result = malloc((row_num + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (i < row_num + 1)
	{
		result[i] = get_next_line(fd);
		if (result[i] == NULL)
			break ;
		i++;
	}
	return (result);
}

char	**get_map(char *filename)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = get_map1(filename, fd);
	if (map == NULL)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}
