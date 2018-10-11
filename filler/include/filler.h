/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:06:54 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/11 01:14:01 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stddef.h>
# include <sys/types.h>

# include <ft/io.h>
# include <ft/conv.h>
# include <ft/string.h>
# include <ft/memory.h>

# define PLAYER_CHAR 'p'
# define PLAYER_LINE "$$$ exec p"
# define PLAYER_LINE_LEN (10)

# define MAP_FIELD_START (4)
# define MAP_LINE "Plateau"
# define MAP_LINE_LEN (7)

# define PIECE_LINE "Piece"
# define PIECE_LINE_LEN (5)

typedef enum	e_player
{
	FIRST_PLAYER = 'o',
	SECOND_PLAYER = 'x'
}				t_player;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_field
{
	t_point		size;
	char		**data;
}				t_field;

typedef struct	s_filler
{
	t_player	me;
	t_player	enemy;
	t_field		map;
	t_field		piece;
	t_point		step;
}				t_filler;

void			filler_init(t_filler *filler);
void			filler_free_field(t_field *field, size_t move);

void			filler_run(t_filler *filler);

t_bool			filler_parse(t_filler *filler, char *line);
t_bool			filler_parse_players(t_filler *filler);
void			filler_read_field(t_field *field, char const *header,
				size_t move);

void			filler_act(t_filler *filler);
void			filler_algo(t_filler *filler);

void			filler_end(t_filler *filler);

#endif
