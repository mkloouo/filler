/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:06:54 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/10 18:22:08 by modnosum         ###   ########.fr       */
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

typedef struct	s_point
{
	uint32_t 	x;
	uint32_t 	y;
}				t_point;

typedef struct	s_field
{
	t_point		size;
	char 		*data;
}				t_field;

typedef struct	s_filler
{
	t_field		piece;
	t_field		map;
}				t_filler;

void			filler_init(t_filler *filler);
void			filler_run(t_filler *filler);
void			filler_end(t_filler *filler);

void			filler_parse(t_filler *filler);

#endif
