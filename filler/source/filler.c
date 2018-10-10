/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:18:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/10 17:08:04 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void			parse_point_size(char *input, t_upoint *point)
{
	char const	*first_digit;

	first_digit = ft_strchr(input, ' ') + 1;
	point->y = (size_t)ft_atoi(first_digit);
	point->x = (size_t)ft_atoi(ft_strchr(first_digit + 1, ' ') + 1);
}

void			skip_parse(size_t times)
{
	char		*line;
	size_t		i;

	i = 0;
	while (i < times)
	{
		ft_get_string(IO_STDIN, &line, 0);
		free(line);
		++i;
	}
}

void			parse_input(char *input, t_data *data)
{
	if (!ft_strncmp(input, "$$$ exec p", 10))
	{
		data->me.type = (ft_atoi(ft_strchr(input, 'p') + 1) == 1)
				? FIRST_PLAYER
				: SECOND_PLAYER;
		data->enemy.type = data->me.type == FIRST_PLAYER
				? SECOND_PLAYER
				: FIRST_PLAYER;
	}
	else if (!ft_strncmp(input, "Plateau", 7))
	{
		parse_point_size(input, &data->map.size);
		skip_parse(data->map.size.y + 1);
	}
	else if (ft_strncmp(input, "Piece", 5) == 0)
	{
		parse_point_size(input, &data->piece.size);
		skip_parse(data->piece.size.y);
		ft_putstr("0 0\n");
	}
}
