/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamefile2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:42:32 by raydogmu          #+#    #+#             */
/*   Updated: 2025/03/09 09:48:45 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"
#include "../libs/libft/libft.h"

void	print_step(void)
{
	static int	step = 1;

	ft_printf("Step counter: %d\n", step);
	step++;
}

void	move_w(t_map1 *st)
{
	if (st->map[st->player_y - 1][st->player_x] == 'E')
	{
		if (st->collectible_num == 0)
			close_program(st, 1, "CHEERS!");
		return ;
	}
	else if (st->map[st->player_y - 1][st->player_x] == 'C')
	{
		st->collectible_num -= 1;
		st->map[st->player_y - 1][st->player_x] = '0';
	}
	else if (st->map[st->player_y - 1][st->player_x] == 'P')
		st->map[st->player_y - 1][st->player_x] = '0';
	else if (st->map[st->player_y - 1][st->player_x] == '1')
		return ;
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_player,
		st->player_x * 32, (st->player_y - 1) * 32);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_free,
		st->player_x * 32, st->player_y * 32);
	st->player_y -= 1;
}

void	move_s(t_map1 *st)
{
	if (st->map[st->player_y + 1][st->player_x] == 'E')
	{
		if (st->collectible_num == 0)
			close_program(st, 1, "CHEERS!");
		return ;
	}
	else if (st->map[st->player_y + 1][st->player_x] == 'C')
	{
		st->collectible_num -= 1;
		st->map[st->player_y + 1][st->player_x] = '0';
	}
	else if (st->map[st->player_y + 1][st->player_x] == 'P')
		st->map[st->player_y + 1][st->player_x] = '0';
	else if (st->map[st->player_y + 1][st->player_x] == '1')
		return ;
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_player,
		st->player_x * 32, (st->player_y + 1) * 32);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_free,
		st->player_x * 32, st->player_y * 32);
	st->player_y += 1;
}

void	move_a(t_map1 *st)
{
	if (st->map[st->player_y][st->player_x - 1] == 'E')
	{
		if (st->collectible_num == 0)
			close_program(st, 1, "CHEERS!");
		return ;
	}
	else if (st->map[st->player_y][st->player_x - 1] == 'C')
	{
		st->collectible_num -= 1;
		st->map[st->player_y][st->player_x - 1] = '0';
	}
	else if (st->map[st->player_y][st->player_x - 1] == 'P')
		st->map[st->player_y][st->player_x - 1] = '0';
	else if (st->map[st->player_y][st->player_x - 1] == '1')
		return ;
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_player,
		(st->player_x - 1) * 32, st->player_y * 32);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_free,
		st->player_x * 32, st->player_y * 32);
	st->player_x -= 1;
}

void	move_d(t_map1 *st)
{
	if (st->map[st->player_y][st->player_x + 1] == 'E')
	{
		if (st->collectible_num == 0)
			close_program(st, 1, "CHEERS!");
		return ;
	}
	else if (st->map[st->player_y][st->player_x + 1] == 'C')
	{
		st->collectible_num -= 1;
		st->map[st->player_y][st->player_x + 1] = '0';
	}
	else if (st->map[st->player_y][st->player_x + 1] == 'P')
		st->map[st->player_y][st->player_x + 1] = '0';
	else if (st->map[st->player_y][st->player_x + 1] == '1')
		return ;
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_player,
		(st->player_x + 1) * 32, st->player_y * 32);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img_free,
		st->player_x * 32, st->player_y * 32);
	st->player_x += 1;
}
