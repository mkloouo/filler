/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:06:54 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/07 03:17:56 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stddef.h>
# include <sys/types.h>

typedef enum		e_player_type
{
	FIRST_PLAYER = 'O',
	SECOND_PLAYER = 'X'
}					t_player_type;

typedef struct		s_upoint
{
	size_t			y;
	size_t			x;
}					t_upoint;

typedef struct		s_player
{
	t_player_type	type;
	t_upoint		pos;
}					t_player;

typedef struct		s_data
{
	t_player		me;
	t_player		enemy;
	t_upoint		map_size;
	t_upoint		piece_size;
}					t_data;

void				parse_input(char *input, t_data *data);

#endif
