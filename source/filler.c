/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:58:34 by modnosum          #+#    #+#             */
/*   Updated: 2019/01/05 13:32:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <ft/io.h>
#include <ft/conv.h>
#include <ft/memory.h>
#include <ft/string.h>

void			find_players_position(t_filler *filler)
{
	t_point	iter;

	iter.y = 0;
	while (iter.y < filler->map.size.height)
	{
		iter.x = 0;
		while (iter.x < filler->map.size.width)
		{
			if (filler->map.data[iter.y][iter.x] == filler->me.c)
			{
				filler->me.pos.y = iter.y;
				filler->me.pos.x = iter.x;
			}
			else if (filler->map.data[iter.y][iter.x] == filler->enemy.c ||
					filler->map.data[iter.y][iter.x] == filler->enemy.c + 32)
			{
				filler->enemy.pos.y = iter.y;
				filler->enemy.pos.x = iter.x;
			}
			iter.x++;
		}
		iter.y++;
	}
	filler->first_time = 0;
	filler->enemy_play = 0;
}

void			get_movement_direction(t_filler *filler)
{
	filler->direction.x = ((filler->enemy.pos.x - filler->me.pos.x > 0) ?
							filler->map.size.width - 1 : 0);
	filler->direction.y = ((filler->enemy.pos.y - filler->me.pos.y > 0) ?
							filler->map.size.height - 1 : 0);
}

void			modnosum_filler(t_filler *filler)
{
	char		*line;

	while (ft_get_string(IO_STDIN, &line, LINE_BREAK) > 0)
	{
		if (ft_strnequ("Plateau ", line, 8))
		{
			parse_field(&filler->map, 4, line);
			if (filler->first_time == 1)
			{
				find_players_position(filler);
				get_movement_direction(filler);
			}
		}
		else if (ft_strnequ("Piece ", line, 6))
		{
			parse_field(&filler->piece, 0, line);
			filler_algo(filler);
		}
		free(line);
	}
}

int				main(void)
{
	t_filler	filler;
	char		*line;

	ft_memset(&filler, 0, sizeof(t_filler));
	line = NULL;
	if ((ft_get_string(IO_STDIN, &line, LINE_BREAK) >= 0) && line &&
		ft_strlen(line) > 10 && !ft_strncmp(line, "$$$ exec p", 10))
	{
		filler.me.c = (char)(line[10] == '1') ? 'O' : 'X';
		filler.enemy.c = (char)(line[10] == '1') ? 'X' : 'O';
		free(line);
		modnosum_filler(&filler);
	}
	else
		return (1);
	return (0);
}
