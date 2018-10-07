/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:18:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/07 17:17:14 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <ft/string.h>
#include <ft/conv.h>
#include <ft/io.h>
#include <ft/memory.h>

void			parse_point_size(char *input, t_upoint *point)
{
	char const	*occ;

	occ = ft_strchr(input, ' ');
	point->y = (size_t)ft_strtoi(occ + 1);
	occ = ft_strchr(occ + 1, ' ');
	point->x = (size_t)ft_strtoi(occ + 1);
}

void			skip_parse(size_t times)
{
	char		*line;
	size_t		i;

	i = 0;
	while (i < times)
	{
		ft_get_string(IO_STDIN, &line, 0);
		ft_dprintf(line_fd, "%s\n", line);
		free(line);
		++i;
	}
}

void			parse_input(char *input, t_data *data)
{
	char const	*occ;

	if (ft_strstarts(input, "$$$ exec p"))
	{
		occ = ft_strchr(input, 'p');
		data->me.type = (ft_strtoi(occ + 1) == 1)
				? FIRST_PLAYER : SECOND_PLAYER;
		data->enemy.type = (data->me.type == FIRST_PLAYER)
				? SECOND_PLAYER : FIRST_PLAYER;
	}
	else if (ft_strstarts(input, "Plateau"))
	{
		parse_point_size(input, &data->map.size);
		skip_parse(data->map.size.y + 1);
	}
	else if (ft_strstarts(input, "Piece"))
	{
		parse_point_size(input, &data->piece.size);
		skip_parse(data->piece.size.y);
		ft_printf("%d %d\n", 0, 0);
	}
}
