/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 01:14:13 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/22 20:23:00 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <ft/char.h>

void			expand_square(t_point *pos, t_rectangle *rect)
{
	if (rect->left_top.y == -1)
	{
		rect->left_top = *pos;
		rect->right_bottom = *pos;
	}
	if (pos->x < rect->left_top.x)
		rect->left_top.x = pos->x;
	if (pos->x > rect->right_bottom.x)
		rect->right_bottom.x = pos->x;
	if (pos->y > rect->right_bottom.y)
		rect->right_bottom.y = pos->y;
}

t_bool			find_player_rect(t_field *map, char player, t_rectangle *rect)
{
	t_point		pnt;
	t_bool		found;

	found = FALSE;
	pnt.y = 0;
	*rect = (t_rectangle){.left_top.y = -1};
	while ((pnt.x = 0) == 0 && pnt.y < map->size.y)
	{
		while (pnt.x < map->size.x)
		{
			if (ft_tolower(map->data[pnt.y][pnt.x]) == player)
			{
				expand_square(&pnt, rect);
				found = TRUE;
			}
			++pnt.x;
		}
		++pnt.y;
	}
	return (found);
}

void            place_piece(t_filler *filler, t_rectangle *me, t_rectangle *enemy)
{
	(void)filler;
	(void)me;
	(void)enemy;
}

void			filler_algo(t_filler *filler)
{
    t_rectangle	my_rect;
    t_rectangle	enemy_rect;

    filler->step = (t_point) {0, 0};
    if (!find_player_rect(&filler->map, filler->me, &my_rect) ||
        !find_player_rect(&filler->map, filler->enemy, &enemy_rect))
        return ;
    place_piece(filler, &my_rect, &enemy_rect);
}
