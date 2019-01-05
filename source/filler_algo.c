/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:58:40 by modnosum          #+#    #+#             */
/*   Updated: 2019/01/05 13:32:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <ft/io.h>
#include <stdlib.h>

#define CHK_PLR(map, c1, c2, c) ((map)[(c1).y + (c2).y][(c1).x + (c2).x] == (c))

t_point		find_place(t_filler *filler)
{
	t_point	i;
	t_point	tmp_coords;

	i.y = filler->direction.y;
	while (filler->direction.y == 0 ? i.y < filler->map.size.height : i.y >= 0)
	{
		i.x = filler->direction.x;
		while (filler->direction.x == 0 ? i.x < filler->map.size.width
				: i.x >= 0)
		{
			if (filler->map.data[i.y][i.x] == filler->me.c &&
				place_piece(filler, i, &tmp_coords))
				return (tmp_coords);
			i.x += (filler->direction.x == 0) ? 1 : -1;
		}
		i.y += (filler->direction.y == 0) ? 1 : -1;
	}
	return (i);
}

int			try_place(t_filler *filler, t_point coords)
{
	t_point		i;
	int			overlay;

	if (filler->piece.size.height + coords.y > filler->map.size.height
	|| filler->piece.size.width + coords.x > filler->map.size.width)
		return (0);
	overlay = 0;
	i.y = 0;
	while (!(i.x = 0) && i.y < filler->piece.size.height)
	{
		while (i.x < filler->piece.size.width)
		{
			if (filler->piece.data[i.y][i.x] == '*')
			{
				if ((CHK_PLR(filler->map.data, coords, i, filler->me.c) &&
					++overlay > 1) ||
					(CHK_PLR(filler->map.data, coords, i, filler->enemy.c) ||
					CHK_PLR(filler->map.data, coords, i, filler->enemy.c + 32)))
					return (0);
			}
			i.x++;
		}
		i.y++;
	}
	return (overlay == 1 ? 1 : 0);
}

int			place_piece(t_filler *filler, t_point me, t_point *tmp_coords)
{
	t_point i;

	i.y = 0;
	while (i.y < filler->piece.size.height)
	{
		i.x = 0;
		while (i.x < filler->piece.size.width)
		{
			tmp_coords->y = me.y - i.y;
			tmp_coords->x = me.x - i.x;
			if (filler->piece.data[i.y][i.x] == '*' &&
				valid_coords(filler, *tmp_coords) &&
				try_place(filler, *tmp_coords))
			{
				return (1);
			}
			i.x++;
		}
		i.y++;
	}
	return (0);
}

t_point		find_coords(t_filler *filler)
{
	t_point	tmp_coords;
	t_point	coords;
	t_point	i;
	int		tmp_dist;

	filler->distance = get_distance(filler->me.pos, filler->enemy.pos);
	tmp_dist = filler->distance;
	i.y = 0;
	while (!(i.x = 0) && i.y < filler->me_count)
	{
		while (i.x < filler->enemy_count)
		{
			if ((get_distance(filler->me_arr[i.y], filler->enemy_arr[i.x])
				<= filler->distance) &&
				place_piece(filler, filler->me_arr[i.y], &tmp_coords))
			{
				coords = tmp_coords;
				filler->distance = get_distance(filler->me_arr[i.y],
						filler->enemy_arr[i.x]);
			}
			i.x++;
		}
		i.y++;
	}
	return (filler->distance == tmp_dist ? find_place(filler) : coords);
}

void		filler_algo(t_filler *filler)
{
	t_point	coords;

	coords.x = 0;
	coords.y = 0;
	if (filler->map.size.height <= 20)
		small_map(filler, &coords);
	else
		big_map(filler, &coords);
	if (!valid_coords(filler, coords))
	{
		coords.x = 0;
		coords.y = 0;
	}
	ft_printf("%d %d\n", coords.y, coords.x);
}
