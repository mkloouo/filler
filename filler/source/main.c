/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 01:35:09 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/07 17:04:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io.h>
#include <ft/memory.h>

#include <filler.h>

void		store_parsed_input(t_data *data)
{
	int		data_fd;

	data_fd = ft_open_file("data.txt", FILE_WRITE);
	if (data_fd == -1)
	{
		ft_dprintf(IO_STDERR, "Could not open file: %s\n", "data.txt");
		return ;
	}
	ft_dprintf(data_fd, "me: %c at (%zu, %zu)\nenemy: %c at (%zu, %zu)\n",
			data->me.type, data->me.pos.x, data->me.pos.y,
			data->enemy.type, data->enemy.pos.x, data->enemy.pos.y);
	ft_dprintf(data_fd, "map: %zu x %zu\n",
			data->map.size.x, data->map.size.y);
	ft_dprintf(data_fd, "piece: %zu x %zu\n",
			data->piece.size.x, data->piece.size.y);
	ft_close_file(data_fd);
}

void		init_data(t_data *data)
{
	data->me.type = FIRST_PLAYER;
	data->me.pos.x = 0;
	data->me.pos.y = 0;
	data->enemy.type = FIRST_PLAYER;
	data->enemy.pos.x = 0;
	data->enemy.pos.y = 0;
	data->map.size.x = 0;
	data->map.size.y = 0;
	data->map.data = 0;
	data->piece.size.y = 0;
	data->piece.size.x = 0;
	data->piece.data = 0;
}

int			main(int ac, char **av)
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
	store_parsed_input(&data);
	return (0);
}
