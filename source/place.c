/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:59:51 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/23 21:43:10 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		find_players_position(t_filler *filler)
{
	t_point	iter;

	iter.y = 0;
	while (iter.y < filler->map.size.height && (iter.x = 0) == 0)
	{
		while (iter.x < filler->map.size.width)
		{
			if (filler->map.data[iter.y][iter.x] == filler->me.c)
				filler->me.pos = iter;
			else if (filler->map.data[iter.y][iter.x] == filler->enemy.c)
				filler->enemy.pos = iter;
			iter.x++;
		}
		iter.y++;
	}
}

void		get_movement_direction(t_filler *filler)
{
	if (filler->enemy.pos.x > filler->me.pos.x &&
		filler->enemy.pos.y > filler->me.pos.y)
		filler->direction = (t_point){filler->map.size.width - 1,
			filler->map.size.height - 1};
	else
		filler->direction = (t_point){0, 0};
}

void		get_distance(t_filler *filler)
{
	(void)filler;
	// filler->distance = ft_abs(filler->enemy.pos.x - filler->me.pos.x)
	// + ft_abs(filler->enemy.pos.y - filler->me.pos.y)
}

void		move_in_direction(t_filler *filler)
{
	(void)filler;
}

void		place_piece(t_filler *filler)
{
	if (filler->first_time)
		find_players_position(filler);
	get_movement_direction(filler);
	get_distance(filler);
	move_in_direction(filler);
}
