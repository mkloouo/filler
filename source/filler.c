/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:02:08 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/23 21:38:06 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <ft/io.h>
#include <ft/conv.h>
#include <ft/memory.h>
#include <ft/string.h>

void			free_field(t_field *field, int inset)
{
	int			i;

	if (field->data)
	{
		i = 0;
		while (i < field->size.height)
			free(field->data[i++] - inset);
		free(field->data);
	}
}

int				main(void)
{
	t_filler	filler;
	char		*line;

	line = 0;
	filler.map.data = 0;
	filler.piece.data = 0;
	ft_get_string(IO_STDIN, &line, LINE_BREAK);
	filler.me.c = (ft_atoi(ft_strchr(line, 'p') + 1) == 1 ? 'O' : 'X');
	filler.enemy.c = (filler.me.c == 'O' ? 'X' : 'O');
	free(line);
	while (ft_get_string(IO_STDIN, &line, LINE_BREAK) > 0)
	{
		if (ft_strnequ("Plateau", line, 7))
			parse_field(&filler.map, 4, line);
		else if (ft_strnequ("Piece", line, 5))
		{
			parse_field(&filler.piece, 0, line);
			place_piece(&filler);
			ft_printf("%d %d\n", filler.step.y, filler.step.x);
		}
		free(line);
	}
	free_field(&filler.map, 4);
	free_field(&filler.piece, 0);
	return (0);
}
