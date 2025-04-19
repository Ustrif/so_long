/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:42:29 by raydogmu          #+#    #+#             */
/*   Updated: 2025/03/09 09:58:19 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCES_H
# define SOURCES_H

# include "../libs/minilibx/mlx.h"

typedef struct s_map {
	char	**map;
	int		row;
	int		col;
	int		**visited;
	int		found_c;
	int		found_e;
}	t_map;

typedef struct s_map1
{
	void	*img_player;
	void	*img_wall;
	void	*img_exit;
	void	*img_free;
	void	*img_col;
	char	**map;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectible_num;
	int		player_move;
	int		colomn_num;
	int		row_num;
	void	*mlx;
	void	*mlx_win;
}	t_map1;

void	ft_printf(const char *str, ...);
int		file_check(char *filename);
int		get_row_num(char *filename);
int		get_colomn_num(char *filename);
void	free_map(char **map);
char	**get_map(char *filename);
int		is_map_rectangular(char *filename);
char	**get_trimmed_map(char *filename);
int		check_walls(char *filename);
int		is_map_has_valid_chars(char *filename);
int		**init_map(int row, int col);
void	dfs(t_map *m, int x, int y);
int		check_way(char *filename);
int		main_checker(char *filename);
void	get_start_coordinate(char **map, int *start_x, int *start_y);
int		count_total_c(char **map);
void	get_exit_coordinate(char **map, int *start_x, int *start_y);
t_map1	*get_struct(char *filename);
void	fill_map(t_map1 *st);
void	close_program(t_map1 *st, int free, char *text);
int		key_hook(int keycode, t_map1 *st);
int		exit_button(t_map1 *st);
void	print_step(void);
void	move_w(t_map1 *st);
void	move_a(t_map1 *st);
void	move_s(t_map1 *st);
void	move_d(t_map1 *st);
#endif
