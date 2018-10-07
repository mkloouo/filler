/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
o/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 01:35:09 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/07 18:22:29 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		init_data(t_data *data)
{
	data->me.type = FIRST_PLAYER;
	data->me.pos.x = 0;
	data->me.pos.y = 0;
	data->enemy.type = FIRST_PLAYER;
	data->enemy.pos.x = 0;
	data->enemy.pos.y = 0;
}

int			main(void)
{
	t_data	data;
	char	*line;

	init_data(&data);
	line = 0;
	while (ft_get_string(IO_STDIN, &line, 0) > 0)
	{
		parse_input(line, &data);
		free(line);
	}
	return (0);
}
