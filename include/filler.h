/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:31:24 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/23 21:23:40 by modnosum         ###   ########.fr       */
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
	t_point		step;
	t_player	me;
	t_player	enemy;
	t_point		direction;
	unsigned	first_time:1;
}				t_filler;

void			parse_field(t_field *field, int offset, char const *pos_data);
void			free_field(t_field *field, int inset);

void			find_players_position(t_filler *filler);
void			get_movement_direction(t_filler *filler);
void			place_piece(t_filler *filler);

#endif
