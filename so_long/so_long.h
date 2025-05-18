/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:25:52 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/30 22:25:58 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "libraries/ft_printf/ft_printf.h"
# include "libraries/libft/libft.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
}			t_game;

# define KEY_ESC 65307

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEYPRESS 2
# define DESTROYNOTIFY 17

int			is_valid_argv(char *av);
void		render_img(t_game *game, void *image, int x, int y);
int			render_map(t_game *game);
void		init_game(t_game *game);
char		**read_map(char *path);
int			is_valide_map(t_game *game);
void		game_start(t_game *game);
void		move_w(t_game *game);
void		move_d(t_game *game);
void		move_s(t_game *game);
void		move_a(t_game *game);
int			exit_game(t_game *game, int exit_type);
void		free_map(char **map);
void		finish_game_with_success(t_game *game);
int			has_valid_solution(t_game *game);
int			has_valid_solution_2(t_game *game);
void		find_player_position(char **map, int *p_row, int *p_col);
#endif