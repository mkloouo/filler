/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:46:57 by modnosum          #+#    #+#             */
/*   Updated: 2019/01/05 13:32:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <ft/memory.h>
#include <ft/io.h>
#include <ft/string.h>
#include <ft/conv.h>

void			free_field(t_field *field, int inset)
{
	int		i;
	char	*del_str;

	if (!field->data)
		return ;
	i = 0;
	while (i < field->size.height)
	{
		del_str = field->data[i] - inset;
		free(del_str);
		i++;
	}
	free(field->data);
}

void			parse_field(t_field *field, int offset, char *data)
{
	char	*cur;
	int		i;

	free_field(field, offset);
	cur = (char*)ft_strchr(data, ' ');
	data = cur + 1;
	field->size.height = ft_atoi(data);
	field->size.width = ft_atoi(ft_strchr(cur + 1, ' ') + 1);
	if (offset == 4)
	{
		ft_get_string(IO_STDIN, &data, LINE_BREAK);
		free(data);
	}
	field->data = malloc(field->size.height * sizeof(char*));
	i = 0;
	while (i < field->size.height)
	{
		ft_get_string(IO_STDIN, &data, LINE_BREAK);
		field->data[i] = data + offset;
		i++;
	}
}
