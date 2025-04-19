/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamefile1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:37:09 by raydogmu          #+#    #+#             */
/*   Updated: 2025/03/09 09:57:56 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"
#include "../libs/libft/libft.h"

void	fill_map1(t_map1 *st, int i, int j)
{
	if (st->map[i][j] == '1')
		mlx_put_image_to_window(st->mlx, st->mlx_win,
			st->img_wall, j * 32, i * 32);
	if (st->map[i][j] == '0')
		mlx_put_image_to_window(st->mlx, st->mlx_win,
			st->img_free, j * 32, i * 32);
	if (st->map[i][j] == 'E')
		mlx_put_image_to_window(st->mlx, st->mlx_win,
			st->img_exit, j * 32, i * 32);
	if (st->map[i][j] == 'P')
		mlx_put_image_to_window(st->mlx, st->mlx_win,
			st->img_player, j * 32, i * 32);
	if (st->map[i][j] == 'C')
		mlx_put_image_to_window(st->mlx, st->mlx_win,
			st->img_col, j * 32, i * 32);
}

void	fill_map(t_map1 *st)
{
	int	i;
	int	j;

	i = 0;
	while (st->map[i])
	{
		j = 0;
		while (st->map[i][j])
		{
			fill_map1(st, i, j);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_map1 *st)
{
	if (keycode == 65307)
		close_program(st, 1, "ESC");
	if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100)
		print_step();
	if (keycode == 119)
		move_w(st);
	if (keycode == 115)
		move_s(st);
	if (keycode == 97)
		move_a(st);
	if (keycode == 100)
		move_d(st);
	return (0);
}

int	exit_button(t_map1 *st)
{
	close_program(st, 1, "EXIT BUTTON");
	return (0);
}
