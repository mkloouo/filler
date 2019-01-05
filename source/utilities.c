/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:57:58 by modnosum          #+#    #+#             */
/*   Updated: 2019/01/05 13:32:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <stdlib.h>

int			get_distance(t_point p1, t_point p2)
{
	int dist;

	dist = 0;
	dist += (p1.x >= p2.x) ? (p1.x - p2.x) : (p2.x - p1.x);
	dist += (p1.y >= p2.y) ? (p1.y - p2.y) : (p2.y - p1.y);
	return (dist);
}

int			valid_coords(t_filler *filler, t_point coords)
{
	return ((coords.y >= 0 && coords.y < filler->map.size.height) &&
			(coords.x >= 0 && coords.x < filler->map.size.width));
}

void		create_arrays(t_filler *filler)
{
	count_pieces(filler);
	if (filler->me_arr)
		free(filler->me_arr);
	if (filler->enemy_arr)
		free(filler->enemy_arr);
	filler->me_arr = malloc(filler->me_count * sizeof(t_point));
	filler->enemy_arr = malloc(filler->enemy_count * sizeof(t_point));
	init_pieces_count(filler);
}

void		initialize_arrays(t_filler *filler)
{
	t_point	i;

	create_arrays(filler);
	i.y = 0;
	while (i.y < filler->map.size.height)
	{
		i.x = 0;
		while (i.x < filler->map.size.width)
		{
			if (filler->map.data[i.y][i.x] == filler->me.c)
			{
				filler->me_arr[filler->me_count] = i;
				filler->me_count++;
			}
			else if (filler->map.data[i.y][i.x] == filler->enemy.c ||
					filler->map.data[i.y][i.x] == filler->enemy.c + 32)
			{
				filler->enemy_arr[filler->enemy_count] = i;
				filler->enemy_count++;
			}
			i.x++;
		}
		i.y++;
	}
}

int			check_if_enemy_play(t_filler *filler)
{
	t_point	i;

	filler->enemy_play = 0;
	i.y = 0;
	while (i.y < filler->map.size.height)
	{
		i.x = 0;
		while (i.x < filler->map.size.width)
		{
			if (filler->map.data[i.y][i.x] == filler->enemy.c ||
				filler->map.data[i.y][i.x] == filler->enemy.c + 32)
			{
				if (filler->map.data[i.y][i.x] == filler->enemy.c + 32)
					filler->enemy_play = 1;
				filler->enemy_count++;
			}
			i.x++;
		}
		i.y++;
	}
	if (filler->enemy_play == 1 ||
		(filler->enemy_play == 0 && filler->enemy_count == 1))
		return (1);
	return (0);
}
