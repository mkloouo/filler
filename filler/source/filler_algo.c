/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 01:14:13 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/11 21:04:52 by modnosum         ###   ########.fr       */
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

void			filler_algo(t_filler *filler)
{
	t_rectangle	rect;

	if (!find_player_rect(&filler->map, filler->me, &rect))
	{
		filler->step = (t_point) {0, 0};
		return ;
	}
	// TODO: Implement algo to set piece to a cool position;
}
