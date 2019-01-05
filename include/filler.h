/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:31:24 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/23 21:43:08 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct	s_size
{
	int			width;
	int			height;
}				t_size;

typedef struct	s_field
{
	t_size		size;
	char		**data;
}				t_field;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_player
{
	char		c;
	t_point		pos;
}				t_player;

typedef struct	s_filler
{
	t_field		map;
	t_field		piece;
	t_player	me;
	t_player	enemy;
	t_point		direction;
	int			distance;
	unsigned	first_time;
	int			me_count;
	int			enemy_count;
	int			enemy_play;
	t_point		*me_arr;
	t_point		*enemy_arr;
}				t_filler;

void			modnosum_filler(t_filler *filler);
void			get_movement_direction(t_filler *filler);
void			find_players_position(t_filler *filler);

void			parse_field(t_field *field, int offset, char *data);
void			free_field(t_field *field, int inset);

void			filler_algo(t_filler *filler);
t_point			find_coords(t_filler *filler);
int				place_piece(t_filler *filler, t_point me, t_point *tmp_coords);
int				try_place(t_filler *filler, t_point coords);
t_point			find_place(t_filler *filler);

void			count_pieces(t_filler *filler);
void			init_pieces_count(t_filler *filler);
void			big_map(t_filler *filler, t_point *coords);
void			small_map(t_filler *filler, t_point *coords);

int				check_if_enemy_play(t_filler *filler);
void			initialize_arrays(t_filler *filler);
void			create_arrays(t_filler *filler);
int				valid_coords(t_filler *filler, t_point coords);
int				get_distance(t_point p1, t_point p2);

#endif
