/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:36:47 by raydogmu          #+#    #+#             */
/*   Updated: 2025/04/30 15:28:45 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"
#include "../libs/libft/libft.h"

void	init_struct(t_map1 *st)
{
	st->mlx = NULL;
	st->mlx_win = NULL;
	st->img_wall = NULL;
	st->img_col = NULL;
	st->img_player = NULL;
	st->img_exit = NULL;
	st->img_free = NULL;
	st->map = NULL;
	st->player_x = -1;
	st->player_y = -1;
	st->exit_x = -1;
	st->exit_y = -1;
	st->collectible_num = -1;
	st->player_move = 0;
	st->colomn_num = -1;
	st->row_num = -1;
}

void	free_struct(t_map1 *st)
{
	if (!st)
		return ;
	if (st->map != NULL)
		free_map(st->map);
	if (st->mlx_win != NULL)
	{
		mlx_clear_window(st->mlx, st->mlx_win);
		mlx_destroy_window(st->mlx, st->mlx_win);
	}
	if (st->img_wall != NULL)
		mlx_destroy_image(st->mlx, st->img_wall);
	if (st->img_free != NULL)
		mlx_destroy_image(st->mlx, st->img_free);
	if (st->img_player != NULL)
		mlx_destroy_image(st->mlx, st->img_player);
	if (st->img_exit != NULL)
		mlx_destroy_image(st->mlx, st->img_exit);
	if (st->img_col != NULL)
		mlx_destroy_image(st->mlx, st->img_col);
	if (st->mlx != NULL)
	{
		mlx_destroy_display(st->mlx);
		free(st->mlx);
	}
	free(st);
}

void	close_program(t_map1 *st, int free, char *text)
{
	ft_printf("Program was closed by: %s ", text);
	if (free)
		free_struct(st);
	exit(EXIT_SUCCESS);
}

int	init_mlx_struct(t_map1 *st)
{
	int	a;

	a = 32;
	st->mlx = mlx_init();
	if (!st->mlx)
		return (-1);
	st->mlx_win = mlx_new_window(st->mlx, st->colomn_num * 32,
			st->row_num * 32, "./so_long");
	if (!st->mlx)
		return (-1);
	st->img_wall = mlx_xpm_file_to_image(st->mlx,
			"textures/rock.xpm", &a, &a);
	st->img_col = mlx_xpm_file_to_image(st->mlx,
			"textures/chest.xpm", &a, &a);
	st->img_player = mlx_xpm_file_to_image(st->mlx,
			"textures/ghost.xpm", &a, &a);
	st->img_exit = mlx_xpm_file_to_image(st->mlx,
			"textures/exit.xpm", &a, &a);
	st->img_free = mlx_xpm_file_to_image(st->mlx,
			"textures/grass.xpm", &a, &a);
	if (!st->img_col || !st->img_player || !st->img_exit
		|| !st->img_free || !st->img_wall)
		return (-1);
	return (0);
}

t_map1	*get_struct(char *filename)
{
	char	**map;
	t_map1	*st;

	st = ft_calloc(1, sizeof(t_map1));
	if (st == NULL)
		return (NULL);
	init_struct(st);
	map = get_trimmed_map(filename);
	if (map == NULL)
	{
		free_struct(st);
		return (NULL);
	}
	st->map = map;
	st->colomn_num = ft_strlen(map[0]);
	st->row_num = get_row_num(filename);
	get_start_coordinate(map, &st->player_y, &st->player_x);
	st->collectible_num = count_total_c(map);
	get_exit_coordinate(map, &st->exit_y, &st->exit_x);
	if (init_mlx_struct(st) == -1)
	{
		close_program(st, 1, "MLX / IMAGE ERROR");
	}
	return (st);
}
