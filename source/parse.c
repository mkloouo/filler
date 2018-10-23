/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:47:09 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/23 21:16:03 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <ft/conv.h>
#include <ft/memory.h>
#include <ft/io.h>
#include <ft/string.h>

void		parse_field(t_field *field, int offset, char const *pos_data)
{
	t_size	nsize;
	char	*line;
	int		i;

	line = (char*)ft_strchr(pos_data, ' ');
	nsize.height = ft_atoi(++line);
	nsize.width = ft_atoi(ft_strchr(line, ' ') + 1);
	if (field->data)
		free_field(field, offset);
	field->data = malloc(sizeof(char*) * nsize.height);
	field->size = nsize;
	i = 0;
	while (i < nsize.height && ft_get_string(IO_STDIN, &line, LINE_BREAK) > 0)
	{
		field->data[i] = line + offset;
		++i;
	}
}
