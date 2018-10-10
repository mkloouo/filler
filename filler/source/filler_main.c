/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 01:12:08 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/11 01:32:22 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void			filler_init(t_filler *filler)
{
	filler->piece.data = 0;
	filler->map.data = 0;
}

void			filler_run(t_filler *filler)
{
	char		*line;

	if (!filler_parse_players(filler))
		return ;
	while (ft_get_string(IO_STDIN, &line, LINE_BREAK) > 0)
	{
		if (filler_parse(filler, line))
			filler_act(filler);
		free(line);
	}
}

void			filler_free_field_rows(t_field *field, size_t move)
{
	int			i;

	i = 0;
	while (i < field->size.y)
		free(field->data[i++] - move);
}

void			filler_act(t_filler *filler)
{
	filler_algo(filler);
	ft_printf("%d %d\n", filler->step.y, filler->step.x);
}

void			filler_end(t_filler *filler)
{
	if (filler->piece.data)
	{
		filler_free_field_rows(&filler->piece, 0);
		free(filler->piece.data);
	}
	if (filler->map.data)
	{
		filler_free_field_rows(&filler->map, MAP_FIELD_START);
		free(filler->map.data);
	}
}
