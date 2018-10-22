/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 01:10:41 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/11 18:47:19 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_bool			filler_parse(t_filler *filler, char *line)
{
	char		*skip;

	if (!ft_strncmp(line, MAP_LINE, MAP_LINE_LEN))
	{
		skip = 0;
		ft_get_string(IO_STDIN, &skip, LINE_BREAK);
		free(skip);
		filler_read_field(&filler->map, line, MAP_FIELD_START);
	}
	else if (!ft_strncmp(line, PIECE_LINE, PIECE_LINE_LEN))
	{
		filler_read_field(&filler->piece, line, 0);
		return (TRUE);
	}
	return (FALSE);
}

t_bool			filler_parse_players(t_filler *filler)
{
	t_bool		ret;
	int			tmp;
	char		*line;

	ret = FALSE;
	if (ft_get_string(IO_STDIN, &line, 0) > 0)
	{
		if (!ft_strncmp(line, PLAYER_LINE, PLAYER_LINE_LEN))
		{
			tmp = ft_strtoi(ft_strchr(line, PLAYER_CHAR) + 1);
			filler->me = (char)((tmp == 1) ? 'o' : 'x');
			filler->enemy = (char)((tmp == 1) ? 'x' : 'o');
			ret = TRUE;
		}
		free(line);
	}
	return (ret);
}

void			filler_read_field(t_field *field, char const *header,
		size_t move)
{
	int			i;
	char const	*tmp;
	char		*line;

	if (field->data)
		filler_free_field(field, move);
	tmp = ft_strchr(header, ' ') + 1;
	field->size.y = ft_strtoi(tmp);
	field->size.x = ft_strtoi(ft_strchr(tmp, ' ') + 1);
	field->data = malloc(sizeof(char*) * field->size.y);
	i = 0;
	while (i < field->size.y && ft_get_string(IO_STDIN, &line, LINE_BREAK) > 0)
		field->data[i++] = line + move;
}
