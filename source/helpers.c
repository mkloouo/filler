/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:58:11 by modnosum          #+#    #+#             */
/*   Updated: 2019/01/05 13:32:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		small_map(t_filler *filler, t_point *coords)
{
	initialize_arrays(filler);
	*coords = find_coords(filler);
}

void		big_map(t_filler *filler, t_point *coords)
{
	if (check_if_enemy_play(filler))
	{
		initialize_arrays(filler);
		*coords = find_coords(filler);
	}
	else
	{
		find_players_position(filler);
		get_movement_direction(filler);
		*coords = find_place(filler);
	}
}

void		init_pieces_count(t_filler *filler)
{
	filler->me_count = 0;
	filler->enemy_count = 0;
}

void		count_pieces(t_filler *filler)
{
	t_point i;

	init_pieces_count(filler);
	i.y = 0;
	while (i.y < filler->map.size.height)
	{
		i.x = 0;
		while (i.x < filler->map.size.width)
		{
			if (filler->map.data[i.y][i.x] == filler->me.c)
				filler->me_count++;
			else if (filler->map.data[i.y][i.x] == filler->enemy.c ||
					filler->map.data[i.y][i.x] == filler->enemy.c + 32)
				filler->enemy_count++;
			i.x++;
		}
		i.y++;
	}
}
