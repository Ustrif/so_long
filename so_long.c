/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:10:25 by raydogmu          #+#    #+#             */
/*   Updated: 2025/03/09 09:55:04 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sources/sources.h"

int	forhook(t_map1 *st)
{
	int	px;
	int	py;

	px = 1;
	py = 1;
	get_start_coordinate(st->map, &py, &px);
	mlx_clear_window(st->mlx, st->mlx_win);
	fill_map(st);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_free,
		px * 32, py * 32);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_player,
		st->player_x * 32, st->player_y * 32);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map1	*st;

	st = NULL;
	if (argc != 2 || main_checker(argv[1]))
		close_program(st, 0, "ARGUMENT ERROR \n");
	st = get_struct(argv[1]);
	if (st == NULL)
		close_program(st, 0, "MEMORY ERROR");
	mlx_key_hook(st->mlx_win, key_hook, st);
	mlx_hook(st->mlx_win, 17, 0, exit_button, st);
	mlx_expose_hook(st->mlx_win, forhook, st);
	mlx_loop(st->mlx);
	return (0);
}
