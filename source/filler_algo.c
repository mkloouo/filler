/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 01:14:13 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/23 19:17:59 by modnosum         ###   ########.fr       */
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

t_bool			try_place(t_filler *filler, t_rectangle *piece, int x, int y)
{
	(void)filler;
	(void)piece;
	(void)x;
	(void)y;
	return (FALSE);
}

t_bool			place_piece(t_filler *filler, t_rectangle *piece)
{
	t_point		rp_size;
	int			i;
	int			j;

	rp_size = (t_point){piece->right_bottom.x - piece->left_top.x,
		piece->right_bottom.y - piece->left_top.y};
	i = filler->me.pos.left_top.y;
	while (i < filler->me.pos.right_bottom.y)
	{
		j = filler->me.pos.left_top.y;
		while (j < filler->me.pos.right_bottom.y)
		{
			if ((i - (rp_size.y - 1) < 0 || j - (rp_size.x - 1) < 0 ||
				i + (rp_size.y - 1) >= filler->map.size.y ||
				j + (rp_size.x - 1) >= filler->map.size.x) && ++j)
				continue ;
			if (try_place(filler, piece, j, i))
			{
				filler->step = (t_point){j - filler->piece.size.y - 1,
					i - filler->piece.size.y - 1};
				return (TRUE);
			}
			++j;
		}
		++i;
	}
	return (FALSE);
}

void			filler_algo(t_filler *filler)
{
	t_rectangle piece;

	if (!find_player_rect(&filler->map, filler->me.c, &filler->me.pos) ||
		!find_player_rect(&filler->map, filler->enemy.c, &filler->enemy.pos) ||
		!find_player_rect(&filler->piece, '*', &piece) ||
		!place_piece(filler, &piece))
		filler->step = (t_point){0, 0};
}
