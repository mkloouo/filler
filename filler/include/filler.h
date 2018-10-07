/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:06:54 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/07 17:11:37 by modnosum         ###   ########.fr       */
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

typedef struct		s_field
{
	t_upoint		size;
	char 			*data;
}					t_field;

typedef struct		s_data
{
	t_player		me;
	t_player		enemy;
	t_field			map;
	t_field			piece;
}					t_data;

void				parse_input(char *input, t_data *data);

#endif
